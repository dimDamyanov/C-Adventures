#include <iostream>

float pow(float a, int n) {
    if (n == 0)
        return 1;
    else return a * pow(a, n-1);
}


int main() {
    float a, b, c;
    int k, p, r;
    std::cin >> a >> b >> c;
    std::cin >> k >> p >> r;
    std::cout << pow(a+b, k) / (pow(a, p) - pow(c, r)) << std::endl;
    return 0;
}