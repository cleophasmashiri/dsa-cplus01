#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int convertStrInt(string s) {
    int v = 0;
    int n = s.length();
    int p = 1;
    for (int i = n-1; i>=0; i--) {
        v += (s[i]-'0')*p;
        p *= 10;
    }
    return v;
}

bool compare(int n1, int n2) {
    string s1 = to_string(n1);
    string s2 = to_string(n2);
    string s1s2 = s1+s2;
    string s2s1 = s2+s1;
    int m1 = convertStrInt(s1s2);
    int m2 = convertStrInt(s2s1);
    if (m1 < m2) return true;
    return false;
}
string concatenate(vector<int> numbers){
    //complete this method and return the largest number you can form as a string
    
    sort(numbers.begin(), numbers.end(), compare);

    string s = "";
    for (int i = numbers.size()-1; i >= 0; i--) {
        s = s + to_string(numbers[i]);
    }
    return s;
    //10,11,20,30,3
    //330201110

}


int main() {
    cout<<"compare: "<<concatenate({9, 34, 7, 45, 3})<<endl;
    return 0;
}
