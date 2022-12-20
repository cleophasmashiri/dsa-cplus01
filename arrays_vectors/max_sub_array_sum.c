#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubArraySum(vector<int> a) {
    int n = a.size();
    vector<int> s(n, 0);
    int p = 0;
    while (p < n && a[p] < 0) {
        s[p] = 0;
        p++;
    }
    int m = 0;
    for (int i = p; i < n; i++) {
        s[i] = s[i-1] + a[i];
        if (s[i] > m) m = s[i];
    }
    return m;
}

int main() {
    cout << "max sub array sum: " << maxSubArraySum({-1,2,3,4,-2,6,-8,3}) << "\n";
    return 0; 
}
