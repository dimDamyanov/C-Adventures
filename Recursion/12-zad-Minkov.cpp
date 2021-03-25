#include <iostream>

void sumToNegative(int *a, int n, int *sum) {
    if (*(a + n - 1) < 0) {
        return;
    }
    else if (n == 0) {
        std::cout << "No negatives in array" << std::endl;
    }
    else {
        *sum += *(a + n - 1);
        sumToNegative(a, n-1, sum);
    }
}


void inputArray(int *a, int n ) {
    if (n == 0) {
        return;
    }
    else {
        std::cout << "a[" << n - 1 << "]= ";
        std::cin >> *(a + n -1);
        inputArray(a, n-1);
    }
}

int main() {
    int a[5];
    inputArray(a, 5);
    int sum = 0;
    sumToNegative(a, 5, &sum);
    std::cout << sum << std::endl; 
    return 0;
}