#include<iostream>
using namespace std;

int main() {
    char str[101];
    cin.getline(str, 101);
    int i=0;
    while(str[i]!='\0') {
        if(str[i]==' ') {
            cout<<' ';
            while(str[i]==' ')
                i++;
        }
        else {
            cout<<str[i];
            i++;
        }
    }
}
