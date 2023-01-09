// https://leetcode.cn/problems/kth-largest-element-in-an-array/
// 题解：堆排序heap_sort，构建大根堆，不断互换堆顶和堆尾元素达到k次，返回第k大的元素nums[i]。
class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        int n = nums.size();

        for(int i = (n - 1)/2; i >= 0; i--) {
            build_heap(nums, i, n); // 构建大根堆
        }
        for(int i = n - 1; i >= 0; i--) {
            swap(nums[i], nums[0]); // 堆顶与堆尾元素互换
            build_heap(nums, 0, i);
            if(i == n - k) return nums[i]; // 返回，第k大的元素
        }

        return -1;
    }

    void build_heap(vector<int> &nums, int i, int len) {
        int lson, rson, max_idx;

        for(; 2*i + 1 < len; ) {
            max_idx = i; lson = 2 * i + 1; rson = 2 * i + 2; // lson和rson不能越界！
            if(lson < len && nums[lson] > nums[i]) max_idx = lson;
            if(rson < len && nums[rson] > nums[max_idx]) max_idx = rson;

            if(max_idx != i) {
                swap(nums[i], nums[max_idx]);
                i = max_idx;
            } else {
                break; // i本身是最大元素，终止遍历！
            }
        }
    }
};

/*
[2,1]
1
[3,2,1,5,6,4]
2
[3,2,3,1,2,4,5,5,6]
4

2
5
4
*/
