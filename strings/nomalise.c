#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

string normalize(string sentence) {
    string copy = sentence;
    int n = copy.length();
    for (int i = 0; i < n; i++) {
        if ((i == 0) or (copy[i-1] = ' '))
            copy[i] = toupper(copy[i]);
        else 
            copy[i] = tolower(copy[i]);
    }
    return copy;
}

int main() {
    cout<<"normalize: "<<normalize("This is SO MUCH FUN!")<<endl;
    return 0;
}