#include <iostream>
#include <fstream>

using namespace std;

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