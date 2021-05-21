#include <iostream>
#include <fstream>
#include <locale>

using namespace std;

struct Student {
    char firstName[20];
    char middleName[20];
    char lastName[20];
    double gpa;
    char egn[11];
};

int main() {
    setlocale(LC_ALL, "bulgarian");
    Student student;
    fstream file;

    file.open("students.txt", ios::trunc | ios::in | ios::out);
    int n, i;
    cout << "Въведи броя на учениците: ";
    cin >> n;
    for (i = 0; i < n; i++) {
        cout << "Име: ";
        cin >> student.firstName;
        cout << "Презиме: ";
        cin >> student.middleName;
        cout << "Фамилия: ";
        cin >> student.lastName;
        cout << "Среден успех: ";
        cin >> student.gpa;
        cout << "ЕГН: ";
        cin >> student.egn;

        file << student.firstName << " ";
        file << student.middleName << " ";
        file << student.lastName << " ";
        file << student.gpa << " ";
        file << student.egn << "\n";
    }
    file.seekg(0);
    for (i = 0; i < n; i++) {
        file >> student.firstName;
        file >> student.middleName;
        file >> student.lastName;
        file >> student.gpa;
        file >> student.egn;
        
        if (student.gpa >= 4 && student.gpa <= 5) {
            cout << student.firstName << " ";
            cout << student.middleName << " ";
            cout << student.lastName << endl;
        }
    }
    file.close();
    return 0;
}