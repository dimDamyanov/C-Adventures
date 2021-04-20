#include <iostream>

void inputArray(int *array, int n) {
    if (n == 0)
        return;
    
    std::cout << "value= ";
    std::cin >> array[n - 1];
    inputArray(array, n-1);
}


int sumElements(int *array, int p, int q) {
    int sum = 0;
    for (int i = p; i <= q; i++)
        sum += array[i];
    
    return sum;
}   

int findLongest(int *array, int n, int i, int p, int q, int j=0) {
    if (j == n)
        return j-1;
    int sum = sumElements(array, i, j);
    if (sum >= p && sum <= q)
        return findLongest(array, n, i, p, q, j+1);
    else
        return j-1;
}

void printElements(int *array, int p, int q) {
    for (int i = p; i <= q; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}

void printSuborders(int *array, int n, int p, int q, int i=0) {
    if (i == n)
        return;
    int ind = findLongest(array, n, i, p, q);
    if (ind != -1)
        printElements(array, n, ind);
    printSuborders(array, n , p, q, i+1);
}

int main() {
    int k, p, q;
    std::cout << "k= ";
    std::cin >> k;
    int array[k];
    inputArray(array, k);
    
    std::cout << "p= ";
    std::cin >> p;
    std::cout << "q= ";
    std::cin >> q;

    // int i_, j_;
    // for (int i = 0; i < k; i++) {
    //     i_ = j_ = -1;
    //     for (int j = i+1; j < k; j++) {
    //         int sum = sumElements(array, i, j);
    //         if (sum >= p && sum <= q) {
    //             i_ = i;
    //             j_ = j;
    //         }
    //     }
    //     if (i_ >= 0 && j_ > 0)
    //         printElements(array, i_, j_);
    // }

    printSuborders(array, k, p, q);

    return 0;
}