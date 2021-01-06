#include<iostream>
#include<cstring>
using namespace std;

int main() {
    char str[51];
    char reverse_str[51];
    cin>>str;
    int str_len=strlen(str);
    for(int i=0;i<str_len;i++)
        reverse_str[str_len-i-1] = str[i];
    reverse_str[str_len]='\0';
    if(strcmp(str, reverse_str)==0)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}
