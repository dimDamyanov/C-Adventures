#include <iostream>
#include <fstream>
#include <cstring>
#include "person.h"

int main() {
    int n;
    std::cout << "Count of people: ";
    std::cin >> n;

    std::ifstream inputFile;
    inputFile.open("people.txt", std::ios::in);

    std::ofstream outputFile;
    outputFile.open("people1.txt", std::ios::out);

    Person person;
    for (int i = 0; i < n; i++) {
        inputFile >> person.firstName;
        inputFile >> person.middleName;
        inputFile >> person.lastName;
        inputFile >> person.egn;

        outputFile << person.firstName << " ";
        outputFile << person.middleName << " ";
        outputFile << person.lastName << " ";
        outputFile << person.egn << "\n";
    }
    inputFile.close();
    outputFile.close();

    return 0;
}