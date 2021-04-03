#include <iostream>

int numlen(int a) {
    int i = 0;
    while (a) {
        a /= 10;
        i++;
    }
    return i;
} 

int strlen(char str[]) {
    int i = 0;
    while (str[i] != '\0')
        i++;
    
    return i;
}

void num_to_str(int a, char str[]) {
    int i = 0;
    while (a) {
        str[i] = (char) (a % 10 + 48);
        a /= 10;
        i++;
    }
    str[i] = '\0';
    return;
}

void reverse_str(char str[]) {
    int strLen = strlen(str);
    char str1[strLen];
    for (int i = 0; i < strLen; i++)
        str1[i] = str[i];
    for (int i = 0; i < strLen; i++)
        str[i] = str1[strLen - i - 1];
    return;
}

int main() {
    int a; 
    std::cin >> a;
    char str_num[numlen(a) + 1];
    int i = 0;
    num_to_str(a, str_num);
    reverse_str(str_num);
    std::cout << str_num << std::endl;
    return 0;
}