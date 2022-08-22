// https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/
// https://www.nowcoder.com/practice/96bd6684e04a44eb80e6a68efc0ec6c5?tpId=117
// 归并排序，题目类似于《归并排序计算逆序对数》，这里是统计每个元素的逆序对数，有两种统计方法
// 方法1-right半区元素入temp-多层循环会超时：nums[i]>nums[j]，push(nums[j])，区间[i,mid]元素都大于nums[j]，区间res[i]~res[mid]都需要加1
// 方法2-left半区元素入temp：nums[i]<nums[j]，push(nums[i])，区间[mid+1,j]元素都小于nums[i]，只需要res[i]加1
class Solution {
public:
    vector<int> countSmaller(vector<int> &nums) {
        int n = nums.size();
        vector<int> res(n,0);
        vector<pair<int,int>> pnums;        
        for(int i = 0; i < n; i++) {
            pnums.emplace_back(nums[i], i);
        }
        merge_sort(pnums, res, 0, n-1);
        return res;
    }

    void merge_sort(vector<pair<int,int>> &pnums, vector<int> &res, int left, int right) {
        if(left >= right) return;
        vector<pair<int,int>> temp;
        int mid = (left + right) / 2;
        int i = left, j = mid + 1, k = 0;
        
        merge_sort(pnums, res, left, mid);
        merge_sort(pnums, res, mid+1, right);
        
        while(i <= mid && j <= right) {
            if(pnums[i].first <= pnums[j].first) {
                res[pnums[i].second] += j - mid - 1; // 比pnums[i]小的元素有j-mid-1个
                temp.push_back(pnums[i++]);
            } else {
                temp.push_back(pnums[j++]);
            }
        }
        while(i <= mid) {
            res[pnums[i].second] += j - mid - 1;
            temp.push_back(pnums[i++]);
        }
        while(j <= right) {
            temp.push_back(pnums[j++]);
        }
        for(i = left; i <= right; i++) pnums[i] = temp[i-left];
    }
};
/*
[-1,-1]
[2,0,1]
[5,2,6,1]

[0,0]
[2,0,0]
[2,1,1,0]
*/
