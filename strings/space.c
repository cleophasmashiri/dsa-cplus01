#include <string>
#include <cstring>
#include <iostream>

using namespace std;

void replace(char *s) {
    int c = 0;
   
    for (int i = 0; s[i]!='\0'; i++) {
        if (s[i] == ' ') c++;
    }

    int n = strlen(s);
    int m = n + 2*c;
    s[m--] = '\0';
    for (int i = n-1; i >= 0; i--) {
        if (s[i] == ' ') {
            s[m--] = '0';
            s[m--] = '2';
            s[m--] = '%';
        } else {
            s[m--] = s[i];
        }
    }

}

int main() {
    cout << "Enter words\n";
    char s[1000];
    cin.getline(s, 1000);
    replace(s);
    cout <<s<<endl ;
    return 0;
}

