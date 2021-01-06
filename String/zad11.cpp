#include<iostream>
using namespace std;

int main() {
    char str[11];
    char chr;
    cin>>str;
    cin>>chr;
    int i=0, n=0;
    while(str[i]!='\0') {
        if(str[i]==chr)
            n++;
        i++;
    }
    cout<<n<<endl;
    return 0;
}
