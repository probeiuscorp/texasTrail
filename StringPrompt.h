#ifndef STRING_PROMPT_H
#define STRING_PROMPT_H
#include <string>
#include <vector>
#include "Formatting.h"
using std::string;
using std::vector;

class StringPrompt {
public:
    using StringList = vector<string>;

public: 
    StringPrompt(const string& prompt, const StringList& choices);
    virtual ~StringPrompt();

    virtual StringList execute() const;

private: 
    const string _prompt;
    const StringList _choices;

    string getResponse() const;
};

#endif