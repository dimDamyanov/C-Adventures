#include <iostream>

void inputArray(int a[], int n, int c = 0) {
    if (c >= n)
        return;
    else
        std::cout << "a[" << c << "]= ";
        std::cin >> a[c];
        return inputArray(a, n, c + 1);
}

bool contains(int a[], int n, int x, int c = 0) {
    if (c >= n)
        return false;
    else
        if (a[c] == x)
            return true;
        else
            return contains(a, n, x, c + 1);
}

int main() {
    int n, x;
    std::cout << "n= ";
    std::cin >> n;
    int a[n];
    inputArray(a, n);
    std::cout << "x= ";
    std::cin >> x;
    std::cout << contains(a, n, x) << std::endl;
    return 0;
}