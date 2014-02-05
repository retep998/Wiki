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
        unsigned const num_chars = 5;
        std::array<unsigned, num_chars> const chars = {{0x20, 0xb0, 0xb1, 0xb2, 0xdb}};
        std::array<char_entry, num_chars> const characters = {{{0x20, 0x00}, {0xb0, 0x0c}, {0xb1, 0x18}, {0xb2, 0x24}, {0xdb, 0x30}}};
        std::array<color, 0x10> const colors = {{{0x00, 0x00, 0x00}, {0x80, 0x00, 0x00}, {0x00, 0x80, 0x00}, {0x80, 0x80, 0x00}, {0x00, 0x00, 0x80}, {0x80, 0x00, 0x80}, {0x00, 0x80, 0x80}, {0xc0, 0xc0, 0xc0}, {0x80, 0x80, 0x80}, {0xff, 0x00, 0x00}, {0x00, 0xff, 0x00}, {0xff, 0xff, 0x00}, {0x00, 0x00, 0xff}, {0xff, 0x00, 0xff}, {0x00, 0xff, 0xff}, {0xff, 0xff, 0xff}}};
        std::array<std::array<std::array<uint16_t, 0x100>, 0x100>, 0x100> grid = {};
        std::vector<entry> entries;
        void print_chars() {
            auto out = std::ofstream("chars.txt");
            for (auto c : chars) {
                out.put(c);
            }
            out.put('\n');
            for (auto c : chars) {
                out << std::hex << "0x" << (int)c << ", ";
            }
            out.put('\n');
        }
        void calc(unsigned w, unsigned h) {
            auto vals = std::array<std::pair<unsigned, unsigned>, num_chars>{};
            auto ws = std::to_string(w);
            auto hs = std::to_string(h);
            auto img = image("chars" + ws + "x" + hs + ".png");
            for (auto i = 0u; i < num_chars; ++i) {
                auto const off = i * w;
                auto sum = 0u;
                for (auto x = off; x < off + w; ++x) {
                    for (auto y = 0u; y < h; ++y) {
                        auto const c = img.get(x, y);
                        sum += c.r ? 1 : 0;
                    }
                }
                vals[i].first = sum;
                vals[i].second = chars[i];
            }
            std::sort(vals.begin(), vals.end(), [](std::pair<unsigned, unsigned> const & a, std::pair<unsigned, unsigned> const & b) {
                return a.first < b.first;
            });
            auto out = std::ofstream("chars" + ws + "x" + hs + ".txt");
            out << std::setfill('0') << std::hex;
            for (auto it : vals) {
                out << "{0x" << std::setw(2) << it.second << ", 0x" << std::setw(2) << it.first << "}, ";
            }
            out << std::endl;
        }
        unsigned diff(color const & a, color const & b) {
            return std::abs(a.r - b.r) + std::abs(a.g - b.g) + std::abs(a.b - b.b);
        }
        void prepare_entries() {
            //auto chosen = {0, 7, 8, 15};//Grayscale
            auto chosen = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};//Full color
            for (auto & a : characters) {
                auto ratio = a.coverage / (6. * 8);
                auto iratio = 1 - ratio;
                for (auto x : chosen) {
                    auto & b = colors[x];
                    for (auto y : chosen) {
                        auto & c = colors[y];
                        auto d = color{static_cast<uint8_t>(b.r * ratio + c.r * iratio), static_cast<uint8_t>(b.g * ratio + c.g * iratio), static_cast<uint8_t>(b.b * ratio + c.b * iratio)};
                        auto code = x | (y << 4);
                        bool found = false;
                        for (auto & e : entries) {
                            if (e.c == d) {
                                found = true;
                            }
                        }
                        if (!found) {
                            entries.push_back({d, code, a.character});
                        }
                    }
                }
            }
        }
        void generate_grid() {
            prepare_entries();
            auto out = std::ofstream("map6x8.bin", std::ios::binary);
            auto blah = color{0, 0, 0};
            for (auto x = 0; x < 0x100; ++x) {
                std::cout << '.';
                for (auto y = 0; y < 0x100; ++y) {
                    for (auto z = 0; z < 0x100; ++z) {
                        auto && target = color{static_cast<uint8_t>(x), static_cast<uint8_t>(y), static_cast<uint8_t>(z)};
                        auto bestd = 1024u;
                        auto bestc = &blah;
                        auto besti = uint16_t{0};
                        for (auto i = uint16_t{0}; i < entries.size(); ++i) {
                            auto & e = entries[i];
                            auto & ec = e.c;
                            auto const d = diff(ec, target);
                            if (d < bestd) {
                                bestd = d;
                                bestc = &ec;
                                besti = i;
                            }
                        }
                        out.write(reinterpret_cast<char *>(&besti), 2);
                    }
                }
            }
        }
        void convert(unsigned const width, std::string name) {
            prepare_entries();
            auto grid_in = std::ifstream("map6x8.bin", std::ios::binary);
            for (auto & x : grid) {
                for (auto & y : x) {
                    for (auto & z : y) {
                        grid_in.read(reinterpret_cast<char *>(&z), 2);
                    }
                }
            }
            auto in = image{name};
            auto const xratio = static_cast<double>(in.width) / width;
            auto const yratio = xratio * (8. / 6);
            auto const height = static_cast<unsigned>(in.height / yratio);
            auto pixels = std::vector<uint16_t>{};
            pixels.resize(width * height);
            for (auto y = 0u; y < height; ++y) {
                auto const yt = static_cast<unsigned>(y * yratio), yb = static_cast<unsigned>((y + 1) * yratio);
                for (auto x = 0u; x < width; ++x) {
                    auto const xt = static_cast<unsigned>(x * xratio), xb = static_cast<unsigned>((x + 1) * xratio);
                    auto const total = (xb - xt) * (yb - yt) * 255u;
                    auto r = 0u, g = 0u, b = 0u;
                    for (auto yi = yt; yi < yb; ++yi) {
                        for (auto xi = xt; xi < xb; ++xi) {
                            auto const c = in.get(xi, yi);
                            r += c.r * c.a;
                            g += c.g * c.a;
                            b += c.b * c.a;
                        }
                    }
                    pixels[y * width + x] = grid[static_cast<uint8_t>(r / total)][static_cast<uint8_t>(g / total)][static_cast<uint8_t>(b / total)];
                    auto & e = entries[pixels[y * width + x]];
                }
            }
            auto mapping = std::array<std::string, 0x100>{};
            mapping[0x20] = {{0x20}};
            mapping[0xb0] = {{-30, -106, -111}};
            mapping[0xb1] = {{-30, -106, -110}};
            mapping[0xb2] = {{-30, -106, -109}};
            mapping[0xdb] = {{-30, -106, -120}};
            auto out = std::ofstream("motd.txt", std::ios::binary);
            for (auto y = 0u; y < height; ++y) {
                for (auto x = 0u; x < width; ++x) {
                    auto & e = entries[pixels[y * width + x]];
                    out << "\x1b[" << (e.code & 0x80 ? "5" : "25");
                    out << ";" << (e.code & 0x08 ? "1" : "21");
                    out << ";" << static_cast<int>(((e.code & 0x70) >> 4) + 40);
                    out << ";" << static_cast<int>((e.code & 0x07) + 30);
                    out << "m" << mapping[e.character];
                }
                out << '\n';
            }
        }
    }
}

int main(int argc, char ** argv) {
    auto get_num = [] {
        auto num = unsigned{};
        std::cin >> num;
        return num;
    };
    //string name;
    //cin >> name;
    ////update_tilesheet(name);
    //import_tilesheet(name);
    auto t1 = high_resolution_clock::now();
    //ascii::print_chars();
    //ascii::calc(6, 8);
    //ascii::generate_grid();
    if (argc > 1) {
        ascii::convert(get_num(), argv[1]);
    }
    auto t2 = high_resolution_clock::now();
    cout << duration_cast<milliseconds>(t2 - t1).count() << endl;
    return EXIT_SUCCESS;
}
