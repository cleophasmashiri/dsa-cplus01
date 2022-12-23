#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

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

bool numericSort(pair<string, string> p1, pair<string, string> p2) {
    // int x1 = (int)p1;
    // int x2 = (int)p2;
    return p1 < p2;
}
bool numericSortDsc(pair<string, string> p1, pair<string, string> p2) {
    // int x1 = (int)p1;
    // int x2 = (int)p2;
    return  p2 < p1;
}
bool lexSort(pair<string, string> p1, pair<string, string> p2) {
    return p1 < p2;
}
bool lexSortDsc(pair<string, string> p1, pair<string, string> p2) {
    return  p2 < p1;
}
string getKey(string s, int col) {
    char *t = tokeniser((char *)s.c_str(), ' ');
    int c = col;
    while (t!=NULL)
    {
        if (c == 1) {
            return t;
        }
        t = tokeniser(NULL, ' ');
        c--;
    }
    return "";
}
vector<string> sortStrings(vector<string> ss, bool plusOrder, int col, bool isNumeric) {
    int n = ss.size();
    vector<pair<string, string>> pp; 
    // s1 = "10 34 34", col = 1;
    for (string s: ss) {
        pair<string, string> p;
        char *t = tokeniser((char *)s.c_str(), ' ');
        p.second = s;
        int c = 1;
        while (t!=NULL)
        {
            if (col == c) {
                p.first = t;
            }
            t = tokeniser(NULL, ' ');
            c++;
        }
        pp.push_back(p);
    }
    //if (plusOrder && isNumeric) sort(pp.begin(), pp.end(), numericSort);
    // else if ((!plusOrder) && isNumeric) sort(pp.begin(), pp.end(), numericSortDsc);
    // else if ((plusOrder) && !isNumeric) sort(pp.begin(), pp.end(), lexSort);
    // else if ((!plusOrder) && !isNumeric) sort(pp.begin(), pp.end(), lexSortDsc);
    vector<string> res;
    //for (pair<string, string> y: pp) res.push_back(y.second);
    return res;
}

int main() {
    cout<<"Sort Strings"<<getKey("12 13, 150, 5686", 4)<<endl;
    return 0;
}
