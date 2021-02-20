#include <iostream>

int evenIndexSum(int *arr, int n, int c = 0) {
    if (c >= n)
        return 0;
    else
        return *(arr + c) + evenIndexSum(arr, n, c + 2);
}

int main() {
    int n;
    std::cin >> n;
    int numArr[n];
    for (int i = 0; i < n; i++)
        std::cin >> numArr[i]; 
    std::cout << evenIndexSum(numArr, n) << std::endl;
    return 0;
}