// https://leetcode-cn.com/problems/lexicographical-numbers/
// DFS动态规划，注意递归的顺序，记得避免重复元素。
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        if(n == 1) return {1};
        vector<int> nums;
        dfs(nums, n, 1);
        return nums;
    }

    void dfs(vector<int> &nums, int n, int start_val) {
        if(start_val > n) return;
        else nums.push_back(start_val); // 1,10,100,...

        dfs(nums, n, start_val*10);
        for(int i = 1; i <= 9; i++) {
            if(start_val + i <= n) {
                if(start_val + i == 10) {
                    continue; // 1+9=10,避免重复
                }
                nums.push_back(start_val + i);
                dfs(nums, n, (start_val + i)*10);
            } else {
                break;
            }
        }
    }
};

/*
1
[1]

13
[1,10,11,12,13,2,3,4,5,6,7,8,9]
*/
