#include <iostream>
#include <limits>

struct Beverage {
    char name[16];
    float price;
    int weight;
    char pref;
};

void inputBeverage(Beverage &beverage) { 
    std::cout << "Name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.getline(beverage.name, 16);
    std::cout << "Price: ";
    std::cin >> beverage.price;
    std::cout << "Weight: ";
    std::cin >> beverage.weight;
    std::cout << "Prefference: ";
    std::cin >> beverage.pref;
    return;
}

void printBeverage(Beverage &beverage) {
    std::cout.width(15); std::cout << std::left << beverage.name;
    std::cout.width(8); std::cout << std::left << beverage.price;
    std::cout.width(8); std::cout << std::left << beverage.weight;
    std::cout.width(6); std::cout << std::left << beverage.pref << std::endl;
    return;
}

void printDataHeader() {
    std::cout.width(15); std::cout << std::left << "Name";
    std::cout.width(8); std::cout << std::left << "Price";
    std::cout.width(8); std::cout << std::left << "Weight";
    std::cout.width(6); std::cout << std::left << "Pref" << std::endl;
    return;
}

int main() {
    int n;
    std::cout << "n= ";
    std::cin >> n;
    Beverage beverages[n];
    for (int i = 0; i < n; i++) {
        std::cout << '(' << i + 1 << '/' << n << ")" << std::endl;
        inputBeverage(beverages[i]);
    }
    printDataHeader();
    for (int i = 0; i < n; i++) {
        printBeverage(beverages[i]);
    }
    std::cout << "Minimal Price: "; 
    float minPrice;
    std::cin >> minPrice;
    std::cout << "Beverages more expensive than " << minPrice << ':' << std::endl;
    printDataHeader();
    for (int i = 0; i < n; i++) {
        if (beverages[i].price > minPrice)
            printBeverage(beverages[i]);
    }
    
    char pref;
    std::cout << "Pref: ";
    std::cin >> pref;
    std::cout << "Beverages with preference " << pref << ':' << std::endl;
    printDataHeader();
    for (int i = 0; i < n; i++) {
        if (beverages[i].pref == pref)
            printBeverage(beverages[i]);
    }
    return 0;
}