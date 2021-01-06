#include<iostream>
using namespace std;

int main() {
    char str[101];
    cin.getline(str, 101);
    int i=0, n=0;
    while(str[i]!='\0') {
        if(str[i]==' ') {
            while(str[i]==' ') {
                i++;
            }
            if(str[i]!='\0')
                n++;
        }
        else {
            i++;
            if(str[i]=='\0')
                n++;
        }
    }
    cout<<n<<endl;
    return 0;
}
