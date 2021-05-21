#include <iostream>
#include <fstream>
#include "person.h"

int main() {
    Person person;
    int n;
    std::cout << "Count of people: ";
    std::cin >> n;

    std::ofstream file;
    file.open("people.txt", std::ios::out);
    for (int i = 0; i < n; i++) {
        std::cout << "Person(" << i+1 << "/" << n << "):\n";
        std::cout << "First name: ";
        std::cin >> person.firstName;
        std::cout << "Middle name: ";
        std::cin >> person.middleName;
        std::cout << "Last name: ";
        std::cin >> person.lastName;
        std:: cout << "EGN: ";
        std::cin >> person.egn;

        file << person.firstName << " ";
        file << person.middleName << " ";
        file << person.lastName << " ";
        file << person.egn << "\n";
    }
    
    file.close();
    return 0;
}