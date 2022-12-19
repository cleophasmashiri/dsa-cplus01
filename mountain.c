#include <iostream>
#include <vector>

using namespace std;

int nextPeak(int i, vector<int> nums) {
    while (nums[i] < nums[i+1] && i < nums.size()) {
        if (nums[i] > nums[i+1]) return i;
        i++;
    }
    return -1;
} 
int nextValley(int i, vector<int> nums) {
    while (nums[i] > nums[i+1] && i < nums.size()) {
        if (nums[i] < nums[i+1]) return i;
        i++;
    }
    return -1;
} 
int getValleys(vector<int>nums, m) {
    int v1 = m;
    while (v1 >=0 && nums[v1-1] < nums[v1]) {
        v1--;
    }
    int v2 = m;
    while (v2 < nums.size() && nums[v2] > nums[v2+1]) {
        v2++;
    }
    return {v1, v2};
}

int len_highest_mountain(vector<int> nums) {
    vector<int> peaks;
    int v1 = 0;
    int m = 0;
    int v2 = 0;
    while (v2 < nums.size()){
         v1 = v2;
         m = nextPeak(v2);
         v2 = nextValley(m);
        if (nums[v1] < nums[m] && nums[m] > nums[v2]) {
            peaks.push_back(m);
        } 
    }
    int mx = 0;
    for (int p: peaks) {
        vector<int> vv = getValleys(p);
        int mv = vv[0] < vv[1]? vv[0]: vv[1];
        int h = nums[p] - mv;
        if (h > nums[mx]) mx = p; 
    }
    vector<int> vv = getValleys(mx);
    int c = 0;
    for (int i = vv[0], i <= vv[1]; i++) {
        c++;
    }
    return c;
}

int main() {
    cout << "Mountain solution\n";
    return 0;
}
