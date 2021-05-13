#include <iostream>
#include <fstream>

using namespace std;
int main() {
    char name[20];
    int age;
    ofstream myFile;
    myFile.open("zad_1.txt", ios::out);
    for (int i = 0; i < 5; i++) {
        cout << "Name: ";
        cin >> name;
        cout << "Age: ";
        cin >> age;
        myFile << name << " ";
        myFile << age << '\n';
    }

    myFile.close();
    return 0;
}