// https://leetcode.cn/problems/sum-of-subarray-minimums/
// 题解：单调栈，left[i]表示以nums[i]为最右且最小的子序列的数目，right[i]表示以nums[i]最左且最小的子序列的数目，注意left[i]和right[i]需要避免重复计算。
// 推导公式：res += left[i] * right[i] * nums[i] % N;
class Solution {
public:
    const int N = 1e9 + 7;
    int sumSubarrayMins(vector<int> &nums) {
        int n = nums.size();
        long long res = 0;
        stack<int> stk;
        vector<int> left(n), right(n);

        for(int i = 0; i < n; i++) {
            while(!stk.empty() && nums[i] <= nums[stk.top()]) { // important!
                stk.pop(); // [top|-1, i]
            }
            left[i] = i - (stk.empty() ? -1 : stk.top());
            stk.push(i);
        }

        while(!stk.empty()) stk.pop(); // clear stack
        for(int i = n-1; i >= 0; i--) {
            while(!stk.empty() && nums[i] < nums[stk.top()]) { // important!
                stk.pop(); // [i,top|n]
            }
            right[i] = (stk.empty() ? n : stk.top()) - i;
            stk.push(i);
        }

        for(int i = 0; i < n; i++) {
            res = ((res + N) % N + (long long)left[i] * right[i] * nums[i]) % N;
        }
        return res;
    }
};

/*
[3,1,2,4]
[71,55,82,55]

17
593
*/
