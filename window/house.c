#include <iostream>
#include <vector>

using namespace std;
// [1,3,2,1,4,1,3,2,1,2]
// s = 8
vector<pair<int, int>> getAreas(int sum, vector<int> h) {
    vector<pair<int, int>> pp;
    int k = 0;
    int n = h.size();
    for (int i = 0; i < n;) {
        int s = 0;
        int j = i;
        while (j < n) {
            s += h[j];
            if (s == sum) {
                pair<int, int> p;
                p.first = i;
                p.second = j;
                pp.push_back(p);
                //i++;
                j=i;
            } else {
                j++;
            }
        }
        i++;
    }
    return pp;
}

vector<pair<int, int>> getAreasPrexSum(int sum, vector<int> h) {
    int n = h.size();
    vector<int> p(n, 0);
    p[0] = h[0];
    for (int i = 1; i < n; i++) {
        p[i] = p[i-1] + h[i];
    }
    vector<pair<int, int>> pp;
    for (int i = 0; i < n; i++) {
         for (int j = i+1; j < n; j++) {
            int s = p[j] - p[i];
            if (s == sum) {
                pair<int, int> p;
                p.first = i;
                p.second = j;
                pp.push_back(p);
            }
         }
    }
    return pp;
}

int main() {
    cout<<"prefix sum"<<endl;
    vector<pair<int, int>> r = getAreasPrexSum(8,{1,3,2,1,4,1,3,2,1,1,2});
    for (pair<int, int> p: r) {
        cout<<"["<<p.first<<", "<<p.second<<"]"<<endl;
    }
    
    // h = [1,3,2,1,4, 1, 3, 2, 1, 2 ]
    // p = [1,4,6,7,11,12,15,17,18,20]
    return 0;
}