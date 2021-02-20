#include <iostream>
#include <cstring>

struct Person {
    char firstName[16];
    char lastName[16];
    char ucn[11];
};

void swap(Person &a, Person &b) {
    Person temp = b;
    b = a;
    a = temp;
    return;
}

void inputPerson(Person &p) {
    std::cout << "First name: ";
    std::cin >> p.firstName;
    std::cout << "Last name: ";
    std::cin >> p.lastName;
    std::cout << "UCN: ";
    std::cin >> p.ucn;
    return;
}

void printPerson(Person p) {
    std::cout << p.firstName << ' ' << p.lastName << ' ' << p.ucn << std::endl;
    return;
}

void sortCollection(Person personArr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i -1; j++) {
            if (std::strcmp(personArr[j].firstName, personArr[j+1].firstName) > 0)
                swap(personArr[j], personArr[j+1]);
        }
    }
}

int main() {
    int n;
    std::cin >> n;
    Person personCollection[n];
    for (int i = 0; i < n; i++)
        inputPerson(personCollection[i]);
    sortCollection(personCollection, n);
    for (int i = 0; i < n; i++)
        printPerson(personCollection[i]);
    return 0;
}
