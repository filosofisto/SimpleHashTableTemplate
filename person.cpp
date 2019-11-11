#include "person.h"

Person::Person(long cpf, const string& name): cpf(cpf), name(name)
{

}

string Person::getName() const
{
    return this->name;
}

long Person::getCpf() const {
    return cpf;
}
