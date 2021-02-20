#include <iostream>


int fibonacci(int n) {
    if (n <= 1)
        return n;
    else return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    int k;
    std::cin >> k;
    int n = 0;
    while (fibonacci(n) <= k) {
        std::cout << fibonacci(n) << std::endl;
        n++;
    }
    return 0;
}