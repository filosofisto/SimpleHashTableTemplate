#include "person.h"

Person::Person(const string& name): name(name)
{

}

string Person::getName() const
{
    return this->name;
}

int Person::hashCode() const
{
    int sum = 0;
    int pos = 0;

    for (char ch: name) {
        sum += ch*++pos;
    }

    return sum;
}
