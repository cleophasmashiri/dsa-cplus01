#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> three_sum(vector<int> arr, int target) {
    int n = arr.size();
    vector<vector<int>> res;
    sort(arr.begin(), arr.end());
    for (int i = 0; i <= n-3; i++) {
       
        int j = i+1;
        int k = n-1;
        while (j < k) {
            int sum = arr[i];
            sum += arr[j];
            sum += arr[k];
            if (sum == target) {
                res.push_back({arr[i], arr[j], arr[k]});
                j++;
                k--;
            } else if (sum > target) {
                k--;
            } else {
                j++;
            }
        }
        
    }
    return res;
}

int main() {
    cout << "Hello\n";
    vector<vector<int>> res = three_sum({1,2,3,4,5,6,7,8,9,15}, 18);
    for (vector<int> v: res) {
        cout << "[";
        for (int n: v) {
            cout << to_string(n) << ","; 
        }
        cout << "]\n";
    }
    return 0;
}



