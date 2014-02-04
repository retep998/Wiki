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

    namespace sys = std::tr2::sys;
    namespace chrono = std::chrono;
    namespace regex_constants = std::regex_constants;
    using std::any_of;
    using chrono::duration_cast;
    using std::endl;
    using std::find_if;
    using std::getline;
    using sys::is_regular_file;
    using std::make_pair;
    using std::regex_match;
    using std::array;
    using sys::directory_iterator;
    using chrono::high_resolution_clock;
    using std::ifstream;
    using std::map;
    using chrono::milliseconds;
    using std::ofstream;
    using std::pair;
    using sys::path;
    using std::regex;
    using std::runtime_error;
    using std::size_t;
    using std::smatch;
    using std::string;
    using std::vector;
    using std::cin;
    using std::cout;

    path base = R"(C:\Users\Peter\Minecraft\Wiki)";

    struct color {
        color() = default;
        color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255) : r(r), g(g), b(b), a(a) {}
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
        auto ptext = base / path{"Tilesheet " + mod + ".txt"};
        auto praw = base / path{mod};
        auto p32 = base / path{"Tilesheet " + mod + " 32.png"};
        auto p16 = base / path{"Tilesheet " + mod + " 16.png"};
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
                cout << x << ' ' << y << ' ' << name << endl;
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
    void import_tilesheet(string mod) {
        auto pin = base / path{"Raw " + mod + ".txt"};
        auto in = ifstream{pin};
        auto pout = base / path{"Tilesheet " + mod + ".txt"};
        auto out = ofstream{pout};
        auto line = string{};
        auto reg = regex{"Edit[[:space:]]+[[:digit:]]+[[:space:]]+([^[:space:]].*[^[:space:]])[[:space:]]+[[:alnum:]]+[[:space:]]+([[:digit:]]+)[[:space:]]+([[:digit:]]+)[[:space:]]+16px, 32px", regex_constants::ECMAScript | regex_constants::optimize};
        auto mat = smatch{};
        while (in.good()) {
            getline(in, line);
            if (regex_match(line, mat, reg))
                out << mat[2] << ' ' << mat[3] << ' ' << mat[1] << '\n';
        }
    }
    void ascii_old() {
        auto const chars = std::array<char, 96>{{0x20, 0x20, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2d, 0x2d, 0x5f, 0x5f, 0x5f, 0x5e, 0x5e, 0x5e, 0x5e, 0x5e, 0x5e, 0x5e, 0x5e, 0x22, 0x22, 0x22, 0x22, 0x7e, 0x7e, 0x7e, 0x7c, 0x7c, 0x28, 0x28, 0x28, 0x28, 0x3f, 0x3f, 0x3f, 0x3f, 0x21, 0x21, 0x21, 0x21, 0x31, 0x31, 0x31, 0x6f, 0x6f, 0x6e, 0x6e, 0x54, 0x54, 0x33, 0x33, 0x6a, 0x6a, 0x35, 0x35, 0x24, 0x24, 0x24, 0x53, 0x53, 0x34, 0x34, 0x50, 0x50, 0x4f, 0x4f, 0x45, 0x45, 0x55, 0x55, 0x44, 0x44, 0x44, 0x44, 0x44, 0x40, 0x40, 0x40, 0x40, 0x42, 0x42, 0x23, 0x23, 0x30, 0x30, 0x30, 0x30, 0x30}};
        auto in = image("image.png");
        auto const width = 79u;
        auto const xratio = static_cast<double>(in.width) / width;
        auto const yratio = xratio * 1.5;
        auto const height = static_cast<unsigned>(in.height / yratio);
        auto grid = std::vector<double>{};
        grid.resize(width * height);
        for (auto y = 0u; y < height; ++y) {
            auto const yt = static_cast<unsigned>(y * yratio), yb = static_cast<unsigned>(y * yratio + yratio);
            for (auto x = 0u; x < width; ++x) {
                auto const xt = static_cast<unsigned>(x * xratio), xb = static_cast<unsigned>(x * xratio + xratio);
                auto const total = (xb - xt) * (yb - yt);
                auto sum = 0.;
                for (auto yi = yt; yi < yb; ++yi) {
                    for (auto xi = xt; xi < xb; ++xi) {
                        auto const c = in.get(xi, yi);
                        auto const a = static_cast<double>(c.a);
                        sum += c.r * a;
                        sum += c.g * a;
                        sum += c.b * a;
                    }
                }
                grid[y * width + x] = sum / total;
            }
        }
        auto const small = *std::min_element(grid.cbegin(), grid.cend());
        auto const big = *std::max_element(grid.cbegin(), grid.cend());
        auto const mult = 1. / (big - small);
        auto out = std::ofstream("image.txt");
        for (auto y = 0u; y < height; ++y) {
            for (auto x = 0u; x < width; ++x) {
                auto const val = chars.size() * mult * (grid[y * width + x] - small);
                out.put(chars[std::min(static_cast<unsigned>(chars.size()) - 1u, std::max(0u, static_cast<unsigned>(val)))]);
            }
            out.put('\n');
        }
    }
    void print_ascii() {
        auto out = std::ofstream("dump.txt");
        for (unsigned char c = 0x20; c < 0x7f; ++c) {
            std::cout.put(c);
        }
        std::cout.put('\n');
        for (unsigned char c = 0x20; c < 0x7f; ++c) {
            out << std::hex << "0x" << (int)c << ", ";
        }
        out.put('\n');
    }
    void calc_ascii() {
        auto const chars = std::array<char, 95>{{0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5a, 0x5b, 0x5c, 0x5d, 0x5e, 0x5f, 0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7a, 0x7b, 0x7c, 0x7d, 0x7e}};
        auto vals = std::array<std::pair<unsigned, char>, 95>{};
        auto img = image("chars.png");
        for (auto i = 0u; i < 95u; ++i) {
            auto const off = i * 8u;
            auto sum = 0u;
            for (auto x = off; x < off + 8u; ++x) {
                for (auto y = 0u; y < 12u; ++y) {
                    auto const c = img.get(x, y);
                    sum += c.r ? 1 : 0;
                }
            }
            vals[i].first = sum;
            vals[i].second = chars[i];
        }
        std::sort(vals.begin(), vals.end(), [](std::pair<unsigned, char> const & a, std::pair<unsigned, char> const & b) {
            return a.first < b.first;
        });
        auto out = std::ofstream("dump.txt");
        auto const big = vals.back().first;
        for (auto i = 0u; i < 96u; ++i) {
            auto const num = static_cast<unsigned>(std::round(1. / 96 * i * big));
            auto const it = std::lower_bound(vals.begin(), vals.end(), num, [](std::pair<unsigned, char> const & a, unsigned const & b) {
                return a.first < b;
            });
            if (it == vals.end()) {
                throw std::runtime_error{"This is bad"};
            }
            out << std::hex << "0x" << (int)it->second << ", ";
        }
        out << std::endl;
    }
    namespace ascii {
        struct entry {
            color c;
            uint8_t code;
            uint8_t character;
        };
        struct char_entry {
            uint8_t character;
            uint8_t coverage;
        };
        std::array<char_entry, 95> const characters = {{{0x20, 0x0}, {0x2E, 0x6}, {0x60, 0x6}, {0x2D, 0x7}, {0x5F, 0x8}, {0x27, 0x8}, {0x2C, 0x8}, {0x5E, 0xC}, {0x3A, 0xC}, {0x3D, 0xC}, {0x22, 0xE}, {0x5C, 0xE}, {0x2B, 0xE}, {0x2F, 0xE}, {0x7E, 0xF}, {0x7C, 0x10}, {0x3B, 0x10}, {0x28, 0x12}, {0x29, 0x12}, {0x3C, 0x12}, {0x3E, 0x12}, {0x3F, 0x14}, {0x7D, 0x14}, {0x73, 0x14}, {0x25, 0x14}, {0x63, 0x14}, {0x7B, 0x14}, {0x21, 0x16}, {0x76, 0x16}, {0x69, 0x16}, {0x5B, 0x16}, {0x49, 0x16}, {0x7A, 0x16}, {0x78, 0x16}, {0x74, 0x16}, {0x5D, 0x16}, {0x31, 0x17}, {0x72, 0x17}, {0x6F, 0x18}, {0x6C, 0x18}, {0x2A, 0x18}, {0x65, 0x18}, {0x61, 0x18}, {0x6E, 0x19}, {0x75, 0x19}, {0x54, 0x1A}, {0x66, 0x1A}, {0x77, 0x1A}, {0x33, 0x1B}, {0x37, 0x1B}, {0x6A, 0x1C}, {0x4A, 0x1C}, {0x79, 0x1C}, {0x35, 0x1D}, {0x24, 0x1E}, {0x32, 0x1E}, {0x59, 0x1E}, {0x36, 0x1E}, {0x39, 0x1E}, {0x6D, 0x1E}, {0x43, 0x1E}, {0x4C, 0x1E}, {0x53, 0x1F}, {0x34, 0x20}, {0x71, 0x20}, {0x70, 0x20}, {0x6B, 0x20}, {0x67, 0x20}, {0x50, 0x21}, {0x64, 0x21}, {0x68, 0x21}, {0x46, 0x21}, {0x62, 0x21}, {0x4F, 0x22}, {0x58, 0x22}, {0x47, 0x22}, {0x56, 0x22}, {0x45, 0x23}, {0x5A, 0x23}, {0x55, 0x24}, {0x41, 0x24}, {0x44, 0x26}, {0x4B, 0x26}, {0x57, 0x26}, {0x38, 0x26}, {0x48, 0x26}, {0x40, 0x28}, {0x26, 0x28}, {0x52, 0x28}, {0x42, 0x29}, {0x51, 0x29}, {0x23, 0x2A}, {0x30, 0x2D}, {0x4D, 0x2D}, {0x4E, 0x2D}}};
        std::array<color, 0x10> const colors = {{{0, 0, 0}, {128, 0, 0}, {0, 128, 0}, {128, 128, 0}, {0, 0, 128}, {128, 0, 128}, {0, 128, 128}, {192, 192, 192}, {128, 128, 128}, {255, 0, 0}, {0, 255, 0}, {255, 255, 0}, {0, 0, 255}, {255, 0, 255}, {0, 255, 255}, {255, 255, 255}}};
        std::array<std::array<std::array<uint16_t, 0x100>, 0x100>, 0x100> grid = {};
        std::array<entry, 95 * 0x100> entries = {};
        unsigned diff(color const & a, color const & b) {
            return std::abs(a.r - b.r) + std::abs(a.g - b.g) + std::abs(a.b - b.b);
        }
        bool sub_check(color const & coord, color const & col) {
            auto & g = grid[coord.r][coord.g][coord.b];
            auto & e = entries[g];
            auto d1 = diff(e.c, coord);
            auto d2 = diff(col, coord);
            return d2 < d1;
        }
        bool sub_set(color const & coord, color const & col, uint16_t id) {
            if (!sub_check(coord, col))
                return false;
            grid[coord.r][coord.g][coord.b] = id;
            return true;
        }
        bool sub_z(color const & coord, color const & col, uint16_t id) {
            if (!sub_check(coord, col))
                return false;
            for (int x = coord.b; x <= 255; ++x)
                if (!sub_set({coord.r, coord.g, static_cast<uint8_t>(x)}, col, id))
                    break;
            for (int x = coord.b - 1; x >= 0; --x)
                if (!sub_set({coord.r, coord.g, static_cast<uint8_t>(x)}, col, id))
                    break;
            return true;
        }
        bool sub_y(color const & coord, color const & col, uint16_t id) {
            if (!sub_check(coord, col))
                return false;
            for (int x = coord.g; x <= 255; ++x)
                if (!sub_z({coord.r, static_cast<uint8_t>(x), coord.b}, col, id))
                    break;
            for (int x = coord.g - 1; x >= 0; --x)
                if (!sub_z({coord.r, static_cast<uint8_t>(x), coord.b}, col, id))
                    break;
            return true;
        }
        void sub_x(color const & coord, color const & col, uint16_t id) {
            if (!sub_check(coord, col))
                return;
            for (int x = coord.r; x <= 255; ++x)
                if (!sub_y({static_cast<uint8_t>(x), coord.g, coord.b}, col, id))
                    break;
            for (int x = coord.r - 1; x >= 0; --x)
                if (!sub_y({static_cast<uint8_t>(x), coord.g, coord.b}, col, id))
                    break;
        }
        void prepare_entries() {
            auto id = 0;
            auto chosen = {0, 7, 8, 15};
            for (auto & a : characters) {
                auto ratio = a.coverage / 96.;
                auto iratio = 1 - ratio;
                for (auto x = 0u; x < 0x10; ++x) {
                    auto & b = colors[x];
                    for (auto y = 0u; y < 0x10; ++y) {
                        auto & c = colors[y];
                        auto d = color{static_cast<uint8_t>(b.r * ratio + c.r * iratio), static_cast<uint8_t>(b.g * ratio + c.g * iratio), static_cast<uint8_t>(b.b * ratio + c.b * iratio)};
                        auto code = x | (y << 4);
                        entries[id++] = {d, code, a.character};
                    }
                }
            }
        }
        void generate_grid() {
            prepare_entries();
            for (auto id = 0u; id < entries.size(); ++id) {
                sub_x(entries[id].c, entries[id].c, id);
            }
            auto out = std::ofstream("map.bin", std::ios::binary);
            for (auto & x : grid) {
                for (auto & y : x) {
                    for (auto & z : y) {
                        out.write(reinterpret_cast<char *>(&z), 2);
                    }
                }
            }
        }
        void convert() {
            prepare_entries();
            auto grid_in = std::ifstream("map.bin", std::ios::binary);
            for (auto & x : grid) {
                for (auto & y : x) {
                    for (auto & z : y) {
                        grid_in.read(reinterpret_cast<char *>(&z), 2);
                    }
                }
            }
            auto in = image("image.png");
            unsigned width;
            std::cin >> width;
            auto const xratio = static_cast<double>(in.width) / width;
            auto const yratio = xratio * 1.5;
            auto const height = static_cast<unsigned>(in.height / yratio);
            auto pixels = std::vector<uint16_t>{};
            pixels.resize(width * height);
            for (auto y = 0u; y < height; ++y) {
                auto const yt = static_cast<unsigned>(y * yratio), yb = static_cast<unsigned>(y * yratio + yratio);
                for (auto x = 0u; x < width; ++x) {
                    auto const xt = static_cast<unsigned>(x * xratio), xb = static_cast<unsigned>(x * xratio + xratio);
                    auto const total = 1. / ((xb - xt) * (yb - yt) * 255);
                    auto r = 0., g = 0., b = 0.;
                    for (auto yi = yt; yi < yb; ++yi) {
                        for (auto xi = xt; xi < xb; ++xi) {
                            auto const c = in.get(xi, yi);
                            auto const a = static_cast<double>(c.a);
                            r += c.r * a;
                            g += c.g * a;
                            b += c.b * a;
                        }
                    }
                    auto c = color{static_cast<uint8_t>(r * total), static_cast<uint8_t>(g * total), static_cast<uint8_t>(b * total)};
                    pixels[y * width + x] = grid[static_cast<uint8_t>(r * total)][static_cast<uint8_t>(g * total)][static_cast<uint8_t>(b * total)];
                    auto & e = entries[pixels[y * width + x]];
                    int a = 1 + 1;
                }
            }
            auto out = std::ofstream("image.txt", std::ios::binary);
            out << width << " " << height << std::endl;
            for (auto y = 0u; y < height; ++y) {
                for (auto x = 0u; x < width; ++x) {
                    auto & e = entries[pixels[y * width + x]];
                    out.put(e.code).put(e.character);
                }
            }
        }
    }
}

int main() {
    //print_ascii();
    //calc_ascii();
    //ascii();
    //fancy_ascii();
    //string name;
    //cin >> name;
    ////update_tilesheet(name);
    //import_tilesheet(name);
    auto t1 = high_resolution_clock::now();
    //ascii::generate_grid();
    ascii::convert();
    auto t2 = high_resolution_clock::now();
    cout << duration_cast<milliseconds>(t2 - t1).count() << endl;
    return EXIT_SUCCESS;
}
