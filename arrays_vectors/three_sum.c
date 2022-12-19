#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    cout << "Hello";
    return 0;
}

vector<vector<int>> three_sum(vector<int> arr, int target) {
    int n = arr.size();
    vector<vector<int>> res;
    sort(arr, arr.begin(), arr.end());
    for (int i = 0; i < n-3; i++) {
        int sum = arr[i];
        int j = i+1;
        int k = n-1;
        while (j < k) {
            sum += arr[j];
            sum += arr[k];
            if (sum == target) {
                res.push_back({arr[i], arr[j], arr[k]});
            } else 
        }
        
    }
}

