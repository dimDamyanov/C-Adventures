#include <iostream>

struct Student {
    char firstName[20];
    char midName[20];
    char lastName[20];
    char ucn[11];
    float gpa;
};

void printStudent(Student s) {
    std::cout << s.firstName << std::endl;
    std::cout << s.midName << std::endl;
    std::cout << s.lastName << std::endl;
    std::cout << s.ucn << std::endl;
    std::cout << s.gpa << std::endl;
}

int main() {
    Student s = {"Ivan", "Ivanov", "Petrov", "1234567890", 5.68};
    printStudent(s);
    return 0;
}