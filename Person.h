#ifndef TEXAS_TRAIL_PERSON_H
#define TEXAS_TRAIL_PERSON_H
#include <string>

class Person {
    public:
        using string = std::string;
    public:
        Person();
        Person(string name);
        ~Person();

        void setName(string name);
        string getName() const;
    private:
        string _name;
};

#endif