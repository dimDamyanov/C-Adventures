#include<iostream>
using namespace std;

int main() {
    char str[81];
    cin.getline(str, 81, '.');
    int i=0, n=0, c=0;
    while(str[i]!='\0'){
        if(str[i]!=' ')
            c++;
        else {
            if(c==1)
                n++;
            c=0;
        }
        i++;
    }
    cout<<n<<endl;
    return 0;
}
