#include <iostream>
#include <vector>

using namespace std;

vector<int> subArray(vector<int> arr) {
    int n = arr.size();
    int s = -1;
    for (int i = 0; i < n-1; i++) {
        if (arr[i] > arr[i+1]) {
            s = i;
        }
    }
    int e = -1;
    for (int i = s; i < n-1; i++) {
        if (arr[s] >= arr[i+1]) {
            e = i;
        }
    }
    return {s,e}; 
} 
int main() {
    cout << "Sub Array\n";
    vector<int> res = subArray({1});
    for (int a: res) {
        cout << a << "\n";
    }
    return 0;
}
