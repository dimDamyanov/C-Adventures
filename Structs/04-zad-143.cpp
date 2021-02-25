#include <iostream>
#include <limits>

struct Book {
    char title[20];
    char author[20];
    float price;
    char ISBN_num[7];
};

void inputBook(Book &b) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Title: ";
    std::cin.getline(b.title, 20);
    std::cout << "Author: ";
    std::cin.getline(b.author, 20);
    std::cout << "Price: ";
    std::cin >> b.price;
    std::cout << "ISBN: ";
    std::cin >> b.ISBN_num;
    return;
}

void printBook(Book b) {
    std::cout << b.title << ' ';
    std::cout << b.author << ' ';
    std::cout << b.price << ' ';
    std::cout << b.ISBN_num << std::endl;
    return;
}

int main() {
  int n;
  float minPrice;
  std::cin.sync_with_stdio(true);
  std::cin >> n >> minPrice;
  Book booksCollection[n];
  for (int i = 0; i < n; i++) 
      inputBook(booksCollection[i]);

  for (int i = 0; i < n; i++) {
      if (booksCollection[i].price > minPrice)
        printBook(booksCollection[i]);
  }
  return 0;
}