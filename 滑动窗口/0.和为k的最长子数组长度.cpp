// https://www.nowcoder.com/questionTerminal/36fb0fd3c656480c92b569258a1223d5/
// 题解：滑动窗口，map<sum,idx>表示nums[0,idx]的和为sum，故nums[i,j] = k = map[sum] - map[sum - k];
#include<bits/stdc++.h>
using namespace std;

int maxLength(vector<int> &nums, int k) {
    int res = 0;
    int n = nums.size(), sum = 0;
    map<int, int> mps; // <sum,idx>
    mps.insert(make_pair(0,-1)); // init status, only one elements.
    
    for(int i = 0; i < n; i++) {
        sum += nums[i];
        
        if(mps.find(sum - k) != mps.end()) {
            res = max(res, i - mps[sum - k]);
        } else {
            mps.insert(make_pair(sum, i));
        }
    }
    
    return res;
}

int main()
{
    int n, k, temp, len;
    vector<int> nums;

    while(cin >> n >> k && n > 0) {
        for(int i = 0; i < n; i++) {
            cin >> temp;
            nums.push_back(temp);
        }
        
        len = maxLength(nums, k);
        cout << len << endl;
    }
    
    return 0;
}

/*
5 0
1 -2 1 1 1

3
*/
