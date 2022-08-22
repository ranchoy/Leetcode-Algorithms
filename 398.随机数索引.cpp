// https://leetcode-cn.com/problems/random-pick-index/comments/
// 蓄水池抽样算法，https://www.coonote.com/algorithm-note/reservoir-algorithm.html
class Solution {
public:
    vector<int> nums;

    Solution(vector<int> &temp) {
        nums = temp;
    }

    int pick(int target) {
        int cnt = 0, idx = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target) {
                cnt++;
                if(rand() % cnt == 0) {
                    idx = i;
                }
            }
        }
        return idx;
    }
};

/*

["Solution","pick","pick","pick"]
[[[1,2,3,3,3]],[3],[1],[3]]

[null,4,0,2]
*/
