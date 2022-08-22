// https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/
// https://www.nowcoder.com/practice/96bd6684e04a44eb80e6a68efc0ec6c5?tpId=117
// �鲢������Ŀ�����ڡ��鲢������������������������ͳ��ÿ��Ԫ�ص����������������ͳ�Ʒ���
// ����1-right����Ԫ����temp-���ѭ���ᳬʱ��nums[i]>nums[j]��push(nums[j])������[i,mid]Ԫ�ض�����nums[j]������res[i]~res[mid]����Ҫ��1
// ����2-left����Ԫ����temp��nums[i]<nums[j]��push(nums[i])������[mid+1,j]Ԫ�ض�С��nums[i]��ֻ��Ҫres[i]��1
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
                res[pnums[i].second] += j - mid - 1; // ��pnums[i]С��Ԫ����j-mid-1��
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
