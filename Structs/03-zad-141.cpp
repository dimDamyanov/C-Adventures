#include <iostream>
#include <cstring>

char DELIMETER[5] = "";


struct Student {
    char firstName[20];
    char midName[20];
    char lastName[20];
    char ucn[11];
    float gpa;
};

void printDataHeader(int fieldWidth = 15) {
    std::cout.width(fieldWidth); std::cout << std::left <<"First N.";
    std::cout.width(fieldWidth); std::cout << std::left <<"Middle N.";
    std::cout.width(fieldWidth); std::cout << std::left <<"Last N.";
    std::cout.width(fieldWidth); std::cout << std::left <<"UCN";
    std::cout.width(fieldWidth); std::cout << std::left <<"GPA";
    std::cout << std::endl;
    for (int i = 0; i < 75; i++) std::cout << '-';
    std::cout << std::endl;
    return;
}

void printStudent(Student student, int fieldWidth = 15, char *delimeter = DELIMETER) {
    std::cout.width(fieldWidth); std::cout << std::left << student.firstName;
    std::cout << delimeter;
    std::cout.width(fieldWidth); std::cout << std::left << student.midName;
    std::cout << delimeter;
    std::cout.width(fieldWidth); std::cout << std::left << student.lastName;
    std::cout << delimeter;
    std::cout.width(fieldWidth); std::cout << std::left << student.ucn;
    std::cout << delimeter;
    std::cout.width(fieldWidth); std::cout << std::left << student.gpa;
    std::cout << std::endl;
    return;
}

void inputStudent(Student &student) {
    std::cout << "First Name: "; std::cin >> student.firstName;
    std::cout << "Middle Name: "; std::cin >> student.midName;
    std::cout << "Last Name: "; std::cin >> student.lastName;
    std::cout << "UCN: "; std::cin >> student.ucn;
    std::cout << "GPA: "; std::cin >> student.gpa;
    return;
}

int main() {
    int n;
    std::cout << "n="; std::cin >> n;
    Student studentsCollection[n];
    for (int i = 0; i < n; i++) {
        std::cout << '(' << i + 1 << '/' << n << ')' << std::endl;
        inputStudent(studentsCollection[i]);
    }
    printDataHeader();
    for (int i = 0; i < n; i++) {
        if (studentsCollection[i].gpa >= 5.50)
            printStudent(studentsCollection[i]);
    }
    return 0;
}