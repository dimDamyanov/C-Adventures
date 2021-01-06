#include<iostream>
using namespace std;

int main() {
    char str[71];
    cin>>str;
    int i=0;
    while(str[i]!='\0') {
        for(int j=0;j<i;j++) {
            if(str[j]==str[i]) {
                cout<<str[j]<<' '<<j<<' '<<i<<endl;
                return 0;
            }
        }
        i++;
    }
    cout<<"No"<<endl;
    return 0;
}
