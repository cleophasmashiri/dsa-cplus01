#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

pair<int,int> minDifference(vector<int> a,vector<int> b) {
    int n = a.size() + b.size();
    pair<int, int> pp[n]; 
    for (int i = 0; i < a.size(); i++) {
        pp[i].first = a[i];
        pp[i].second = 0;
    }
    for (int i = a.size(); i < n; i++) {
        pp[i].first = b[i];
        pp[i].second = 1;
    }
    sort(pp, pp+n);
    int c = 0;
    pair<int, int> d;
    for (int i = 0; i < n;) {
        int x = i+1;
        while (x < n) {
            if (pp[i].second!=pp[x].second) {
                x++;
            }
        }
       // if (abs(pp[i].first - pp[x].first) < abs[pp[]]) 
    }
    return d;
}

int main() {
    cout << "min diff";
    return 0;
}