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

#include "image.hpp"

namespace nl {
    void colorizer(path p_file) {
        ifstream file{p_file};
        string line;
        smatch mat;
        auto maker = [](char const * p_str) {
            return regex{p_str, regex_constants::ECMAScript | regex_constants::optimize};
        };
        imagef img;
        vector<pair<regex, function<void()>>> regs =
        {
            {maker(R"/(\s*start\s+(\d+)\s+(\d+)\s*)/"), [&]() {
                img.clear(stol(mat[1]), stol(mat[2]));
            }},
            {maker(R"/(\s*out\s+"([^"]+)"\s*)/"), [&]() {
                path outp{mat[1]};
                img.save(outp);
            }},
            {maker(R"/(\s*in\s+"([^"]+)"\s+#([[:xdigit:]]{2})([[:xdigit:]]{2})([[:xdigit:]]{2})([[:xdigit:]]{2})\s*)/"), [&]() {
                path inp{mat[1]};
                auto r = static_cast<uint8_t>(stol(mat[2], nullptr, 16));
                auto g = static_cast<uint8_t>(stol(mat[3], nullptr, 16));
                auto b = static_cast<uint8_t>(stol(mat[4], nullptr, 16));
                auto a = static_cast<uint8_t>(stol(mat[5], nullptr, 16));
                auto c = static_cast<colorf>(colori{r, g, b, a});
                imagef::temp.load(inp);
                imagef::temp *= c;
                img += imagef::temp;
            }},
            {maker(R"/(\s*in\s+"([^"]+)"\s+#([[:xdigit:]]{2})([[:xdigit:]]{2})([[:xdigit:]]{2})\s*)/"), [&]() {
                path inp{mat[1]};
                auto r = static_cast<uint8_t>(stol(mat[2], nullptr, 16));
                auto g = static_cast<uint8_t>(stol(mat[3], nullptr, 16));
                auto b = static_cast<uint8_t>(stol(mat[4], nullptr, 16));
                auto c = static_cast<colorf>(colori{r, g, b, 0xff});
                imagef::temp.load(inp);
                imagef::temp *= c;
                img += imagef::temp;
            }},
            {maker(R"/(\s*in\s+"([^"]+)"\s*)/"), [&]() {
                path inp{mat[1]};
                imagef::temp.load(inp);
                img += imagef::temp;
            }},
            {maker(R"/(\s*)/"), [&]() {
                cout << "Blank line" << endl;
            }},
            {maker(R"/(.*)/"), [&]() {
                cout << "Invalid line" << endl;
            }}
        };
        while (getline(file, line)) {
            for (auto & r : regs) {
                if (regex_match(line, mat, r.first)) {
                    try {
                        r.second();
                    } catch (exception & e) {
                        cerr << e.what() << endl;
                    }
                    break;
                }
            }
        }
    }
}

int wmain(int argc, wchar_t ** argv) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> convert;
    std::for_each(argv + 1, argv + argc, [&](wchar_t * p_str) {
        nl::colorizer(convert.to_bytes(p_str));
    });
    return 0;
}
