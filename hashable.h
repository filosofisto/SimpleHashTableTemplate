#ifndef HASHABLE_H
#define HASHABLE_H

class Hashable
{
public:
    Hashable();
    ~Hashable();

    virtual int hashCode() const = 0;
};

#endif // HASHABLE_H
