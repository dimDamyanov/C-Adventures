#include <iostream>


void inputArray(int *a, int n, int ind=0) {
    if (n == 0) {
        return;
    }
    else {
        std::cout << "a[" << ind << "]= ";
        std::cin >> *(a + n -1);
        inputArray(a, n-1, ind+1);
    }
}

void sumToNegative(int *a, int n, int *neg, int *sum) {
    if (n == 0) {
        return;
    }
    else if (*(a + n - 1) < 0) {
        *neg = *(a + n - 1);
        return;
    }
    else {
        *sum += *(a + n - 1);
        sumToNegative(a, n-1, neg, sum);
    }
}

int main() {
    int n, sum=0, neg=0;
    std::cout << "n= ";
    std::cin >> n;
    int a[n];
    inputArray(a, n);
    sumToNegative(a, n, &neg, &sum);
    if (neg<0) {
        std::cout << neg << std::endl;
        std::cout << sum << std::endl;
    }
    else
        std::cout << "No negatives in array" << std::endl;
    return 0;
}