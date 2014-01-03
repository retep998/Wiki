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

namespace {

    namespace sys = std::tr2::sys;
    using std::any_of;
    using std::find_if;
    using std::getline;
    using sys::is_regular_file;
    using std::make_pair;
    using std::array;
    using sys::directory_iterator;
    using std::ifstream;
    using std::map;
    using std::ofstream;
    using std::pair;
    using sys::path;
    using std::runtime_error;
    using std::size_t;
    using std::string;
    using std::vector;

    path base = R"(C:\Users\Peter\Minecraft\Wiki)";

    struct color {
        color() = default;
        color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : r(r), g(g), b(b), a(a) {}
        color(color const &) = default;
        color & operator=(color const &) = default;
        union {
            struct {
                uint8_t r, g, b, a;
            };
            uint32_t rgba;
        };
        bool operator==(color const & c) {
            return rgba == c.rgba;
        }
    };
    struct image {
        image() = default;
        image(image const &) = default;
        image(image && o) : pixels(std::move(o.pixels)), width(o.width), height(o.height) {}
        image(path p) {
            load(p);
        }
        image & operator=(image const &) = default;
        image & operator=(image && o) {
            pixels = std::move(o.pixels);
            width = o.width;
            height = o.height;
        }
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
            temp.resize(32, 32);
            for (auto y = 0u; y < 32; ++y) {
                for (auto x = 0u; x < 32; ++x) {
                    auto c1 = get(static_cast<size_t>((x * 2 + 0) * xm), static_cast<size_t>((y * 2 + 0) * ym));
                    auto c2 = get(static_cast<size_t>((x * 2 + 0) * xm), static_cast<size_t>((y * 2 + 1) * ym));
                    auto c3 = get(static_cast<size_t>((x * 2 + 1) * xm), static_cast<size_t>((y * 2 + 1) * ym));
                    auto c4 = get(static_cast<size_t>((x * 2 + 1) * xm), static_cast<size_t>((y * 2 + 0) * ym));
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
        void insert(image & o, size_t x, size_t y) {
            if (x + o.width > width || y + o.height > height)
                throw runtime_error{"Oh noez"};
            for (auto yi = 0; yi < o.height; ++yi)
                for (auto xi = 0; xi < o.width; ++xi)
                    set(x + xi, y + yi, o.get(xi, yi));
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
            auto error = lodepng::encode(p.string(), pixels, static_cast<unsigned>(width), static_cast<unsigned>(height));
            if (error) {
                std::cout << lodepng_error_text(error) << std::endl;
                return false;
            }
            return true;
        }
        color get(size_t x, size_t y) const {
            auto i = (y * width + x) * 4;
            return{pixels[i + 0], pixels[i + 1], pixels[i + 2], pixels[i + 3]};
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
        static image temp;
    };
    image image::temp;
    void shrink_image(image & in, path p) {
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
        std::deque<path> tiles;
        path p = R"(A:\Files\Wiki)";
        path pg = p / path("Grid") / path(mod);
        path pf = p / path("Tilesheets");

        for (sys::directory_iterator it = pg; it != sys::directory_iterator(); ++it) {
            if (sys::is_regular_file(it->path()) && it->path().extension() == ".png") tiles.push_back(it->path());
        }
        image out, in;
        out.resize(16 * 32, tiles.size() / 16 * 32 + (tiles.size() & 0xf ? 32 : 0));
        std::ofstream tile_file(pf / path("Tilesheet " + mod + ".txt"));
        for (uint32_t y = 0; !tiles.empty(); ++y) for (uint32_t x = 0; x < 16 && !tiles.empty(); ++x) {
            uint32_t xi = x * 32, yi = y * 32;
            path pt = tiles.front();
            tiles.pop_front();
            in.load(pt);
            for (uint32_t xx = 0; xx < 32; ++xx) for (uint32_t yy = 0; yy < 32; ++yy) {
                out.set(xi + xx, yi + yy, in.get(xx, yy));
            }
            tile_file << x << ' ' << y << ' ' << pt.replace_extension("").filename() << std::endl;
        }
        out.save(pf / path("Tilesheet " + mod + " 32.png"));
        shrink_image(out, pf / path("Tilesheet " + mod + " 16.png"));
    }
    void generate_updated(std::vector<path> needs) {
        path p = R"(A:\Files\Wiki)";
        for (auto & it : needs) {
            generate_tilesheet(it.leaf());
        }
    }
    std::vector<path> fetch_latest() {
        path p = R"(A:\Files\Wiki)";
        image img;
        std::vector<path> needs;
        std::vector<std::string> suffixes = {"(AE)", "(BC)", "(ES)", "(ExtraBiomes XL)", "(FZ)", "(Forestry)", "(F)", "(GraviSuite)", "(GC)", "(IC2)", "(MFR)", "(PG)", "(RC)", "(RP2)", "(Steve's Carts)", "(TC3)", "(TE)", "(TC)", "(WR)", "(XyCraft)"};
        for (sys::directory_iterator it = p / path("Fresh"); it != sys::directory_iterator(); ++it) {
            path mod = it->path().leaf();
            needs.push_back(mod);
            sys::create_directory(p / path("Grid") / mod);
            for (sys::directory_iterator it2 = it->path(); it2 != sys::directory_iterator(); ++it2) {
                if (!sys::is_regular_file(it2->path()) || it2->path().extension() != ".png") continue;
                path file = it2->path();
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
                img.save(p / path("Grid") / mod / path(name + ".png"));
            }
        }
        return needs;
    }
    void gregtech() {
        path p = R"(A:\Files\Wiki)";
        path pitems = p / path(R"(GregTech\assets\gregtech_addon\textures\items)");
        path pextraitems = p / path(R"(GregTech\assets\minecraft\textures\items)");
        path pcrops = p / path(R"(GregTech\assets\ic2\textures\blocks\crop)");
        path plang = p / path(R"(GregTech\GregTech.lang)");
        path pgrids = p / path(R"(Fresh\GregTech)");
        path pblocks = p / path(R"(GregTech\Blocks.png)");
        path pblocknames = p / path(R"(GregTech\Blocks.txt)");
        path ptemp = p / path(R"(GregTech\Template.png)");
        sys::create_directory(pgrids);
        for (sys::directory_iterator it = pextraitems; it != sys::directory_iterator(); ++it) {
            rename(it->path(), pitems / path(it->path().filename().insert(0, "item.")));
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
            if (sys::exists(pitems / path(first))) {
                sys::copy_file(pitems / path(first), pgrids / path(rest), sys::copy_option::overwrite_if_exists);
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
            out.save(pgrids / path(str + ".png"));
            if (block_file.eof()) break;
        }
    }
    void fetch_and_generate() {
        generate_updated(fetch_latest());
    }
    void generate_everything() {
        path p = R"(A:\Files\Wiki)";
        for (sys::directory_iterator it = p / path("Grid"); it != sys::directory_iterator(); ++it) {
            if (!sys::is_directory(it->path())) continue;
            generate_tilesheet(it->path().leaf());
        }
    }
    void dump_thing(std::string thing) {
        path pin = R"(A:\Files\Wiki\Tilesheets\Tilesheet GT.txt)";
        path pout = R"(A:\Files\Wiki\GT dump.txt)";
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

    void update_tilesheet(string mod) {
        auto ptext = base / path{"Tilesheet_" + mod + ".txt"};
        auto praw = base / path{mod};
        auto p32 = base / path{"Tilesheet_" + mod + "_32.png"};
        auto p16 = base / path{"Tilesheet_" + mod + "_16.png"};
        auto intext = ifstream{ptext};
        auto entries = vector<array<string, 16>>{};
        auto lookup = map<string, pair<size_t, size_t>>{};
        auto name = string{};
        while (intext.good()) {
            auto x = size_t{}, y = size_t{};
            intext >> x >> y;
            while (intext.peek() == ' ')
                intext.get();
            getline(intext, name);
            if (name.empty())
                continue;
            for (auto & c : name)
                if (c == ' ')
                    c = '_';
            auto it = lookup.find(name);
            if (it != lookup.end())
                continue;
            if (y >= entries.size())
                entries.resize(y + 1);
            entries[y][x] = name;
            lookup.emplace(name, make_pair(x, y));
        }
        auto img = image{p32};
        if (img.width < 32 * 16)
            img.resize(32 * 16, 32);
        auto in = image{};
        for (auto it = directory_iterator{praw}; it != directory_iterator{}; ++it) {
            auto p = it->path();
            if (!is_regular_file(p) || p.extension() != ".png")
                continue;
            in.load(p);
            in.adjust32();
            p.replace_extension();
            name = p.filename();
            for (auto & c : name)
                if (c == ' ')
                    c = '_';
            auto lit = lookup.find(name);
            auto x = size_t{}, y = size_t{};
            if (lit != lookup.end()) {
                x = lit->second.first;
                y = lit->second.second;
            } else {
                auto found = false;
                for (auto yi = size_t{}; yi < entries.size() && !found; ++yi) {
                    auto & row = entries[yi];
                    for (auto xi = size_t{}; xi < row.size() && !found; ++xi) {
                        auto & entry = row[xi];
                        if (entry.empty()) {
                            entry = name;
                            found = true;
                            x = xi;
                            y = yi;
                        }
                    }
                }
                if (!found) {
                    x = 0;
                    y = entries.size();
                    entries.emplace_back();
                    entries.back().front() = name;
                }
                lookup.emplace(name, make_pair(x, y));
            }
            if (y * 32 + 32 > img.height)
                img.resize(32 * 16, y * 32 + 32);
            img.insert(in, x * 32, y * 32);
        }
        img.save(p32);
        img.half_size();
        img.save(p16);
        auto outtext = ofstream(ptext);
        for (auto y = size_t{}; y < entries.size(); ++y) {
            auto row = entries[y];
            for (auto x = size_t{}; x < row.size(); ++x) {
                auto entry = row[x];
                if (entry.empty())
                    continue;
                outtext << x << ' ' << y << ' ' << entry << '\n';
            }
        }
    }
}

int main() {
    auto t1 = std::chrono::high_resolution_clock::now();
    //generate_everything();
    //dump_thing(" Cell");
    update_tilesheet("RC");
    auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << std::endl;
    return 0;
}
