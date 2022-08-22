// https://leetcode-cn.com/problems/next-permutation/
// ģ�⣬�Ӻ���ǰ�ҵ���һ��<ǰ<��>Ԫ���±�k���ٴ�[k+1,n-1]�ҵ���С����nums[k]Ԫ�ؽ��л���������[k+1,n-1]Ԫ����������Ҳ���k����������鵹�����У�ֱ�������м��ɡ�
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
