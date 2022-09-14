// https://leetcode.cn/problems/sort-an-array/
// 题解：堆排序，构造大根堆，每次互换堆顶和堆底元素，直至堆元素唯一。
class Solution {
public:
    vector<int> sortArray(vector<int> &nums) {
        heap_sort(nums);
        return nums;
    }
    
    void build_heap(vector<int> &nums, int i, int len) {
        int max_idx, lson, rson;
        for(; 2*i+1 < len; ) {
            max_idx = i;
            lson = 2*i + 1; rson = 2*i + 2;
            if(lson < len && nums[lson] > nums[i]) max_idx = lson;
            if(rson < len && nums[rson] > nums[max_idx]) max_idx = rson;
            if(max_idx != i) {
                swap(nums[i], nums[max_idx]);
                i = max_idx;
            } else {
                break;
            }
        }
    }
    
    void heap_sort(vector<int> &nums) {
        int len = nums.size();
        
        // build heap
        for(int i = (len-1)/2; i >= 0; i--) {
            build_heap(nums, i, len);
        }
        
        // get elements from the top of heap
        for(int i = len-1; i >= 0; i--) {
            swap(nums[0], nums[i]);
            build_heap(nums, 0, i);
        }
    }
};

/*
[3,2,1]

[1,2,3]
*/
