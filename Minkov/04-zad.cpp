#include <iostream>
#include <cmath>
using namespace std;
 
void calculateArea(int a, int b, int c, float &area);
 
void inputTriangles(int *a_values, int *b_values, int *c_values, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Triangle #" << i + 1 << endl;
        cout << "a= ";
        cin >> *(a_values + i);
        cout << "b= ";
        cin >> *(b_values + i);
        cout << "c= ";
        cin >> *(c_values + i);
    }
}
 
void getGreatestArea(int *a_values, int *b_values, int *c_values, int n) {
    int max_ind;
    float max_area;
    max_ind = 0;
    calculateArea(*(a_values), *(b_values), *(c_values), max_area);
    for (int i = 1; i < n; i++) {
        float current_area;
        calculateArea(*(a_values + i), *(b_values + i), *(c_values + i), current_area);
        if (current_area > max_area) {
            max_ind = i;
            max_area = current_area;
        }
    }
 
    cout << "Greatest Area: Triangle#" << max_ind + 1 << endl;
    cout << "a= " << *(a_values + max_ind) << endl;
    cout << "b= " << *(b_values + max_ind) << endl;
    cout << "c= " << *(c_values + max_ind) << endl;
    cout << "Area= " << max_area << endl;
}
 
void calculateArea(int a, int b, int c, float &area) {
    area = sqrt(((a + b + c)/2) * (((a + b + c)/2) - a) * (((a + b + c)/2) - b) * (((a + b + c)/2) - c));
}
 
int main () {
    int n;
    cout << "n= ";
    cin >> n;
 
    int a_values[n], b_values[n], c_values[n];
    inputTriangles(a_values, b_values, c_values, n);
    getGreatestArea(a_values, b_values, c_values, n);
 
    return 0;
}
