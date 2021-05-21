#include <iostream>
#include <fstream>
#include <cstring>

struct Book {
    char title[20];
    char author[20];
    float price;
    char ISBN[14];
};

int main() {
    int n;
    std::cout << "Count of the books: ";
    std::cin >> n;
    std::fstream file;
    file.open("file_1.txt", std::ios::trunc | std::ios::in | std::ios::out);

    Book book;
    for (int i = 0; i < n; i++)  {
        std::cin.ignore();
        std::cout << "Book(" << i+1 << "/" << n << "):\n";
        std::cout << "Title: ";
        std::cin.getline(book.title, 20);
        std::cout << "Author: ";
        std::cin.getline(book.author, 20);
        std::cout << "Price: ";
        std::cin >> book.price;
        std::cin.ignore();
        std::cout << "ISBN: ";
        std::cin.getline(book.ISBN, 14);

        file << book.title << ",";
        file << book.author << ",";
        file << book.price << ",";
        file << book.ISBN << "\n";
    }
    file.seekg(0);
    char price[10];

    char isbn[14];
    std::cout << "Enter ISBN to search: ";
    std::cin.getline(isbn, 14);

    for (int i = 0; i < n; i++) {
        file.getline(book.title, 20, ',');
        file.getline(book.author, 20, ',');
        file.getline(price, 10, ',');
        book.price = (float)std::strtod(price, NULL);
        file.getline(book.ISBN, 14);
        
        if (strcmp(isbn, book.ISBN) == 0) {
            std::cout << book.title << " " << book.author << " " << book.price << " " << book.ISBN << "\n";
            break;
        }
    }
    file.close();

    return 0;
}