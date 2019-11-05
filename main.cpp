#include <iostream>

#include "person.h"
#include "simplehashtable.h"

using namespace std;

int main()
{
    SimpleHashTable<Person> hashTable;

    hashTable.insert(Person("Eduardo"));
    hashTable.insert(Person("Marcelo"));
    hashTable.insert(Person("Hanae"));
    hashTable.insert(Person("Djovana"));
    hashTable.insert(Person("Hanna"));
    hashTable.insert(Person("Hiago"));

    // find() test
    Person* p = hashTable.find(Person("Eduardo"));

    if (p != nullptr) {
        cout << "Founded: " << p->getName() << endl;
    } else {
        cout << "Not Founded" << endl;
    }

    // exists() test
    cout << "Exists person 'hanae'? " << (hashTable.exists(Person("hanae")) ? "Yes" : "No") << endl;

    hashTable.remove(Person("hanae"));
    cout << "Exists person 'hanae' after remove her? " << (hashTable.exists(Person("hanae")) ? "Yes" : "No") << endl;

    return EXIT_SUCCESS;
}
