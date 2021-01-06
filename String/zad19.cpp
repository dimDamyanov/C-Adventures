#include<iostream>
using namespace std;

int main() {
    char str[101], longest[11];
    cin.getline(str, 101);
    int i=0, max_len=0, current_len=0;
    while(str[i]!='\0') {
        while(str[i]!=' '&&str[i]!='\0') {
            i++;
            current_len++;
        }
        if(current_len>max_len) {
            max_len = current_len;
            for(int j=i-max_len;j<i;j++) {
                longest[j-(i-max_len)] = str[j];
                /*if(j==i-1)
                    longest[j-(i-max_len)+1] = '\0';*/
            }
        }
        current_len=0;
        if(str[i]!='\0')
            i++;
    }
    cout<<longest<<endl;
    return 0;
}
