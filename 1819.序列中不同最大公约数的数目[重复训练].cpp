// https://leetcode.cn/problems/number-of-different-subsequences-gcds/
// 题解：枚举+GCD函数，元素i不断增加，判断是否有子序列的最大公约数是i。其中，i的整数被一定可以，存在就继续寻找下一元素。
class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int> &nums) {
        int ans = 0;
        int N = *max_element(nums.begin(), nums.end());

        vector<bool> mark_list(N + 1, false);
        for(int i = 0; i < nums.size(); i++) {
            mark_list[ nums[i] ] = true;
        }

        for(int i = 1; i <= N; i++) {
            int gcd_num = -1;
            for(int j = i; j <= N; j += i) {
                if(mark_list[j] == false) continue;

                if(gcd_num == -1) {
                    gcd_num = j; // important!
                } else {
                    gcd_num = __gcd(j, gcd_num);
                }

                if(gcd_num == i) {
                    ans++; break;
                }
            }
        }

        return ans;
    }
};

/*
[6,10,3]
[5,15,40,5,6]

5
7
*/
