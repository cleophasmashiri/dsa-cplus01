#include <string>
#include <cstring>
#include <iostream>

using namespace std;

void replaceSpace(char *s)
{
    int n = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == ' ')
            n++;
    }

    int x = strlen(s) + 2 * n;

    s[x--] = '\0';
    int m = strlen(s);
    for (int i = m-1; i >= 0; i--)
    {
        if (s[i] == ' ')
        {
            s[x--] = '0';
            s[x--] = '2';
            s[x--] = '%';
        }
        else
        {
            s[x--] = s[i];
        }
    }
}

int main()
{
    char s[1000];
    cout << "Enter string" << endl;
    cin.getline(s, 1000);
    replaceSpace(s);
    cout << s << endl;
    return 0;
}