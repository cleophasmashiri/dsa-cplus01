#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubArraySum(vector<int> a) {
    int m = a[0];
    int c = a[0];
    for (int i = 1; i < a.size(); i++) {
        c = max(a[i], c+a[i]);
        m = max(m, c);  
    }
    return m;
}

int main() {
    cout << "max sub array sum: " << maxSubArraySum({-1,2,3,4,-2,6,-8,3}) << "\n";
    return 0; 
}
