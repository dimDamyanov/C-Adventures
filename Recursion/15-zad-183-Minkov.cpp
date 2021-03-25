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

void evenElementsAverage(int *a, int n, int *sum, int *count) {
    if (n == 0)
        return;
    if (*(a + n - 1) % 2 == 0) {
        *sum += *(a + n - 1);
        *count += 1;
    }
    evenElementsAverage(a, n - 1, sum, count);
}

int main() {
    int n, sum=0, count=0;
    std::cout << "n= ";
    std::cin >> n;
    int a[n];
    inputArray(a, n);
    evenElementsAverage(a, n, &sum, &count);
    std::cout << sum << std::endl;
    std::cout << count << std::endl;
    std::cout << "Even elements average= " << (float) sum / count << std::endl;
    return 0;
}