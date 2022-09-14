// https://leetcode.cn/problems/largest-number/
// 题解：贪心，两个数根据不同的拼接顺序进行排序。
class Solution {
public:
    string largestNumber(vector<int> &nums) {
        string res;
        sort(nums.begin(), nums.end(), comp);
        if(nums[0] == 0) return "0";
        for(auto num : nums) res += to_string(num);
        return res;
    }

    static bool comp(int x, int y) {
        long int a = 10, b = 10; // 最少是个位起步
        while(a <= x) a *= 10;
        while(b <= y) b *= 10;
        return b*x + y > a*y + x; // x+y vs. y+x
    }
};

/*
[10,2]
[1,2,3,4,5,6,7,8,9,0]

"210"
"9876543210"
*/
