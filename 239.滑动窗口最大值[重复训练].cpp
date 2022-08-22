// https://leetcode-cn.com/problems/sliding-window-maximum/
// https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/
// 单调双端队列，当新元素大于队尾则队尾删元素直至找到大的或为空，当删除元素判断删除是否是队首元素
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        deque<int> deq;
        vector<int> res;

        for(int i = 0; i < nums.size(); i++) {
            deque_push_back(deq, nums[i]); // 区间[i-k+1,i]
            if(i >= k-1) {
                res.push_back(deq.front());
                deque_pop_front(deq, nums[i-k+1]);
            }
        }

        return res;
    }

    void deque_push_back(deque<int> &deq, int val) {
        while(!deq.empty() && deq.back() < val) {
            deq.pop_back(); // 队列单调递减
        }
        deq.push_back(val);
    }

    void deque_pop_front(deque<int> &deq, int val) {
        if(!deq.empty() && deq.front() == val) {
            deq.pop_front(); // 弹出队首元素
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
