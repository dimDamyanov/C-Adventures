#include<iostream>
#include<cstring>
using namespace std;

int main() {
    char str1[21];
    char str2[6];
    cin>>str1;
    cin>>str2;
    int n=0;
    for(int i=0;i<strlen(str1);i++) {
        int j=0;
        if(str1[i]==str2[j]) {
            int k=i;
            while(str1[i]==str2[j]&&j<strlen(str2)) {
                j++;
                i++;
            }
            if(j==strlen(str2)) {
                n++;
                i--;
            }
            else
                i=k;
        }
    }
    cout<<n<<endl;
    return 0;
}
