#include<iostream>
using namespace std;

int main() {
    char str[101];
    cin.getline(str, 101);
    int i=0, min_len=101, start_ind, current_len=0;
    while(str[i]!='\0') {
        if(str[i]==' ') {
            if(current_len<min_len) {
                min_len = current_len;
                start_ind = i - current_len;
                current_len = 0;
            }
            while(str[i]==' ') {
                i++;
            }
        }
        else {
            current_len++;
            i++;
        }
    }
    cout<<min_len<<' '<<start_ind<<endl;
    return 0;
}
