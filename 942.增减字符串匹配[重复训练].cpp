// https://leetcode.cn/problems/di-string-match/
// 贪心+双指针，上升关系则low，下降关系则high。
class Solution {
public:
    vector<int> diStringMatch(string s) {
        int len = s.size();
        int low = 0, high = len;
        vector<int> nums(len+1, 0);
        for(int i = 0; i <= len; i++) {
            nums[i] = (s[i] == 'I') ? low++ : high--;
        }
        return nums;
    }
};

/*
"III"
"IDID"

[0,1,2,3]
[0,4,1,3,2]
*/
