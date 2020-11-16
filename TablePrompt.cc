#include "TablePrompt.h"

TablePrompt::TablePrompt(const string prompt, const StringList& headers) : _prompt(prompt), _headers(headers) {}
TablePrompt::~TablePrompt() {}

void TablePrompt::add(const StringList& row) {
    _cells.push_back(row);
    _height++;
}
int TablePrompt::execute() const {
    Log::log("%s%s" __RESET "\n\n", Style::New(Formatting::Color::YELLOW).with(Formatting::Format::BOLD).text().c_str(), _prompt.c_str());
    
    vector<int> column_widths;

    if(_cells.size() == 0 || _cells[0].size() == 0) {
        Log::log("  \u256d%s\u256e\n", Utils::numerateString("\u2500", 24).c_str());
        Log::log("  \u2502 Nothing to see here... \u2502\n");
        Log::log("  \u2570%s\u256f\n", Utils::numerateString("\u2500", 24).c_str());
    } else {
        for(int i=0;i<_cells[0].size();i++) {
            column_widths.push_back(_headers[i].size());
            // Log::log("%s\n",_headers[i].size().c_str());
            for(int j=0;j<_cells.size();j++) {
                if(_cells[j][i].size() > column_widths[i]) {
                    column_widths[i] = _cells[j][i].size();
                }
            }
        }

        // <painful box drawing>

        Log::log("    %s", _headers[0].c_str());
        for(int i=0;i<_headers.size()-1;i++) {
            Log::log(Utils::numerateString(" ", column_widths[i]+4-_headers[i].size()).c_str());
            Log::log("%s", _headers[i+1].c_str());
        }
        Log::log("\n  \u256d");

        for(int i=0;i<_headers.size();i++) {
            Log::log(Utils::numerateString("\u2500", column_widths[i]+3).c_str());
            if(i != _headers.size()-1) {Log::log("\u252c");}
        }
        Log::log("\u256e\n");

        for(int i=0;i<_cells.size();i++) {
            for(int j=0;j<_cells[i].size();j++) {
                Log::log("  \u2502 %s", _cells[i][j].c_str());
                Log::log(Utils::numerateString(" ", column_widths[j]-_cells[i][j].size()).c_str());
            }
            Log::log("  \u2502\n  %s", i == _cells.size()-1 ? "\u2570" : "\u251c");
            for(int j=0;j<_cells[i].size();j++) {
                Log::log(Utils::numerateString("\u2500", column_widths[j]+3).c_str());
                if(j != _cells[i].size()-1) {
                    Log::log("%s", i == _cells.size()-1 ? "\u2534" : "\u253c");
                }
            }
            Log::log("%s\n", i == _cells.size()-1 ? "\u256f" : "\u2524");
        }
        
        // </painful box drawing>
    }

    Log::log("\n%sWhat is your choice? " __RESET, Style::New(Formatting::Color::GREEN).with(Formatting::Format::BOLD).text().c_str());

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

    if(response < 0 || response > _cells.size()) {
        r = false;
    }

    return r;
}