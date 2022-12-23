#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

bool issubset(string s, string a) {
   int p = s.length()-1, q = a.length()-1;
   while (p >= 0 and q >= 0) {
    if (s[p] == a[q]) {
        p--;
        q--;
    } else {
        p--;
    }
   } 
   if (q ==-1) return true;
   return false;
}


int main() {
   cout<<"Counts: "<<issubset("baba", "ab")<<endl;
    return 0;
}

