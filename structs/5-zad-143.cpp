#include <iostream>
#include <limits>

struct Employee {
    char name[25];
    char ucn[11];
    char position[20];
    float wage;
};

void inputEmployee(Employee &e) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Name: ";
    std::cin.getline(e.name, 25);
    std::cout << "UCN: ";
    std::cin.getline(e.ucn, 11);
    std::cout << "Position: ";
    std::cin.getline(e.position, 20);
    std::cout << "Wage: ";
    std::cin >> e.wage;
}

void printEmployee(Employee e) {
    std::cout << e.name << ' ';
    std::cout << e.ucn << ' ';
    std::cout << e.position << ' ';
    std::cout << e.wage << std::endl;
}

int main() {
    int n;
    std::cin >> n;
    Employee employeesCollection[n];
    for (int i = 0; i < n; i++)
        inputEmployee(employeesCollection[i]);
    for (int i = 0; i < n; i++) {
        if (employeesCollection[i].wage < 700)
            std::cout << employeesCollection[i].name << std::endl;
    }
    return 0;
}