#include "Person.h"
#include "Resources.h"
#include "Utils.h"
#include <string>
#include <vector>
#include <fstream>

using std::vector;
using std::string;

class PersonGenerator {
    private:
        class Name {
            public:
                Name(string _name, int _count) {
                    name = _name;
                    count = _count;
                };
                string name;
                int count;
        };

    public:
        using NameList = vector<Name*>;
        using PersonList = vector<Person*>;

    public:
        static PersonList generate(int num);
        static Person* generatePerson();
        static void load();
        static void unload();

    private:
        static void loadNameSet(const Resource& resource, NameList* list, int* count);
        static string generateLastName();
        static string generateFemaleFirstName();
        static string generateMaleFirstName();

    private:
        static NameList _fFirstNames;
        static NameList _mFirstNames;
        static NameList _lastNames;
        static int _fCount;
        static int _mCount;
        static int _lastCount;
};