#include <iostream>

#include "person.h"
#include "simplehashtable.h"

using namespace std;

int main()
{
    SimpleHashTable<Person, long> hashTable;

    hashTable.put(81646674987, Person(81646674987, "Eduardo"));
    hashTable.put(11111111111, Person(11111111111, "Marcelo"));
    hashTable.put(22222222222, Person(22222222222, "Hanae"));
    hashTable.put(33333333333, Person(33333333333, "Djovana"));
    hashTable.put(44444444444, Person(44444444444, "Hanna"));
    hashTable.put(55555555555, Person(55555555555, "Hiago"));

    // get() test
    Person* p = hashTable.get(81646674987);

    if (p != nullptr) {
        cout << "Founded: " << p->getName() << " - " << p->getCpf() << endl;
    } else {
        cout << "Not Founded" << endl;
    }

    // exists() test
    cout << "Exists person 'hanae'? " << (hashTable.exists(22222222222) ? "Yes" : "No") << endl;

    hashTable.remove(22222222222);
    cout << "Exists person 'hanae' after remove her? " << (hashTable.exists(22222222222) ? "Yes" : "No") << endl;

    return EXIT_SUCCESS;
}
