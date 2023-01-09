// https://www.nowcoder.com/questionTerminal/a4e34287fa1b41f9bd41f957efbd5dff
// 求连续最长数组和为k的子数组长度
// 滑动窗口，在区间[left, right]的和与k进行比较
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    
    cin >> n >> k;
    vector<int> nums(n);
    
    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }
    
    int max_len = 0;
    int sum = nums[0];
    int left = 0, right = 0;
    
    while(left <= right) { // 重要
        if(sum == k) {
            max_len = max(max_len, right-left+1);
            sum -= nums[left];
            left++;
        } else if(sum < k) {
            right++;
            if(right == nums.size()) break;
            sum += nums[right];
        } else {
            sum -= nums[left];
            left++;
        }
    }
    cout << max_len << endl;
    return 0;
}

/*
5 3
1 2 1 1 1
3

1 3
3
1
*/
