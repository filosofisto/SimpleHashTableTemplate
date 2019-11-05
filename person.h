#ifndef PERSON_H
#define PERSON_H

#include <string>

#include "hashable.h"

using namespace std;

class Person: public Hashable
{
public:
    Person(const string& name);
    virtual ~Person() = default;

    string getName() const;

    int hashCode() const;
private:

    string name;
};

#endif // PERSON_H
