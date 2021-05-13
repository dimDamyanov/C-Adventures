#include <iostream>
#include <cmath>
using namespace std;
 
void calculateDistance(int x1, int y1, int x2, int y2, float &result);
 
void inputPoints(int *x_values, int *y_values, int n) {
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << "= ";
        cin >> *(x_values + i);
        cout << "y" << i + 1 << "= ";
        cin >> *(y_values + i);
    }
}
 
void printDistances(int *x_values, int *y_values, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            float distance;
            calculateDistance(*(x_values + i), *(y_values + i), *(x_values + j), *(y_values + j), distance);
            cout << "(x" << i + 1 << ", y" << i + 1 << ") -> (x" << j + 1 << ", y" << j + 1 << ")= " << distance << endl;
        }
    }
}
 
void calculateDistance(int x1, int y1, int x2, int y2, float &result) {
    result = sqrt(ceil(pow((x2-x1), 2)) + ceil(pow((y2-y1), 2)));
}
 
int main() {
    int n;
    cout << "n= ";
    cin >> n;
 
    int x_values[n], y_values[n];
    inputPoints(x_values, y_values, n);
    printDistances(x_values, y_values, n);
 
    return 0;
}
 
