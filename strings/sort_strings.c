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

int convertStrInt(string s) {
    int a = 0;
    int p = 1;
    for (int i = s.length()-1; i>=0; i--) {
        a += ((s[i]-'0')) *p;
        p *= 10;
    }
    return a;
}

bool numericSort(pair<string, string> p1, pair<string, string> p2) {
    int x1 = convertStrInt(p1.first);
    int x2 = convertStrInt(p2.first);
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
        p.first = getKey(s, col);
        p.second = s;
        pp.push_back(p);
        // cout<<"Pairs: key="<<p.first<<" value="<<p.second<<endl;
    }
    if (plusOrder && isNumeric) sort(pp.begin(), pp.end(), numericSort);
    // else if ((!plusOrder) && isNumeric) sort(pp.begin(), pp.end(), numericSortDsc);
    // else if ((plusOrder) && !isNumeric) sort(pp.begin(), pp.end(), lexSort);
    // else if ((!plusOrder) && !isNumeric) sort(pp.begin(), pp.end(), lexSortDsc);
    vector<string> res;
    for (pair<string, string> y: pp) res.push_back(y.second);
    return res;
}

int main() {
    // vector<string> ss = {"1 4 3", "1 1 3", "1 2 3"};
    // cout<<"Original String"<<endl;
    //  for (string s: ss) 
    //     cout<<s<<endl;
    // vector<string> res = sortStrings(ss, true, 2, true);
    // cout<<"Result String"<<endl;
    // for (string s: res) 
    //     cout<<s<<endl;
    string s = "12304";
    pair<string, string> p1;
    p1.first = "1";
    p1.second = "2";
    pair<string, string> p2;
    p2.first = "10";
    p2.second = "20";
    cout<<s<<" as numericSort 1,4:"<<numericSort(p2,p1)<<endl;
    return 0;
}
