#include "PersonGenerator.h"

PersonGenerator::NameList PersonGenerator::_fFirstNames = PersonGenerator::NameList();
PersonGenerator::NameList PersonGenerator::_mFirstNames = PersonGenerator::NameList();
PersonGenerator::NameList PersonGenerator::_lastNames = PersonGenerator::NameList();
int PersonGenerator::_fCount = 0;
int PersonGenerator::_mCount = 0;
int PersonGenerator::_lastCount = 0;

void PersonGenerator::loadNameSet(const Resource& resource, PersonGenerator::NameList* list, int* count) {
    std::ifstream fin;
    fin.open(resource.location(), std::ios::in);

    string line;
    vector<string> slices;
    while(fin) {
        getline(fin, line);
        slices = Utils::split(line, ':');
        if(slices.size() != 2) continue;
        int n = std::stoi(slices[1]);
        list->push_back(new PersonGenerator::Name(slices[0], n));
        (*count) += n;
    }
    // for(Name* name : *list) {
    //     printf("Name %s appears %d times\n", name->name.c_str(), name->count);
    // }
}

void PersonGenerator::load() {
    loadNameSet(Resources::F_FIRST_NAMES, &_fFirstNames, &_fCount);
    loadNameSet(Resources::M_FIRST_NAMES, &_mFirstNames, &_mCount);
    loadNameSet(Resources::LAST_NAMES, &_lastNames, &_lastCount);
}

void PersonGenerator::unload() {
    for(Name* name : _fFirstNames) delete name;
    for(Name* name : _mFirstNames) delete name;
    for(Name* name : _lastNames)   delete name;
}

PersonGenerator::PersonList PersonGenerator::generate(int num) {
    PersonList people;
    for(int i=0;i<num;i++) {
        people.push_back(generatePerson());
    }
    return people;
}

Person* PersonGenerator::generatePerson() {
    if(Utils::chance(0.5)) {
        return new Person(string(generateFemaleFirstName() + " " + generateLastName()), Person::Gender::FEMALE);
    } else {
        return new Person(string(generateMaleFirstName() + " " + generateLastName()), Person::Gender::MALE);
    }
}

string PersonGenerator::generateLastName() {
    string lastName;
    int lastIndex = floor(((double)rand()/RAND_MAX)*_lastCount);
    for(Name* name : _lastNames) {
        lastIndex -= name->count;
        if(lastIndex <= 0) {
            lastName = name->name;
            break;
        }
    }
    return lastName;
}

string PersonGenerator::generateFemaleFirstName() {
    string firstName;
    int firstIndex = floor(((double)rand()/RAND_MAX)*_fCount);
    for(Name* name : _fFirstNames) {
        firstIndex -= name->count;
        if(firstIndex <= 0) {
            firstName = name->name;
            break;
        }
    }
    return firstName;
}

string PersonGenerator::generateMaleFirstName() {
    string firstName;
    int firstIndex = floor(((double)rand()/RAND_MAX)*_mCount);
    for(Name* name : _mFirstNames) {
        firstIndex -= name->count;
        if(firstIndex <= 0) {
            firstName = name->name;
            break;
        }
    }
    return firstName;
}