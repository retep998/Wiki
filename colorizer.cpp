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

namespace {
    void colorizer(path p_file) {
        ifstream file{p_file};
        string line;
        smatch mat;
        auto maker = [](char const * p_str) {
            return regex{p_str, regex_constants::ECMAScript | regex_constants::optimize};
        };
        vector<pair<regex, function<void()>>> regs =
        {
            {maker("[[:s:]]*start[[:s:]]+([[:d:]]+)[[:s:]]*"), [&]() {
                auto size = stol(mat[1]);
            }},
            {maker("[[:s:]]*out[[:s:]]+\"([^\"]+)\"[[:s:]]*"), [&]() {
                path outp{mat[1]};
            }},
            {maker(""), [&]() {
                cout << "Blank line" << endl;
            }}
        };
        while (getline(file, line)) {
            for (auto & r : regs) {
                if (regex_match(line, mat, r.first)) {
                    r.second();
                    break;
                }
            }
        }
    }
}

int wmain(int argc, wchar_t ** argv) {
    wstring_convert<codecvt_utf8<wchar_t>> convert;
    for_each(argv + 1, argv + argc, [&](wchar_t * p_str) {
        colorizer(convert.to_bytes(p_str));
    });
}