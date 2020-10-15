#ifndef TEXAS_TRAIL_INT_PROMPT_H
#define TEXAS_TRAIL_INT_PROMPT_H
#include "Colors.h"
#include "Formatting.h"
#include "Log.h"
#include <string>
#include <sstream>
#include <iostream>

class IntPrompt {
    public: 
        IntPrompt(const std::string& prompt, int min, int max);
        virtual ~IntPrompt();

        virtual int execute() const;

    private: 
        const std::string _prompt;
        int _min;
        int _max;

        bool isValidResponse(int response) const;
        int getResponse() const;
};

#endif