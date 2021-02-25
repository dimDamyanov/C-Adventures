#include <iostream>
#include <limits>

struct Book {
    char title[20];
    char author[20];
    float prices[3];
    char ISBN_num[7];
};

void inputBook(Book &b) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Title: ";
    std::cin.getline(b.title, 20);
    std::cout << "Author: ";
    std::cin.getline(b.author, 20);
    for (int i = 0; i < 3; i++) {
        std::cout << "Price " << i + 1 << ": ";
        std::cin >> b.prices[i];
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "ISBN: ";
    std::cin >> b.ISBN_num;
    return;
}

