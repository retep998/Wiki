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
namespace sys = std::tr2::sys;

struct color {
    uint8_t r, g, b, a;
    bool operator==(color const & c) {
        return r == c.r && g == c.g && b == c.b &&  a == c.a;
    }
};
struct image {
    void resize(size_t w, size_t h) {
        pixels.resize(w * h * 4);
        width = w;
        height = h;
    }
    void swap(image & o) {
        pixels.swap(o.pixels);
        std::swap(width, o.width);
        std::swap(height, o.height);
    }
    void adjust32() {
        auto xm = width / 64., ym = height / 64.;
        image temp;
        temp.resize(32, 32);
        for (auto y = 0u; y < 32; ++y) {
            for (auto x = 0u; x < 32; ++x) {
                auto c1 = get(static_cast<uint32_t>((x * 2 + 0) * xm), static_cast<uint32_t>((y * 2 + 0) * ym));
                auto c2 = get(static_cast<uint32_t>((x * 2 + 0) * xm), static_cast<uint32_t>((y * 2 + 1) * ym));
                auto c3 = get(static_cast<uint32_t>((x * 2 + 1) * xm), static_cast<uint32_t>((y * 2 + 1) * ym));
                auto c4 = get(static_cast<uint32_t>((x * 2 + 1) * xm), static_cast<uint32_t>((y * 2 + 0) * ym));
                auto sum = c1.a + c2.a + c3.a + c4.a;
                if (sum) {
                    temp.set(x, y, {
                        static_cast<uint8_t>((c1.r * c1.a + c2.r * c2.a + c3.r * c3.a + c4.r * c4.a) / sum),
                        static_cast<uint8_t>((c1.g * c1.a + c2.g * c2.a + c3.g * c3.a + c4.g * c4.a) / sum),
                        static_cast<uint8_t>((c1.b * c1.a + c2.b * c2.a + c3.b * c3.a + c4.b * c4.a) / sum),
                        static_cast<uint8_t>((c1.a + c2.a + c3.a + c4.a) / 4)
                    });
                } else {
                    temp.set(x, y, {0, 0, 0, 0});
                }
            }
        }
        swap(temp);
    }
    bool load(sys::path p) {
        pixels.clear();
        unsigned w, h;
        auto error = lodepng::decode(pixels, w, h, p.string());
        width = w;
        height = h;
        if (error) {
            std::cout << p << std::endl;
            std::cout << lodepng_error_text(error) << std::endl;
            return false;
        }
        return true;
    }
    bool save(sys::path p) {
        auto error = lodepng::encode(p.string(), pixels, width, height);
        if (error) {
            std::cout << lodepng_error_text(error) << std::endl;
            return false;
        }
        return true;
    }
    color get(size_t x, size_t y) {
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
    size_t width = 0, height = 0;
    std::vector<uint8_t> pixels;
};
void shrink_image(image & in, sys::path p) {
    image out;
    auto w = in.width / 2, h = in.height / 2;
    out.resize(w, h);
    for (auto y = 0u; y < h; ++y) {
        for (auto x = 0u; x < w; ++x) {
            auto c1 = in.get(x * 2 + 0, y * 2 + 0);
            auto c2 = in.get(x * 2 + 1, y * 2 + 0);
            auto c3 = in.get(x * 2 + 1, y * 2 + 1);
            auto c4 = in.get(x * 2 + 0, y * 2 + 1);
            auto sum = c1.a + c2.a + c3.a + c4.a;
            if (sum) {
                out.set(x, y, {
                    static_cast<uint8_t>((c1.r * c1.a + c2.r * c2.a + c3.r * c3.a + c4.r * c4.a) / sum),
                    static_cast<uint8_t>((c1.g * c1.a + c2.g * c2.a + c3.g * c3.a + c4.g * c4.a) / sum),
                    static_cast<uint8_t>((c1.b * c1.a + c2.b * c2.a + c3.b * c3.a + c4.b * c4.a) / sum),
                    static_cast<uint8_t>((c1.a + c2.a + c3.a + c4.a) / 4)
                });
            } else {
                out.set(x, y, {0, 0, 0, 0});
            }
        }
    }
    out.save(p);
}
void generate_tilesheet(std::string mod) {
    std::deque<sys::path> tiles;
    sys::path p = R"(A:\Files\Wiki)";
    sys::path pg = p / sys::path("Grid") / sys::path(mod);
    sys::path pf = p / sys::path("Tilesheets");

    for (sys::directory_iterator it = pg; it != sys::directory_iterator(); ++it) {
        if (sys::is_regular_file(it->path()) && it->path().extension() == ".png") tiles.push_back(it->path());
    }
    image out, in;
    out.resize(16 * 32, tiles.size() / 16 * 32 + (tiles.size() & 0xf ? 32 : 0));
    std::ofstream tile_file(pf / sys::path("Tilesheet " + mod + ".txt"));
    for (uint32_t y = 0; !tiles.empty(); ++y) for (uint32_t x = 0; x < 16 && !tiles.empty(); ++x) {
        uint32_t xi = x * 32, yi = y * 32;
        sys::path pt = tiles.front();
        tiles.pop_front();
        in.load(pt);
        for (uint32_t xx = 0; xx < 32; ++xx) for (uint32_t yy = 0; yy < 32; ++yy) {
            out.set(xi + xx, yi + yy, in.get(xx, yy));
        }
        tile_file << x << ' ' << y << ' ' << pt.replace_extension("").filename() << std::endl;
    }
    out.save(pf / sys::path("Tilesheet " + mod + " 32.png"));
    shrink_image(out, pf / sys::path("Tilesheet " + mod + " 16.png"));
}
void generate_updated(std::vector<sys::path> needs) {
    sys::path p = R"(A:\Files\Wiki)";
    for (auto & it : needs) {
        generate_tilesheet(it.leaf());
    }
}
std::vector<sys::path> fetch_latest() {
    sys::path p = R"(A:\Files\Wiki)";
    image img;
    std::vector<sys::path> needs;
    std::vector<std::string> suffixes = {"(AE)", "(BC)", "(ES)", "(ExtraBiomes XL)", "(FZ)", "(Forestry)", "(F)", "(GraviSuite)", "(GC)", "(IC2)", "(MFR)", "(PG)", "(RC)", "(RP2)", "(Steve's Carts)", "(TC3)", "(TE)", "(TC)", "(WR)", "(XyCraft)"};
    for (sys::directory_iterator it = p / sys::path("Fresh"); it != sys::directory_iterator(); ++it) {
        sys::path mod = it->path().leaf();
        needs.push_back(mod);
        sys::create_directory(p / sys::path("Grid") / mod);
        for (sys::directory_iterator it2 = it->path(); it2 != sys::directory_iterator(); ++it2) {
            if (!sys::is_regular_file(it2->path()) || it2->path().extension() != ".png") continue;
            sys::path file = it2->path();
            std::string name = file.replace_extension("").filename();
            if (name.find("Grid") == 0) name.erase(0, 4);
            for (char & c : name) if (c == '_') c = ' ';
            for (auto & suffix : suffixes) {
                auto pos = name.find(suffix);
                if (pos != std::string::npos) name.erase(pos, suffix.size());
            }
            while (name[0] == ' ') name.erase(0, 1);
            while (name[name.length() - 1] == ' ') name.erase(name.length() - 1, 1);
            img.load(it2->path());
            img.adjust32();
            img.save(p / sys::path("Grid") / mod / sys::path(name + ".png"));
        }
    }
    return needs;
}
void gregtech() {
    sys::path p = R"(A:\Files\Wiki)";
    sys::path pitems = p / sys::path(R"(GregTech\assets\gregtech_addon\textures\items)");
    sys::path pextraitems = p / sys::path(R"(GregTech\assets\minecraft\textures\items)");
    sys::path pcrops = p / sys::path(R"(GregTech\assets\ic2\textures\blocks\crop)");
    sys::path plang = p / sys::path(R"(GregTech\GregTech.lang)");
    sys::path pgrids = p / sys::path(R"(Fresh\GregTech)");
    sys::path pblocks = p / sys::path(R"(GregTech\Blocks.png)");
    sys::path pblocknames = p / sys::path(R"(GregTech\Blocks.txt)");
    sys::path ptemp = p / sys::path(R"(GregTech\Template.png)");
    sys::create_directory(pgrids);
    for (sys::directory_iterator it = pextraitems; it != sys::directory_iterator(); ++it) {
        rename(it->path(), pitems / sys::path(it->path().filename().insert(0, "item.")));
    }
    std::ifstream lang_file(plang);
    std::string prefix = "    S:";
    std::string isitem = "item.";
    std::string isname = ".name=";
    std::string str;
    while (!lang_file.eof()) {
        getline(lang_file, str);
        if (str.find(prefix) != 0) continue;
        if (str.find(isitem) != prefix.length()) continue;
        size_t namepos = str.find(isname);
        if (namepos == std::string::npos) continue;
        std::string first = str.substr(prefix.length(), namepos - prefix.length());
        std::string rest = str.substr(namepos + isname.length());
        size_t fdot = first.find_first_of('.');
        size_t ldot = first.find_last_of('.');
        if (fdot != ldot) first.replace(ldot, 1, 1, '/');
        first.append(".png");
        rest.append(".png");
        if (sys::exists(pitems / sys::path(first))) {
            sys::copy_file(pitems / sys::path(first), pgrids / sys::path(rest), sys::copy_option::overwrite_if_exists);
        }
    }
    image in, temp, out;
    in.load(pblocks);
    temp.load(ptemp);
    std::ifstream block_file(pblocknames);
    out.resize(64, 64);
    for (uint32_t yi = 4; yi < in.height; yi += 72) for (uint32_t xi = 4; xi < in.width; xi += 72) {
        getline(block_file, str);
        for (uint32_t y = 0; y < 64; ++y) for (uint32_t x = 0; x < 64; ++x) {
            if (temp.get(x, y) == color{0, 0, 0, 255}) {
                out.set(x, y, {0, 0, 0, 0});
            } else {
                out.set(x, y, in.get(x + xi, y + yi));
            }
        }
        out.save(pgrids / sys::path(str + ".png"));
        if (block_file.eof()) break;
    }
}
void fetch_and_generate() {
    generate_updated(fetch_latest());
}
void generate_everything() {
    sys::path p = R"(A:\Files\Wiki)";
    for (sys::directory_iterator it = p / sys::path("Grid"); it != sys::directory_iterator(); ++it) {
        if (!sys::is_directory(it->path())) continue;
        generate_tilesheet(it->path().leaf());
    }
}
void dump_thing(std::string thing) {
    sys::path pin = R"(A:\Files\Wiki\Tilesheets\Tilesheet GT.txt)";
    sys::path pout = R"(A:\Files\Wiki\GT dump.txt)";
    std::ifstream in(pin);
    std::ofstream out(pout);
    std::string str;
    std::vector<std::string> things;
    while (!in.eof()) {
        in >> str >> str;
        in.get();
        std::getline(in, str);
        if (str.find(thing) != std::string::npos) {
            things.push_back(str);
        }
    }
    size_t max = 0;
    for (auto & s : things) {
        if (s.size() > max) {
            max = s.size();
        }
    }
    for (auto & s : things) {
        auto p = s.find(thing);
        out << std::left << std::setw(max) << s << "|3=" << std::left << std::setw(max - thing.size()) << s.erase(p, thing.size()) << "}}{{•}}<!--\n";
    }
}

int main() {
    auto t1 = std::chrono::high_resolution_clock::now();
    //generate_everything();
    dump_thing(" Cell");
    auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << std::endl;
    return 0;
}
