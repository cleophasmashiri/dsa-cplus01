#include <iostream>
#include <vector>

using namespace std;

int maxRight(int i, vector<int> arr) {
    int n = arr.size();
    if (i == n-1) return arr[i];
    int mx = arr[i];
    for (int j = i+1; j < n; j++) {
        mx = max(mx, arr[j]);
    }
    return mx;
}
int maxLeft(int i, vector<int> arr) {
    int n = arr.size();
    if (i == 0) return arr[0];
    int mx = arr[i];
    for (int j = i-1; j >= 0; j--) {
        mx = max(mx, arr[j]);
    }
    return mx;
}

int waterBrute(vector<int> arr) {
    int t = 0;
    int n = arr.size();
    int w = 0;
    for (int i = 0; i < n; i++ ) {
        w += (min(maxRight(i, arr), maxLeft(i, arr))) - arr[i];

    }
    return w;
}

int water(vector<int> arr) {
    int n = arr.size();
    vector<int> right(n, 0), left(n, 0);
    left[0] = arr[0];
    right[n-1] = arr[n-1];

    for (int i = 1; i < n-1; i++) {
        left[i] = max(left[i-1], arr[i]);
        right[n-i-1] = max(right[n-i], arr[n-i-1]);
    }
    int t = 0;
    for (int i = 0; i< n; i++) {
        t += min(left[i], right[i]) - arr[i];
    }
    return t;
    
}

int main() {
    cout << "Rain\n";
    cout << "Water total: " << water({0,1,0,2,1,0,1,3,2,1,2,1}) << "\n";
    return 0;
}
