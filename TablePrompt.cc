#include "TablePrompt.h"

TablePrompt::TablePrompt(const string& prompt, const StringList& headers) : _prompt(prompt), _headers(headers) {}
TablePrompt::~TablePrompt() {}

void TablePrompt::add(const StringList& row) {
    _cells.push_back(row);
    _height++;
}
int TablePrompt::execute() const {
    Log::log("%s%s" __RESET "\n\n", Style::New(Formatting::Color::YELLOW).with(Formatting::Format::BOLD).text().c_str(), _prompt.c_str());
    
    vector<int> column_widths;

    for(int i=0;i<_cells.size();i++) {
        column_widths.push_back(_headers[i].size()); // Minimum width
        for(int j=0;j<_cells[i].size();j++) {
            column_widths[i] = _cells[i][j].size() > column_widths[i] ? _cells[i][j].size() : column_widths[i];
        }
    }

    // <painful box drawing>

    
//   Char referenfce
// Your choice <text text text>
//   8           3
//   Item        Price
//  ┌───────────┬──────┐
//  │ 1. Food   │ $7   │
//  ├───────────┼──────┤
//  │ 2. Axles  │ $40  │
//  └───────────┴──────┘
    Log::log("%d %d %d\n", column_widths[0],column_widths[1], column_widths[2]);
    Log::log("   %s", _headers[0].c_str());
    for(int i=0;i<_headers.size()-1;i++) {
        Log::log(numerateChar(" ", column_widths[i]+4-_headers[i].size()).c_str());
        Log::log("%s", _headers[i+1].c_str());
    }
    Log::log("\n  \u250c");

    for(int i=0;i<_headers.size();i++) {
        Log::log(numerateChar("\u2500", column_widths[i]+3).c_str());
        if(i != _headers.size()-1) {Log::log("\u252c");}
    }
    Log::log("\u2510\n");

    for(int i=0;i<_cells.size();i++) {
        for(int j=0;j<_cells[i].size();j++) {
            Log::log("  \u2502 %s", _cells[i][j].c_str());
            Log::log(numerateChar(" ", column_widths[j]-_cells[i][j].size()).c_str());
        }
        Log::log("  \u2502\n  %s", i == _cells.size()-1 ? "\u2514" : "\u251c");
        for(int j=0;j<_cells[i].size();j++) {
            Log::log(numerateChar("\u2500", column_widths[j]+3).c_str());
            if(j != _cells[i].size()-1) {
                Log::log("\u253c");
            }
        }
        Log::log("%s\n", i == _cells.size()-1 ? "\u2518" : "\u2524");
    }
    
    
    // </painful box drawing>

    Log::log("%sWhat is your choice? " __RESET, Style::New(Formatting::Color::GREEN).with(Formatting::Format::BOLD).text().c_str());

    int chosen = -1;
    chosen = getResponse();

    while(!isValidResponse(chosen)) {
        Log::log( __RED "Invalid Reponse." __RESET " What is your choice? ");
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

    if(response < 1 || response > _cells.size()) {
        r = false;
    }

    return r;
}

string TablePrompt::numerateChar(string chr, int count) const {
    string str = "";
    for(int i=0;i<count;i++) {
        str += chr;
    }
    return str;
}