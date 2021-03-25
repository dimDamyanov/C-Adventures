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

void minAndmaxElements(int *a, int n, int *min, int *max) {
    if (n==0)
        return;
    if (*(a + n - 1) < *min)
        *min = *(a + n - 1);
    if (*(a + n - 1) > *max)
        *max = *(a + n - 1);
    minAndmaxElements(a, n-1, min, max);
}

int main() {
    int n, min, max;
    std::cout << "n= ";
    std::cin >> n;
    int a[n];
    inputArray(a, n);
    min = max = *a;
    minAndmaxElements(a, n, &min, &max);
    std::cout << max << std::endl;
    std::cout << min << std::endl;
    std::cout << max - min << std::endl;
    return 0;
}