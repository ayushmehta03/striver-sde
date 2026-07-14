#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int, int> freqCnt(vector<int>& nums) {
    unordered_map<int, int> freq;

    for (int num : nums) {
        freq[num]++;
    }

    return freq;
}

int main() {
    vector<int> nums = {1, 2, 2, 1, 3, 2, 3};

    unordered_map<int, int> ans = freqCnt(nums);

    for (auto it : ans) {
        cout << it.first << " : " << it.second << endl;
    }

    return 0;
}