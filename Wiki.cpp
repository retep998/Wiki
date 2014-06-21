#include "lodepng.h"
#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <chrono>
#include <thread>
#include <array>
#include <algorithm>
#include <numeric>
#include <deque>
#include <iomanip>
#include <regex>

namespace {
using namespace std;
namespace sys = std::tr2::sys;
using sys::path;

struct color {
    color() = default;
    color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255) : r(r), g(g), b(b), a(a) {}
    color(color const &) = default;
    color &operator=(color const &) = default;
    union {
        struct {
            uint8_t r, g, b, a;
        };
        uint32_t rgba;
    };
    bool operator==(color const &c) { return rgba == c.rgba; }
};

struct image {
    image() = default;
    image(image const &) = default;
    image(image &&o) : pixels(std::move(o.pixels)), width(o.width), height(o.height) {}
    image(path p) { load(p); }
    image &operator=(image const &) = default;
    image &operator=(image &&o) {
        pixels = std::move(o.pixels);
        width = o.width;
        height = o.height;
        return *this;
    }
    void resize(size_t w, size_t h) {
        pixels.resize(w * h * 4);
        width = w;
        height = h;
    }
    void swap(image &o) {
        pixels.swap(o.pixels);
        std::swap(width, o.width);
        std::swap(height, o.height);
    }
    void adjust32() {
        auto xm = width / 64., ym = height / 64.;
        temp.resize(32, 32);
        for (auto y = 0u; y < 32; ++y) {
            for (auto x = 0u; x < 32; ++x) {
                auto c1 = get(static_cast<size_t>((x * 2 + 0) * xm),
                              static_cast<size_t>((y * 2 + 0) * ym));
                auto c2 = get(static_cast<size_t>((x * 2 + 0) * xm),
                              static_cast<size_t>((y * 2 + 1) * ym));
                auto c3 = get(static_cast<size_t>((x * 2 + 1) * xm),
                              static_cast<size_t>((y * 2 + 1) * ym));
                auto c4 = get(static_cast<size_t>((x * 2 + 1) * xm),
                              static_cast<size_t>((y * 2 + 0) * ym));
                auto sum = c1.a + c2.a + c3.a + c4.a;
                if (sum) {
                    temp.set(x, y, {static_cast<uint8_t>((c1.r * c1.a + c2.r * c2.a + c3.r * c3.a
                                                          + c4.r * c4.a) / sum),
                                    static_cast<uint8_t>((c1.g * c1.a + c2.g * c2.a + c3.g * c3.a
                                                          + c4.g * c4.a) / sum),
                                    static_cast<uint8_t>((c1.b * c1.a + c2.b * c2.a + c3.b * c3.a
                                                          + c4.b * c4.a) / sum),
                                    static_cast<uint8_t>((c1.a + c2.a + c3.a + c4.a) / 4)});
                } else { temp.set(x, y, {0, 0, 0, 0}); }
            }
        }
        swap(temp);
    }
    void half_size() {
        auto w = width / 2, h = height / 2;
        temp.resize(w, h);
        for (auto y = 0u; y < h; ++y) {
            for (auto x = 0u; x < w; ++x) {
                auto c1 = get(x * 2 + 0, y * 2 + 0);
                auto c2 = get(x * 2 + 1, y * 2 + 0);
                auto c3 = get(x * 2 + 1, y * 2 + 1);
                auto c4 = get(x * 2 + 0, y * 2 + 1);
                auto sum = c1.a + c2.a + c3.a + c4.a;
                if (sum) {
                    temp.set(x, y, {static_cast<uint8_t>((c1.r * c1.a + c2.r * c2.a + c3.r * c3.a
                                                          + c4.r * c4.a) / sum),
                                    static_cast<uint8_t>((c1.g * c1.a + c2.g * c2.a + c3.g * c3.a
                                                          + c4.g * c4.a) / sum),
                                    static_cast<uint8_t>((c1.b * c1.a + c2.b * c2.a + c3.b * c3.a
                                                          + c4.b * c4.a) / sum),
                                    static_cast<uint8_t>((c1.a + c2.a + c3.a + c4.a) / 4)});
                } else { temp.set(x, y, {0, 0, 0, 0}); }
            }
        }
        swap(temp);
    }
    void insert(image &o, size_t x, size_t y) {
        if (x + o.width > width || y + o.height > height) throw runtime_error{"Oh noez"};
        for (auto yi = 0; yi < o.height; ++yi)
            for (auto xi = 0; xi < o.width; ++xi) set(x + xi, y + yi, o.get(xi, yi));
    }
    bool load(path p) {
        pixels.clear();
        unsigned w, h;
        auto error = lodepng::decode(pixels, w, h, p.string());
        if (error) {
            width = 0;
            height = 0;
            std::cout << p << std::endl;
            std::cout << lodepng_error_text(error) << std::endl;
            return false;
        }
        width = w;
        height = h;
        return true;
    }
    bool save(path p) const {
        auto error = lodepng::encode(p.string(), pixels, static_cast<unsigned>(width),
                                     static_cast<unsigned>(height));
        if (error) {
            std::cout << lodepng_error_text(error) << std::endl;
            return false;
        }
        return true;
    }
    color get(size_t x, size_t y) const {
        auto i = (y * width + x) * 4;
        return {pixels[i + 0], pixels[i + 1], pixels[i + 2], pixels[i + 3]};
    }
    void set(size_t x, size_t y, color c) {
        auto i = (y * width + x) * 4;
        pixels[i + 0] = c.r;
        pixels[i + 1] = c.g;
        pixels[i + 2] = c.b;
        pixels[i + 3] = c.a;
    }
    void fill(color p_color) {
        for (auto it = pixels.begin(), end = pixels.end(); it != end; it += 4) {
            it[0] = p_color.r;
            it[1] = p_color.g;
            it[2] = p_color.b;
            it[3] = p_color.a;
        }
    }
    void outline(size_t x, size_t y, size_t w, size_t h, color c) {
        for (auto i = x; i < x + w; ++i) {
            set(i, y, c);
            set(i, y + h - 1, c);
        }
        for (auto i = y; i < y + h; ++i) {
            set(x, i, c);
            set(x + w - 1, i, c);
        }
    }
    size_t width = 0, height = 0;
    std::vector<uint8_t> pixels;
    static image temp;
};
image image::temp;

