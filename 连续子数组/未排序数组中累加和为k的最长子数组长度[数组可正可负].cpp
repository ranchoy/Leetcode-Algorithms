// https://www.nowcoder.com/questionTerminal/36fb0fd3c656480c92b569258a1223d5
// 滑动窗口，注意只有一个元素且为k的情况
#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> nums;

int main()
{
    int temp;
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        cin >> temp;
        nums.push_back(temp);
    }
    
    int mx = 0;
    int sum = 0;
    unordered_map<int, int> mp; // <sum, idx>
    mp[0] = -1; // 只有一个元素且为k
    for(int i=0; i<nums.size(); i++) {
        sum += nums[i];
        
        if(mp.count(sum - k) == 1) {
            mx = max(mx, i - mp[sum-k]);
        }
        if(mp.count(sum) == 0) {
            mp[sum] = i;
        }
    }
    
    cout << mx << endl;
    return 0;
}
