//////////////////////////////////////////////////////////////////////////////
// Copyright © 2014 Peter Atashian                                          //
//                                                                          //
// This program is free software: you can redistribute it and/or modify     //
// it under the terms of the GNU Affero General Public License as           //
// published by the Free Software Foundation, either version 3 of the       //
// License, or (at your option) any later version.                          //
//                                                                          //
// This program is distributed in the hope that it will be useful,          //
// but WITHOUT ANY WARRANTY; without even the implied warranty of           //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            //
// GNU Affero General Public License for more details.                      //
//                                                                          //
// You should have received a copy of the GNU Affero General Public License //
// along with this program.  If not, see <http://www.gnu.org/licenses/>.    //
//////////////////////////////////////////////////////////////////////////////

#pragma once
#include <array>
#include <chrono>
#include <codecvt>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <regex>
#include "lodepng.h"

namespace nl {

    using namespace std;
    namespace sys = std::tr2::sys;
    namespace chrono = std::chrono;
    namespace regex_constants = std::regex_constants;
    using chrono::duration_cast;
    using chrono::high_resolution_clock;
    using chrono::milliseconds;
    using sys::path;

    //imagei and colori are assumed to be sRGB with regular alpha
    //imagef and colorf are assumed to be linear with pre-multiplied alpha

    float clamp(float const & p_val) {
        return p_val < 0 ? 0.f : p_val > 1 ? 1.f : p_val;
    }

    double srgb_to_linear(double p_val) {
        if (p_val <= 0.04045) {
            return p_val / 12.92;
        }
        return pow((p_val + 0.055) / (1 + 0.055), 2.4);
    }
    double linear_to_srgb(double p_val) {
        if (p_val <= 0.0031308) {
            return p_val * 12.92;
        }
        return (1 + 0.055) * pow(p_val, 1 / 2.4) - 0.055;
    }
    auto const lookup_itof_table = [] {
        array<float, 0x100> buf;
        size_t i{0};
        generate(buf.begin(), buf.end(), [&]() {
            return static_cast<float>(srgb_to_linear(static_cast<double>(i++) / 0xFF));
        });
        return buf;
    }();
    auto const lookup_ftoi_table = [] {
        array<uint8_t, 0x1000> buf;
        size_t i{0};
        generate(buf.begin(), buf.end(), [&]() {
            return static_cast<uint8_t>(linear_to_srgb(static_cast<double>(i++) / 0xFFF) * 0xFF + 0.9);
        });
        return buf;
    }();
    float lookup_itof(uint8_t p_val) {
        return lookup_itof_table[p_val];
    }
    uint8_t lookup_ftoi(float p_val) {
        return lookup_ftoi_table[static_cast<int>(clamp(p_val) * 0xFFF)];
    }
    struct colorf;
    struct colori {
        colori() = default;
        colori(uint8_t p_r, uint8_t p_g, uint8_t p_b, uint8_t p_a) :
            r{p_r}, g{p_g}, b{p_b}, a{p_a} {}
        operator colorf() const;
        colori(colori const &) = default;
        bool operator==(colori const & p_other) const {
            return r == p_other.r && g == p_other.g && b == p_other.b && a == p_other.a;
        }
        uint8_t r, g, b, a;
    };
    static_assert(sizeof(colori) == 4 * sizeof(uint8_t), "This is bad");
    struct colorf {
        colorf() = default;
        colorf(float p_r, float p_g, float p_b, float p_a) :
            r{p_r}, g{p_g}, b{p_b}, a{p_a} {}
        colorf(colorf const &) = default;
        operator colori() const {
            if (a < 0.001f) {
                return{0, 0, 0, 0};
            }
            auto ai = static_cast<uint8_t>(clamp(a) * 0xFF);
            auto ar = 1 / a;
            return{lookup_ftoi(r * ar), lookup_ftoi(g * ar), lookup_ftoi(b * ar), ai};
        }
        colorf & operator=(colorf const &) = default;
        void operator*=(colorf const & p_other) {
            r *= p_other.r;
            g *= p_other.g;
            b *= p_other.b;
            a *= p_other.a;
        }
        bool operator==(colorf const & p_other) const {
            return r == p_other.r && g == p_other.g && b == p_other.b && a == p_other.a;
        }
        colorf operator*(colorf const & p_other) const {
            return{r * p_other.r, g * p_other.g, b * p_other.b, a * p_other.a};
        }
        colorf operator+(colorf const & p_other) const {
            return{r + p_other.r, g + p_other.g, b + p_other.b, a + p_other.a};
        }
        colorf operator*(float p_mult) const {
            return{r * p_mult, g * p_mult, b * p_mult, a * p_mult};
        }
        float r, g, b, a;
    };
    colori::operator colorf() const {
        auto af = a * (1.f / 0xFF);
        return{lookup_itof(r) * af, lookup_itof(g) * af, lookup_itof(b) * af, af};
    }
    vector<uint8_t> tempu8;
    struct imagef;
    struct imagei {
        void operator=(imagef const & p_img);
        void save(path p_path) const {
            tempu8.resize(pixels.size() * 4);
            memcpy(tempu8.data(), pixels.data(), pixels.size() * sizeof(colori));
            auto error = lodepng::encode(p_path, tempu8, width, height);
            if (error) {
                throw std::runtime_error{lodepng_error_text(error)};
            }
        }
        void load(path p_path) {
            tempu8.clear();
            auto error = lodepng::decode(tempu8, width, height, p_path);
            if (error) {
                throw std::runtime_error{lodepng_error_text(error)};
            }
            pixels.resize(width * height);
            memcpy(pixels.data(), tempu8.data(), pixels.size() * sizeof(colori));
        }
        unsigned width{0}, height{0};
        vector<colori> pixels;
        static imagei temp;
    };
    imagei imagei::temp;
    struct imagef {
        void operator=(imagei const & p_img) {
            width = p_img.width;
            height = p_img.height;
            pixels.resize(p_img.pixels.size());
            for (size_t i{0}, end{pixels.size()}; i != end; ++i) {
                pixels[i] = p_img.pixels[i];
            }
        }
        void operator*=(colorf const & p_color) {
            for (auto & p : pixels) {
                p *= p_color;
            }
        }
        void operator+=(imagef const & p_img) {
            if (width != p_img.width || height != p_img.height) {
                throw invalid_argument{"Image size doesn't match"};
            }
            for (size_t i{0}, end{pixels.size()}; i != end; ++i) {
                auto & src = p_img.pixels[i];
                auto & dest = pixels[i];
                dest = dest * (1 - src.a) + src;
            }
        }
        void clear(unsigned p_width, unsigned p_height) {
            width = p_width;
            height = p_height;
            pixels.clear();
            pixels.resize(p_width * p_height, {0, 0, 0, 0});
        }
        void save(path p_path) const {
            imagei::temp = *this;
            imagei::temp.save(p_path);
        }
        void load(path p_path) {
            imagei::temp.load(p_path);
            *this = imagei::temp;
        }
        unsigned width{0}, height{0};
        vector<colorf> pixels;
        static imagef temp;
    };
    imagef imagef::temp;
    void imagei::operator=(imagef const & p_img) {
        width = p_img.width;
        height = p_img.height;
        pixels.resize(p_img.pixels.size());
        for (size_t i{0}, end{pixels.size()}; i != end; ++i) {
            pixels[i] = p_img.pixels[i];
        }
    }
}
