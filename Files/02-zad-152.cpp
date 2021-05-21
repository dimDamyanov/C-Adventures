#include <iostream>
#include <fstream>

using namespace std;

struct Person {
    char firstName[20];
    char middleName[20];
    char lastName[20];
    char egn[11];
};

int main() {
    char name[20];
    int age;
    ifstream myFile;
    myFile.open("zad_1.txt", ios::in);
    for (int i = 0; i < 5; i++) {
        myFile >> name;
        cout << name << " ";
        myFile >> age;
        cout << age << '\n';
    }

    myFile.close();
    return 0;
}