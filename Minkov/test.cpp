#include <iostream>


void inputArray(int *array, int n, int i=0) {
    if (i==n)
        return;
    std::cout << "a["<< i << "]= ";
    std::cin >> array[i];

    return inputArray(array, n, i+1);
}

// void printElements(int *array, int p, int q) {
//     for (int i = p; i <= q; i++)
//         std::cout << array[i] << " ";
//     std::cout << std::endl;
// }

void printElementsRec(int *array, int p, int q) {
    if (p-1 == q) {
        std::cout << std::endl;
        return;
    }
    std::cout << array[p] << " ";
    printElementsRec(array, p+1, q);
}

// int sumElements(int *array, int p, int q) {
//     int sum = 0;
//     for (int i = p; i <= q; i++)
//         sum += array[i];
    
//     return sum;
// }

int sumElementsRec(int *array, int p, int q) {
    if (p-1 == q)
        return 0;
    
    return array[p] + sumElementsRec(array, p+1, q);
}

int findLongest(int *array, int n, int i, int p, int q, int j=1) {
    if (i+j == n)
        return i+j-1;
    
    int sum = sumElementsRec(array, i, i+j);
    if (sum >= p && sum <= q)
        return findLongest(array, n, i, p, q, j+1);
    else
        return i+j-1;
}

// void printSuborders(int *array, int n, int p, int q) {
//     for (int i = 0; i < n; i++) {
//         int ind = findLongest(array, n, i, p, q);
//         if (ind != 0)
//             printElements(array, i, ind);
//     }    
// }

void printSubordersRec(int *array, int n, int p, int q, int i=0) {
    if (i == n)
        return;
    int ind = findLongest(array, n, i, p, q);
    if (ind != i) {
        printElementsRec(array, i, ind);
    }
        
    
    printSubordersRec(array, n, p, q, i+1);
}

int main() {
    int n, p, q;
    std::cout << "n= ";
    std::cin >> n;
    int array[n];
    inputArray(array, n);
    std::cout << "p= ";
    std::cin >> p;
    std::cout << "q= ";
    std::cin >> q;
    
    printSubordersRec(array, n, p, q);
    return 0;
}