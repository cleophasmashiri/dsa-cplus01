#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

string compressString(const string &str)
{
    // aaaabcccccaaa
    // a4bc5a3
    char b = str[0];
    int c = 0;
    int p = 0, q = 0, n = str.length();
    string s = "";
    while (q < n)
    {
        if (str[p] == str[q])
        {
            q++;
            c++;
        }
        else
        {
            s += b + to_string(c);
            b = str[q];
            p = q;
            c = 0;
        }
    }
    return (s.length() < str.length() ? s : str);
}
int main()
{
    string s = "aaaabbcdeee";
    cout << "Compress: " << s << endl;
    cout << compressString(s) << endl;
    return 0;
}
