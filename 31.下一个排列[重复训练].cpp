// https://leetcode-cn.com/problems/next-permutation/
// 模拟，从后向前找到第一个<前<后>元素下标k，再从[k+1,n-1]找到最小大于nums[k]元素进行互换，最后对[k+1,n-1]元素排序。如果找不到k，则表明数组倒序排列，直接重排列即可。
class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int k = -1, mn, idx;
        int n = nums.size();
        
        for(int i = n-2; i >= 0; i--) {
            if(nums[i] < nums[i+1]) {
                k = i; break; // 12354, k=2
            }
        }
        
        if(k == -1) { // 54321
            sort(nums.begin(), nums.end());
            return;
        }
        
        mn = INT_MAX;
        for(int i = n-1; i >= k+1; i--) {
            if(nums[i] > nums[k] && mn > nums[i]) {
                idx = i; mn = nums[i]; // idx=4 
            }
        }
        
        swap(nums[k], nums[idx]);
        sort(nums.begin()+k+1, nums.end());
    }
};

/*
[1,2,3]
[3,2,1]

[1,3,2]
[1,2,3]
*/
