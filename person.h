#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person
{
public:
    Person(long cpf, const string& name);
    virtual ~Person() = default;

    string getName() const;

    long getCpf() const;
private:

    string name;
    long cpf;
};

#endif // PERSON_H
