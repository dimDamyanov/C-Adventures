#include <iostream>


int sumElements(int *array, int p, int q) {
    int sum = 0;
    for (int i = p; i <= q; i++)
        sum += array[i];
    
    return sum;
}   

void printElements(int *array, int p, int q) {
    for (int i = p; i <= q; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}

int main() {
    int k, p, q;
    std::cout << "k= ";
    std::cin >> k;
    int array[k];
    for (int i = 0; i < k; i++) {
        std::cout << "a[" << i << "]= ";
        std::cin >> array[i];
    }
    
    std::cout << "p= ";
    std::cin >> p;
    std::cout << "q= ";
    std::cin >> q;

    for (int i = 0; i < k; i++) {
        for (int j = i+1; j < k; j++) {
            int sum = sumElements(array, i, j);
            if (sum >= p && sum <= q)
                printElements(array, i, j);
        }
    }

    return 0;
}