namespace emotes {
struct block {
    size_t x, y;
    size_t w, h;
};
using block_container_t = std::multimap<size_t, block>;
block_container_t hblocks{};
block_container_t wblocks{};
image atlas;
void add_block(size_t x, size_t y, size_t w, size_t h) {
    if (w <= 0 || h <= 0) { return; }
    if (w > h) { hblocks.insert({h, {x, y, w, h}}); } else {
        wblocks.insert({w, {x, y, w, h}});
    }
}
block get_block(size_t p_width, size_t p_height) {
    auto itw = std::find_if(
        wblocks.lower_bound(p_width), wblocks.end(),
        [&](block_container_t::value_type const &p) { return p_height <= p.second.h; });
    auto ith = std::find_if(
        hblocks.lower_bound(p_height), hblocks.end(),
        [&](block_container_t::value_type const &p) { return p_width <= p.second.w; });
    block b;
    if (itw != wblocks.end() && ith != hblocks.end()) {
        if (itw->first - p_width <= ith->first - p_height) {
            b = itw->second;
            wblocks.erase(itw);
        } else {
            b = ith->second;
            hblocks.erase(ith);
        }
    } else if (itw != wblocks.end()) {
        b = itw->second;
        wblocks.erase(itw);
    } else if (ith != hblocks.end()) {
        b = ith->second;
        hblocks.erase(ith);
    } else { throw std::runtime_error{"Out of space!"}; }
    if (b.w - p_width > b.h - p_height) {
        add_block(b.x + p_width, b.y, b.w - p_width, b.h);
        add_block(b.x, b.y + p_height, p_width, b.h - p_height);
    } else {
        add_block(b.x + p_width, b.y, b.w - p_width, p_height);
        add_block(b.x, b.y + p_height, b.w, b.h - p_height);
    }
    return b;
}
void generate() {
    auto const size = 512u;
    hblocks.clear();
    wblocks.clear();
    atlas.resize(size, size);
    add_block(0, 0, atlas.width, atlas.height);
    auto dir = sys::u8path(".");
    ofstream out{dir / "sheet.css"};
    vector<tuple<image, path>> todo;
    for (sys::directory_iterator it{dir / "input"}, end; it != end; ++it) {
        auto img_path = it->path();
        if (!sys::is_regular_file(img_path)) { continue; }
        image img;
        img.load(img_path);
        todo.emplace_back(move(img), img_path);
    }
    sort(todo.begin(), todo.end(),
         [](tuple<image, path> const &p_one, tuple<image, path> const &p_two) {
        return get<0>(p_one).width > get<0>(p_two).width;
    });
    auto index = 0;
    for (auto &next : todo) {
        auto &img = get<0>(next);
        auto &img_path = get<1>(next);
        auto block = get_block(img.width, img.height);
        atlas.insert(img, block.x, block.y);
        out << "a[href|=\"/" << img_path.stem()
            << "\"]{display:block;clear:none;float:left;background-image:url(%%emotes%%);width:"
            << img.width << "px;height:" << img.height << "px;background-position:-" << block.x
            << "px -" << block.y << "px;}" << endl;
    }
    atlas.save(dir / "emotes.png");
}
}
}

int main(int argc, char **argv) {
    emotes::generate();
    return EXIT_SUCCESS;
}
