// https://leetcode.cn/problems/make-two-arrays-equal-by-reversing-sub-arrays/
// 题解：桶计数法，一旦出现某个元素不相等，则表明两个数组不同。
class Solution {
public:
    const int N = 1010;
    bool canBeEqual(vector<int> &target, vector<int> &arr) {
        if(target.size() != arr.size()) return false;

        int len = target.size();
        vector<int> nums(N, 0);

        for(int i = 0; i < len; i++) {
            nums[target[i]] += 1; nums[arr[i]] -= 1;
        }

        for(int i = 0; i < len; i++) {
            if(nums[target[i]] != 0) return false;
        }

        return true;
    }
};

/*
[1,2,3]
[1,2,4]
[1,2,3,4]
[2,4,1,3]

false
true
*/
