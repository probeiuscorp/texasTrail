#ifndef TEXAS_TRAIL_TABLE_PROMPT_H
#define TEXAS_TRAIL_TABLE_PROMPT_H
#include "Log.h"
#include "Colors.h"
#include "Formatting.h"
#include "Utils.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using std::string;
using std::vector;

class TablePrompt {
public:
    using StringList = vector<string>;
    using TableList = vector<StringList>;

public: 
    TablePrompt(const string prompt, const StringList& headers);
    virtual ~TablePrompt();

    virtual void add(const StringList& row);
    virtual int execute() const;

private: 
    const StringList _headers;
    TableList _cells;
    const string _prompt;
    int _height = 0;

    int getResponse() const;
    bool isValidResponse(int response) const;
};

#endif