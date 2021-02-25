#include <iostream>
#include <limits>
#include <cstring>

struct Patient {
    char name[51];
    char diagnosis[21];
    int stay;
};

void inputPatient(Patient &p) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Name: ";
    std::cin.getline(p.name, 51);
    std::cout << "Diagnosis: ";
    std::cin.getline(p.diagnosis, 21);
    std::cout << "Stay: ";
    std::cin >> p.stay;
    return;
}

void printPatient(Patient p) {
    std::cout << p.name << ' ' << p.diagnosis <<' '<< p.stay << std::endl;
    return;
}

int main() {
    int n;
    char searchedDiagnosis[21];
    std::cin >> n;
    Patient patientCollection[n];
    for (int i = 0; i < n; i++)
        inputPatient(patientCollection[i]);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.getline(searchedDiagnosis, 21);
    for (int i = 0; i < n; i++) {
        if (std::strcmp(patientCollection[i].diagnosis, searchedDiagnosis) == 0)
            std::cout << patientCollection[i].name << std::endl;
    }
    Patient maxStayPatient = patientCollection[0];
    for (int i = 1; i < n; i++) {
        if (patientCollection[i].stay > maxStayPatient.stay)
            maxStayPatient = patientCollection[i];
    }
    printPatient(maxStayPatient);
    return 0;
}