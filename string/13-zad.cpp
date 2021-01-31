#include<iostream>
using namespace std;

int main() {
    char str[81];
    cin.getline(str, 81, '.');
    int i=0, n=1;
    while(str[i]!='\0'){
        if(str[i]==' ')
            n++;
        i++;
    }
    cout<<n<<endl;
    return 0;
}
