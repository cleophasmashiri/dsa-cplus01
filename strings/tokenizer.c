#include <string>
#include <cstring>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

char *tokeniser(char *s, char d) {
    static char *x = NULL;
    if (s != NULL) x = s;
    if (x == NULL) return NULL;
    char *t = new char[strlen(x)+1];
    int i = 0;
    for (; x[i]!='\0'; i++) {
        if (x[i] == d) {
            t[i] = '\0';
            x += i+1;
            return t;
        } else {
            t[i] = x[i]; 
        }
    } 
    t[i] = '\0';
    x = NULL;
    return t;
}

int main()
{

    char s[1000];
    cin.getline(s, 1000);
    char *tt = tokeniser(s, ' ');
    while (tt!=NULL) {
        cout<<tt<<endl;
        tt = tokeniser(NULL, ' ');
    }
    //cout << t<<endl;
    // using strtok
    // char s[1000];
    // cin.getline(s, 1000);

    // cout << strtok(s, " ")<<endl;
    // cout << strtok(NULL, " ")<<endl;
    // cout << strtok(s, " ")<<endl;
    // cout << strtok(s, " ")<<endl;

    // cout << "Tokenizer"<<endl;
    // string s;
    // getline(cin, s);
    // stringstream ss(s);
    // string t;
    // vector<string> tt;
    // while (getline(ss, t, ' '))
    // {
    //     tt.push_back(t);
    // }

    // for (auto x: tt) {
    //     cout <<x<<endl;
    // }
}