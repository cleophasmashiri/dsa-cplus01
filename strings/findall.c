#include <string>
#include <iostream>


using namespace std;

void findAll(string s, string a) {
    int i = 0;
    while (i > -1) {
        i = s.find(a, i+1);
        cout<<"Found at:"<<i<<"\n";
    }
}

int main() {
    string s="Enter word to find to and.";
    string a="to";
    cout << "Enter text\n";
    cin >> s;
    cout << "Enter word to find";
    cin >>a;
    findAll(s, a);
    return 0;
}