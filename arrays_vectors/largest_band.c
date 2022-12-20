#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

int largest_band_better(vector<int> arr) {
    unordered_set<int> s;
    for (int a: arr) {
        s.insert(a);
    }
    int l = 0;
    for (auto a: s) {
        int p = a-1;
        if (s.find(p) == s.end()) {
            int c = 1;
            int next = a+1;
            while (s.find(next) != s.end()) {
                c++;
                next++
            }

            if (c > l) {
                l = c
            }

        }
    }
    return l;
}

vector<int> largest_band(vector<int> arr) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int p = 0;
    int q = 0;
     vector<int> res;
    vector<vector<int>> pq;
    while (q <= n-1) {
        if (arr[q] +1 == arr[q+1]) {
            q++;
        } else {
            pq.push_back({p, q});
            p = q+1;
            q = q+1;
        }
    }
    vector<int> mx = {0, 0};
    for (vector<int> v: pq) {
        if ((v[1] - v[0]) >  (mx[1] - mx[0])) mx = v;
    }
   
    for (int i = mx[0]; i <= mx[1]; i++) {
        res.push_back(arr[i]);
    }
    return res;
}


int main() {
    cout << "largest_band\n";
    vector<int> arr = largest_band({1,2,3,4,5,6,7,8,10,11});
    for (int a: arr) {
        cout << a << "\n";
    }
    return 0;
}