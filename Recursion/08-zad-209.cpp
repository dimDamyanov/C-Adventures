#include <iostream>

int gcd(int a, int b) {
    if (b)
        return gcd(b, a % b);
    else return a; 
}

int main() {
    int n;
    std::cin >> n;
    int numArr[n];
    for (int i = 0; i < n; i++)
        std::cin >> numArr[i];
    int currentGCD = numArr[0]; 
    for (int i = 1; i < n; i++)
        currentGCD = gcd(currentGCD, numArr[i]);
    std::cout << currentGCD << std::endl;
    return 0;
}