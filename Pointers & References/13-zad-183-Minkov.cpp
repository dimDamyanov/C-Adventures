#include <iostream>


void inputArray(int *a, int n, int ind=0) {
    if (n == 0)
        return;
    else {
        std::cout << "a[" << ind << "]= ";
        std::cin >> *(a + n -1);
        inputArray(a, n-1, ind+1);
    }
}

void positiveSumAndNegativeCount(int *a, int n, int *posSum, int *negCount) {
    if (n == 0)
        return;
    if (*(a + n - 1) > 0)
        *posSum += *(a + n - 1);
    else if (*(a + n - 1) < 0)
        *negCount += 1;
    positiveSumAndNegativeCount(a, n-1, posSum, negCount);
}

int main() {
    int n, posSum=0, negCount=0;
    std::cout << "n= ";
    std::cin >> n;
    int a[n];
    inputArray(a, n);
    positiveSumAndNegativeCount(a, n, &posSum, &negCount);
    std::cout << posSum << std::endl;
    std::cout << negCount << std::endl;
    return 0;
}