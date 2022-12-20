#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minSwaps(vector<int> arr) {
    int n = arr.size();
    pair<int,int> pp[n];
    for (int i = 0; i < n; i++) {
        pp[i].first = arr[i];
        pp[i].second = i;
    }
    sort(pp, pp+n);
    vector<bool> v(n, false);

    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (pp[i].second == i or v[i] == true) {
            continue;
        }

        int node = i;
        int cycles = 0;
        while (!v[node]) {
            v[node] = true;
            int next = pp[node].secod;
            c++;
            node = next;
        }
        ans += cycles-1;
    }

    return 0;
}

int main() {
    cout << "Min Swaps: " <<  minSwaps({}) << "\n";
    return 0;
}