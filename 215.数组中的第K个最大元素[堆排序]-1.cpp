// https://leetcode.cn/problems/kth-largest-element-in-an-array/
// 题解：构建小根堆，维护前k长的小根堆，堆顶元素小于后续元素就互换，继续维护小根堆。
class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        for(int i = (k-1)/2; i >= 0; i--) {
            build_min_heap(nums, i, k); // build
        }

        for(int i = k; i < nums.size(); i++) {
            if(nums[0] < nums[i]) {
                swap(nums[0], nums[i]); // remove
                build_min_heap(nums, 0, k); // build
            }
        }
        return nums[0];
    }

    void build_min_heap(vector<int> &nums, int i, int len) {
        int idx, lson, rson;
        for(; 2*i+1 < len; ) {
            idx = i; lson = 2*i+1; rson = 2*i+2;
            if(lson < len && nums[i] > nums[lson]) {
                idx = lson;
            }
            if(rson < len && nums[idx] > nums[rson]) {
                idx = rson;
            }

            if(idx != i) {
                swap(nums[i], nums[idx]); i = idx;
            } else {
                break;
            }
        }
    }
};

/*
[3,2,1,5,6,4]
2
[3,2,3,1,2,4,5,5,6]
4

5
4
*/
