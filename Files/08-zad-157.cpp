#include <iostream>
#include <fstream>

using namespace std;
int main() {
    ifstream inFile;
    ofstream outFile;
    inFile.open("text.txt", ios::in);
    outFile.open("out.txt", ios::out);

    char line[1000];
    while(inFile.getline(line, 1000)) {
        outFile << line;
        outFile << "\n";
    }

    inFile.close();
    outFile.close();
    return 0;
}
