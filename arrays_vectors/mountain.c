#include <iostream>
#include <vector>

using namespace std;

int len_highest_mountain(vector<int> nums) {
   int l = 0;
   int n = nums.size();
    for (int i = 1; i <= n - 2;) {
        int c = 0;
        if (nums[i-1] < nums[i] && nums[i] > nums[i+1]) {
            int j = i;
            while (j >= 1 && nums[j] > nums[j-1]) {
                j--;
                c++;
            } 
            while (i <= n-2 && nums[i] > nums[i+1]) {
                i++;
                c++;
            } 
            l = max(l, c);
        } else {
            i++;
        }
    }
    return l;
}

int main() {
    cout << "Mountain solution\n";
    vector<int> arr = {5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};
    int h = len_highest_mountain(arr);
    cout << "len_highest_mountain: " << to_string(h) << "\n";
    return 0;
}
