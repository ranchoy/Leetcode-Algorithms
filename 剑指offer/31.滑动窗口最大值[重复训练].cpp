// https://leetcode-cn.com/problems/sliding-window-maximum/
// https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/
// 单调双端队列，当新元素大于队尾则队尾删元素直至找到大的或为空，当删除元素判断删除是否是队首元素
class Solution {
public:
    deque<int> que;
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            deque_push_back(nums[i]);
            if(i >= k-1) {
                res.push_back(que.front());
                deque_pop_front(nums[i-k+1]);
            }
        }
        return res;
    }

    void deque_push_back(int val) {
        while(!que.empty() && val > que.back()) {
            que.pop_back(); // 队列单调递减
        }
        que.push_back(val);
    }

    void deque_pop_front(int val) {
        if(!que.empty() && val == que.front()) {
            que.pop_front(); // 弹出队首元素
        }
    }
};

/*
[1]
1
[1,3,-1,-3,5,3,6,7]
3

1
[3,3,5,5,6,7]
*/
