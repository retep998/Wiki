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
#include <iostream>
#include <regex>
#include "lodepng.h"

namespace {
    using namespace std;
    namespace sys = std::tr2::sys;
    namespace chrono = std::chrono;
    namespace regex_constants = std::regex_constants;
    using chrono::duration_cast;
    using chrono::high_resolution_clock;
    using chrono::milliseconds;
    using sys::path;

    template <typename T>
    struct iter {
        using difference_type = ptrdiff_t;
        using value_type = T;
        using pointer = T;
        using reference = T &;
        using iterator_category = forward_iterator_tag;
        iter(T const & p_value) :
            m_value{p_value} {}
        void operator++() {
            ++m_value;
        }
        T & operator*() {
            return m_value;
        }
        bool operator!=(iter const & p_other) {
            return m_value != p_other.m_value;
        }
        bool operator==(iter const & p_other) {
            return m_value == p_other.m_value;
        }
        T m_value;
    };
    template <typename T>
    struct range {
        range(T const & p_begin, T const & p_end) :
            m_begin{p_begin}, m_end{p_end} {}
        T & begin() {
            return m_begin;
        }
        T & end() {
            return m_end;
        }
        T m_begin, m_end;
    };

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
        transform(iter<size_t>{0}, iter<size_t>{buf.size()}, buf.begin(), [](size_t n) {
            return static_cast<float>(srgb_to_linear(static_cast<double>(n) / 0xFF));
        });
        return buf;
    }();
    auto const lookup_ftoi_table = [] {
        array<uint8_t, 0x1000> buf;
        transform(iter<size_t>{0}, iter<size_t>{buf.size()}, buf.begin(), [](size_t n) {
            return static_cast<uint8_t>(linear_to_srgb(static_cast<double>(n) / 0xFFF) * 255);
        });
        return buf;
    }();
    float lookup_itof(uint8_t p_val) {
        return lookup_itof_table[p_val];
    }
    uint8_t lookup_ftoi(float p_val) {
        return lookup_ftoi_table[static_cast<int>(max(min(p_val, 1.f), 0.f) * 0xFFF)];
    }
    struct colori {
        colori() = default;
        colori(uint8_t p_r, uint8_t p_g, uint8_t p_b, uint8_t p_a) :
            r{p_r}, g{p_g}, b{p_b}, a{p_a} {}
        colori(colori const &) = default;
        bool operator==(colori const & p_other) const {
            return r == p_other.r && g == p_other.g && b == p_other.b && a == p_other.a;
        }
        uint8_t r, g, b, a;
    };
    struct colorf {
        colorf() = default;
        colorf(float p_r, float p_g, float p_b, float p_a) :
            r{p_r}, g{p_g}, b{p_b}, a{p_a} {}
        colorf(colorf const &) = default;
        colorf(colori const &) {

        }
        colorf & operator=(colorf const &) = default;
        bool operator==(colorf const & p_other) const {
            return r == p_other.r && g == p_other.g && b == p_other.b && a == p_other.a;
        }
        colorf operator*(colorf const & p_other) const {
            return{r * p_other.r, g * p_other.g, b * p_other.b, a * p_other.a};
        }
        float r, g, b, a;
    };
    struct imagei {
        size_t width{0}, height{0};
        vector<colori> pixels;
    };
    vector<uint8_t> temp_u8;
    imagei temp_imagi;
}
