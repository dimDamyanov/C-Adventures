#include<iostream>
using namespace std;

int main() {
    char str[26];
    cin>>str;
    char sym;
    int i=0, current_c=1, max_c=0;
    while(str[i+1]!='\0') {
        while(str[i]==str[i+1]) {
            i++;
            current_c++;
        }
        if(current_c > max_c) {
            max_c = current_c;
            sym = str[i];
        }
        else
            i++;
        current_c=1;
    }
    cout<<max_c<<' '<<sym<<endl;
    return 0;
}
