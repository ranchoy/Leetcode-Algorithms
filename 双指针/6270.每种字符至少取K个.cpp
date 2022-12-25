// https://leetcode.cn/problems/take-k-of-each-character-from-left-and-right/
// 题解：双指针，先找到刚好满足的后缀，再不断增加前缀长度，同时减小后缀长度，并保留最小的结果res。注意后缀必须刚好停下。
class Solution {
public:
    int takeCharacters(string s, int k) {
        int res, n = s.size();
        int left = 0, right = n;
        vector<int> nums(3, 0); // count of alpha

        while(nums[0] < k || nums[1] < k || nums[2] < k) {
            if(right == 0) return -1; // 不能满足题意，返回-1。
            right--; // 必须停止在字符abc次数都刚好为k。
            nums[s[right] - 'a'] += 1;
        }
        res = n - right;

        for(left = 0; left < n; left++) {
            nums[s[left] - 'a'] += 1;

            while(right < n && nums[s[right] - 'a'] > k) {
                nums[s[right] - 'a'] -= 1;
                right++;
            }

            res = min(res, left + 1 + n - right);
            if(right == n) break;
        }

        return res;
    }
};

/*
"a"
1
"abca"
"aabaaaacaabc"
2

-1
3
8
*/
