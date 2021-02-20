#include <iostream>
#include <cmath>

bool IsPrime(int a, int b = 2, int c = 0) {
    if (a <= 1)
        return false;
    else if (a == 2)
        return true;
    else {
        if (c == 0)
            c = ceil(sqrt(a));
        if (b > c)
            return true;
        else if (a % b == 0)
            return false;
        else
            return IsPrime(a, b+1, c);
    }
}


int main() {
    int p, q;
    std::cout << "p= ";
    std::cin >> p;
    std::cout << "q= ";
    std::cin >> q;
    for (int i = p; i <= q; i++) {
        if (IsPrime(i))
            std::cout << i << std::endl;
    }
    return 0;
}