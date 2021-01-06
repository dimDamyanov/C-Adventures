#include<iostream>
using namespace std;

int main() {
    char str[21];
    cin>>str;
    int i=0, n=0;
    while(str[i]!='\0') {
        if(str[i]>='0'&&str[i]<='9')
            n++;
        i++;
    }
    cout<<n<<endl;
    return 0;
}
