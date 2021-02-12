#include <iostream>
#include <cstring>

char DELIMETER[5] = "";


struct Student {
    int classNum;
    char firstName[20];
    char midName[20];
    char lastName[20];
    char ucn[11];
    float gpa;
};

void printDataHeader(int fieldWidth = 15) {
    std::cout.width(fieldWidth / 3); std::cout << std::left <<"No.";
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

void printKeyIndexes() {
    std::cout << '\t' << 0 << " => " << "Class No." << std::endl;
    std::cout << '\t' << 1 << " => " << "First name" << std::endl;
    std::cout << '\t' << 2 << " => " << "Middle name" << std::endl;
    std::cout << '\t' << 3 << " => " << "Last name" << std::endl;
    std::cout << '\t' << 4 << " => " << "UCN" << std::endl;
    std::cout << '\t' << 5 << " => " << "GPA" << std::endl;
    return;
}

void printStudent(Student student, int fieldWidth = 15, char *delimeter = DELIMETER) {
    std::cout.width(fieldWidth / 3); std::cout << std::left << student.classNum;
    std::cout << delimeter;
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
    std::cout << "Class No.: "; std::cin >> student.classNum;
    std::cout << "First Name: "; std::cin >> student.firstName;
    std::cout << "Middle Name: "; std::cin >> student.midName;
    std::cout << "Last Name: "; std::cin >> student.lastName;
    std::cout << "UCN: "; std::cin >> student.ucn;
    std::cout << "GPA: "; std::cin >> student.gpa;
    return;
}

void searchByInt(Student studentsCollection[], int n, int key, int searchInt) {
    switch (key) {
        case 0:
            for (int i = 0; i < n; i++) {
                if (studentsCollection[i].classNum == searchInt)
                printStudent(studentsCollection[i]);
            }
            break;
        default:
            std::cout << "ERROR: Search criteria is not an integer!" << std::endl;
            break;
    }
    return;
}

void searchByFloat(Student studentsCollection[], size_t n, int key, float searchFloat) {
    switch (key) {
        case 5:
            for (int i = 0; i < n; i++) {
                if (studentsCollection[i].gpa == searchFloat)
                    printStudent(studentsCollection[i]);
            }
            break;
        default:
            std::cout << "ERROR: Search criteria is not a float!" << std::endl;
            break;
    }
    return;
}

void searchByString(Student studentsCollection[], size_t n, int key, char *searchString) {
    switch (key) {
        case 1:
            for (int i = 0; i < n; i++) {
                if (strcmp(studentsCollection[i].firstName, searchString) == 0)
                    printStudent(studentsCollection[i]);
            }
            break;
        case 2:
            for (int i = 0; i < n; i++) {
                if (strcmp(studentsCollection[i].midName, searchString) == 0)
                    printStudent(studentsCollection[i]);
            }
            break;
        case 3:
            for (int i = 0; i < n; i++) {
                if (strcmp(studentsCollection[i].lastName, searchString) == 0)
                    printStudent(studentsCollection[i]);
            }
            break;
        case 4:
            for (int i = 0; i < n; i++) {
                if (strcmp(studentsCollection[i].ucn, searchString) == 0)
                    printStudent(studentsCollection[i]);
            }
            break;
        default:
                std::cout << "ERROR: Search criteria is not a char array!" << std::endl;
            break;
    }
}

int main() {
    int n, keyIndex;
    std::cout << "n="; std::cin >> n;
    Student studentsCollection[n];
    for (int i = 0; i < n; i++) {
        std::cout << '(' << i + 1 << '/' << n << ')' << std::endl;
        inputStudent(studentsCollection[i]);
    }
    std::cout << "Search by criteria in struct array:" << std::endl;
    printKeyIndexes();
    std::cout << "Enter key index (0-5): ";
    std::cin >> keyIndex;
    char searchStr[20];
    int searchInt;
    float searchFloat;
    switch (keyIndex) {
        case 0:
            
            std::cout << "Enter Class No.: ";
            std::cin >> searchInt;
            printDataHeader();
            searchByInt(studentsCollection, n, keyIndex, searchInt);
            break;
        case 1:
            std::cout << "Enter First name: ";
            std::cin >> searchStr;
            printDataHeader();
            searchByString(studentsCollection, n, keyIndex, searchStr);
            break;
        case 2:
            std::cout << "Enter Middle name: ";
            std::cin >> searchStr;
            printDataHeader();
            searchByString(studentsCollection, n, keyIndex, searchStr);
            break;
        case 3:
            std::cout << "Enter Last name: ";
            std::cin >> searchStr;
            printDataHeader();
            searchByString(studentsCollection, n, keyIndex, searchStr);
            break;
        case 4:
            char searchStr[20];
            std::cout << "Enter UCN: ";
            std::cin >> searchStr;
            printDataHeader();
            searchByString(studentsCollection, n, keyIndex, searchStr);
            break;
        case 5:
            std::cout << "Enter GPA: ";
            std::cin >> searchFloat;
            printDataHeader();
            searchByFloat(studentsCollection, n , keyIndex, searchFloat);
            break;
    default:
        std::cout << "ERROR: Key index not in range (1-5)!" << std::endl;
        break;
    }
    return 0;
}