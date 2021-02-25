#include <iostream>

int factorial(int n) {
    if (n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int factorialSum(int n) {
    if (n == 1)
        return 1;
    else
        return factorial(n) + factorialSum(n - 1);
}

int main() {
    int n;
    std::cout << "n= ";
    std::cin >> n;
    std::cout << factorialSum(n) << std::endl;
    return 0;
}
