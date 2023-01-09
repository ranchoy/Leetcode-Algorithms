// 题意：判断区间是否有重叠，若存在返回false，否则返回true。
#include<bits/stdc++.h>
using namespace std;

bool is_legal_sequence(vector<vector<int>> &nums) {
    int n = nums.size();
    
    // 按照[left,right]区间小到大划分，先比较left，再比较right。
    sort(nums.begin(), nums.end(), [&](vector<int> &a, vector<int> &b) {
        if(a[0] != b[0]) return a[0] < b[0];
        return a[1] < b[1];
    });
    
    for(int i = 1; i < n; i++) {
        if(nums[i][0] > nums[i-1][0] && nums[i][0] < nums[i-1][1]) {
            return false;
        }
    }
    
    return true;
}

int main()
{
    vector<vector<int>> nums = {{1,2},{3,5},{4,6},{7,8}};
    bool is_legal = is_legal_sequence(nums);
    
    cout << is_legal << endl;
    return 0;
}
