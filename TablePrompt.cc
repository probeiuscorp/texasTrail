#include "TablePrompt.h"

TablePrompt::TablePrompt(const string prompt, const StringList& headers) : _prompt(prompt), _headers(headers) {}
TablePrompt::~TablePrompt() {}

void TablePrompt::add(const StringList& row) {
    _cells.push_back(row);
    _height++;
}

int TablePrompt::execute() const {
    return execute(1);
}

int TablePrompt::execute(int columns) const {
    if(_cells.size() < columns) columns = _cells.size();

    Log::log("%s%s" __RESET "\n\n", Style::New(Formatting::Color::YELLOW).with(Formatting::Format::BOLD).text().c_str(), _prompt.c_str());
    
    vector<vector<StringList>> cells = vector<vector<StringList>>(columns);

    int next = 0;
    for(StringList row : _cells) {
        cells[next].push_back(row);
        next++;
        next %= columns;
    }

    vector<vector<int>> column_widths;

    if(_cells.size() == 0 || _cells[0].size() == 0) {
        Log::log("  \u256d%s\u256e\n", Utils::numerateString("\u2500", 24).c_str());
        Log::log("  \u2502 Nothing to see here... \u2502\n");
        Log::log("  \u2570%s\u256f\n", Utils::numerateString("\u2500", 24).c_str());
    } else {
        for(int c=0;c<columns;c++) {
            column_widths.push_back(vector<int>());
            for(int i=0;i<cells[c][0].size();i++) {
                column_widths[c].push_back(_headers[i].size());
                for(int j=0;j<cells[c].size();j++) {
                    if(cells[c][j][i].size() > column_widths[c][i]) {
                        column_widths[c][i] = cells[c][j][i].size();
                    }
                }
            }
        }
        // <painful box drawing>

        // Log::log("    %s", _headers[0].c_str());
        // for(int i=0;i<_headers.size()-1;i++) {
        //     Log::log(Utils::numerateString(" ", column_widths[0][i]+4-_headers[i].size()).c_str());
        //     Log::log("%s", _headers[i+1].c_str());
        // }
        // Log::log("\n  \u256d");

        // for(int i=0;i<_headers.size();i++) {
        //     Log::log(Utils::numerateString("\u2500", column_widths[0][i]+3).c_str());
        //     if(i != _headers.size()-1) {Log::log("\u252c");}
        // }
        // Log::log("\u256e\n");
        // for(int i=0;i<cells[0].size();i++) {
        //     for(int c=0;c<cells.size();c++) {
        //         // Draw text lines SILVER CITY
        //         for(int j=0;j<cells[c][i].size();j++) {
        //             Log::log("  \u2502 %s", cells[0][i][j].c_str());
        //             Log::log(Utils::numerateString(" ", column_widths[c][j]-cells[c][i][j].size()).c_str());
        //         }
        //         Log::log("  \u2502%s  %s", c == cells.size()-1 ? "\n":"", i == cells[c].size()-1 ? "\u2570" : "\u251c");
        //         // Draw bottom line
        //         for(int j=0;j<cells[c][i].size();j++) {
        //             Log::log(Utils::numerateString("\u2500", column_widths[c][j]+3).c_str());
        //             if(j != cells[i].size()-1) {
        //                 Log::log("%s", i == cells[c].size()-1 ? "\u2534" : "\u253c");
        //             }
        //         }
        //         Log::log(i == cells[c].size()-1 ? "\u256f" : "\u2524");
        //         if(c == cells.size()-1) Log::log("\n");
        //     }
        // }

        // Top left, top right, bottom left, bottom right, horizontal, vertical
        const char* TL =  "\u256d"; // ╭
        const char* TR =  "\u256e"; // ╮
        const char* BL =  "\u2570"; // ╰
        const char* BR =  "\u256f"; // ╯
        const char* T =   "\u252c"; // ┬
        const char* B =   "\u2534"; // ┴
        const char* L =   "\u251c"; // ├
        const char* R =   "\u2524"; // ┤
        const char* ALL = "\u253c"; // ┼
        const char* HOR = "\u2500"; // ─
        const char* VER = "\u2502"; // │

        // Print header
        Log::log("   ");
        for(int table=0;table<columns;table++) {
            for(int i=0;i<_headers.size();i++) {
                Log::log(_headers[i].c_str());
                Log::log(Utils::numerateString(" ", column_widths[table][i] - _headers[i].size() + 3).c_str());
            }
            Log::log("     ");
        }
        Log::log("\n");

        // Print top row
        Log::log("  ");
        for(int table=0;table<columns;table++) {
            Log::log(TL);
            for(int w=0;w<column_widths[table].size();w++) {
                Log::log(Utils::numerateString(string(HOR), column_widths[table][w] + 2).c_str());
                bool lastColumn = w == column_widths[table].size() - 1;
                if(!lastColumn)
                    Log::log(T);
            }
            Log::log(TR);
            Log::log("    ");
        }
        Log::log("\n");

        // Print table
        for(int row=0;row<cells[0].size();row++) {
            bool lastRow = row == cells[0].size() - 1;
            for(int table=0;table<columns;table++) {
                bool lastTable = table == columns - 1;
                
                if(cells[table].size() > row) {
                    // Cell values
                    Log::log("  %s", VER);
                    for(int col=0;col<cells[table][row].size();col++) {
                        string& val = cells[table][row][col];
                        Log::log(" %s " __RESET, val.c_str());
                        Log::log(Utils::numerateString(" ", column_widths[table][col]-val.length()).c_str());
                        Log::log(VER);
                    }
                    if(lastTable) {
                        // If the table is a rectangle, don't print another new line
                        if(!lastRow || _cells.size() % columns != 0)
                            Log::log("\n");
                    } else {
                        Log::log("  ");
                    }
                }
            }
            // Line separators
            for(int table=0;table<columns;table++) {
                bool lastTable = table == columns - 1;
                bool secondToLastRow = row == cells[0].size() - 2;
                //                                                                      Tables are all of equal size, all caps are drawn later
                bool lastOfRow = secondToLastRow && _cells.size() % columns <= table && _cells.size() % columns != 0;

                if(!lastRow) {
                    Log::log("  ");
                    Log::log(lastOfRow ? BL : L);
                    for(int w=0;w<column_widths[table].size();w++) {
                        Log::log(Utils::numerateString(string(HOR), column_widths[table][w]+2).c_str());
                        bool lastColumn = w == column_widths[table].size() - 1;
                        if(!lastColumn)
                            Log::log(lastOfRow ? B : ALL);
                    }
                    Log::log(lastOfRow ? BR : R);
                }
                if(lastTable)
                    Log::log("\n");
                else
                    Log::log("  ");
            }
        }

        // End tables that haven't already
        int mod = _cells.size() % columns;
        int capsLeft = mod == 0 ? columns : mod;
        
        Log::log("  ");
        for(int table=0;table<capsLeft;table++) {
            Log::log(BL);
            for(int w=0;w<column_widths[table].size();w++) {
                Log::log(Utils::numerateString(HOR, column_widths[table][w]+2).c_str());
                if(w != column_widths[table].size() - 1) Log::log(B);
            }
            Log::log(BR);
            Log::log("    ");
        }
        Log::log("\n");
        
        // </painful box drawing>
    }

    Log::log("\n%sWhat is your choice? " __RESET, Style::New(Formatting::Color::GREEN).with(Formatting::Format::BOLD).text().c_str());

    int chosen = -1;
    chosen = getResponse();

    while(!isValidResponse(chosen)) {
        Log::log( __RED "Invalid Response." __RESET " What is your choice? ");
        chosen = getResponse();
    }

    Log::log("\n");

    return chosen;
}

int TablePrompt::getResponse() const {
    int chosen = -1;
    string line;

    if(std::getline(std::cin, line)) {
        std::istringstream str(line);
        str >> chosen;
    }

    return chosen;
}

bool TablePrompt::isValidResponse(int response) const {
    bool r = true;

    if(response < 0 || response > _cells.size()) {
        r = false;
    }

    return r;
}