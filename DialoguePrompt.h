#ifndef TEXAS_TRAIL_DIALOGUE_PROMPT_H
#define TEXAS_TRAIL_DIALOGUE_PROMPT_H
#include <string>
#include <vector>
#include "Formatting.h"
using std::string;
using std::vector;

class DialoguePrompt {
public:
    using StringList = vector<string>;

public: 
    DialoguePrompt(const string& prompt, const StringList& choices);
    virtual ~DialoguePrompt();

    virtual int execute() const;

private: 
    const string _prompt;
    const StringList _choices;

    bool isValidResponse(int response) const;
    int getResponse() const;
};

#endif