#include <iostream>

bool evenSetBits(int a, bool controlBit = false) {
    if (a) {
        if (a & 1 == 1)
            controlBit = !controlBit;
        a >>= 1;
        return evenSetBits(a, controlBit);
    }
    else
        return !controlBit;
}


int main() {
    int numArray[90];
    for (int i = 0; i < 90; i++)
        std::cin >> numArray[i];
    for (int i = 0; i < 90; i++)
        std::cout << evenSetBits(numArray[i]) << std::endl;
    return 0;
}