#include <iostream>

struct Student {
    char firstName[20];
    char midName[20];
    char lastName[20];
    char ucn[20];
    float gpa;
};

void printStudent(Student s) {
    std::cout << s.firstName << ' ';
    std::cout << s.midName << ' ';
    std::cout << s.lastName << ' ';
    std::cout << s.ucn << ' ';
    std::cout << s.gpa << std::endl;
    return;
}

void inputStudent(Student &s) {
    std::cout << "First name: ";
    std::cin >> s.firstName;
    std::cout << "Middle name: ";
    std::cin >> s.midName;
    std::cout << "Last name: ";
    std::cin >> s.lastName;
    std::cout << "UCN: ";
    std::cin >> s.ucn;
    std::cout << "GPA: ";
    std::cin >> s.gpa;
    return;
}

int main() {
    Student s;
    inputStudent(s);
    printStudent(s);
    return 0;
}
