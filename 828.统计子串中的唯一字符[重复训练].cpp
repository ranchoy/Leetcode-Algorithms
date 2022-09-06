// https://leetcode.cn/problems/count-unique-characters-of-all-substrings-of-a-given-string/
// 题解：公式推理，通过map记录各字符的idx，则含当前字符的子串个数为(nums[i] - nums[i-1])*(nums[i+1] - nums[i])。
class Solution {
public:
    int uniqueLetterString(string s) {
        int res = 0, len = s.size();
        map<char,vector<int>> mps;
        for(int i = 0; i < len; i++) {
            mps[s[i]].emplace_back(i);
        }

        for(auto &&[_, nums] : mps) {
            nums.insert(nums.begin(), -1); // single aplha
            nums.emplace_back(len);
            for(int i = 1; i < nums.size()-1; i++) {
                res += (nums[i] - nums[i-1]) * (nums[i+1] - nums[i]);
            }
        }

        return res;
    }
};

/*
"AA"
"ABA"
"ABC"

2
8
10
*/
