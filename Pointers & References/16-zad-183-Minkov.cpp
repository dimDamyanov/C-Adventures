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

void multipleOf3Prod(int *a, int n, int *prod) {
    if (n == 0)
        return;
    else if (*(a + n - 1) % 3 == 0)
        *prod *= *(a + n - 1);
    multipleOf3Prod(a, n-1, prod);
}

int main() {
     int n, prod=1;
    std::cout << "n= ";
    std::cin >> n;
    int a[n];
    inputArray(a, n);
    multipleOf3Prod(a, n, &prod);
    std::cout << prod << std::endl;
    return 0;
}