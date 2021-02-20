#include <iostream>

int factorial(int n) {
    if (n == 1)
        return 1;
    else return n * factorial(n-1);
}

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << (factorial(a) + factorial(b)) / (b-a) << std::endl;
    return 0;
}