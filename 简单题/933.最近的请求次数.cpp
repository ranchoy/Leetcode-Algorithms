// https://leetcode-cn.com/problems/number-of-recent-calls/
// 模拟题目，数组实现。
class RecentCounter {
public:
    int ping_cnt,left;
    vector<int> nums;

    RecentCounter() {
        left = 0;
        ping_cnt = 0;
    }

    int ping(int t) {
        if(nums.size() == 0) {
            nums.push_back(t); return 1;
        }
        nums.push_back(t);
        while(t-3000 > nums[left]) {
            left++;
        }
        return nums.size() - left;
    }
};

/*

["RecentCounter","ping","ping","ping","ping"]
[[],[1],[100],[3001],[3002]]

[null,1,2,3,3]
*/

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
