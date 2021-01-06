#include<iostream>
using namespace std;

int main() {
    char str[26];
    cin.getline(str, 26);
    int i=0;
    while(str[i]!='\0') {
        if(str[i]==' ')
            cout<<'\n';
        else
            cout<<str[i];
        i++;
    }
    return 0;
}
