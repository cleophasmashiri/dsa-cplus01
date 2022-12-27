#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

void subsequence(string s, string t, vector<string> &v) {
    if (s.length() == 0) {
        v.push_back(t);
        return;
    }
    string x = s.substr(1);
    subsequence(x, t+s[0], v);
    subsequence(x, t, v);
}
bool comparator(string s1, string s2) {
    if (s1.length() == s2.length()) {
        return s1 < s2;
    } else {
        return s1.length() < s2.length();
   }
}
 
int main() {
    cout<<"subsequence"<<endl;
    vector<string> v;
    string s = "abc";
    string x = "";
    subsequence(s, x, v);
    sort(v.begin(), v.end(), comparator);
    for (string s1: v) cout<<s1<<endl;
    return 0;
}