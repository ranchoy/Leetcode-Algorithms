// https://leetcode.cn/problems/advantage-shuffle/
// 题解：贪心+idx索引+双指针，当nums1最小元素大于nums2最小元素时，对应nums2元素位置赋值；当小于nums2最小元素时，nums2最大元素赋值。
// 注意idx索引数组存放的是nums数组元素从小到大排列的索引。
class Solution {
public:
    vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2) {
        int a, b, c, left, right;
        int n = nums1.size();
        vector<int> res(n,0);
        vector<int> idx1, idx2; // 第i大元素在idx[i]处

        for(int i = 0; i < n; i++) {
            idx1.push_back(i); idx2.push_back(i);
        }
        sort(idx1.begin(), idx1.end(), [&](int i, int j){return nums1[i] < nums1[j];});
        sort(idx2.begin(), idx2.end(), [&](int i, int j){return nums2[i] < nums2[j];});

        left = 0; right = n-1;
        for(int i = 0, k = 0; i < n; i++) {
            a = idx1[i]; b = idx2[left]; c = idx2[right];
            if(nums1[a] > nums2[b]) {
                res[b] = nums1[a];
                left++;
            } else {
                res[c] = nums1[a];
                right--;
            }
        }

        return res;
    }
};

/*
[2,7,11,15]
[1,10,4,11]
[12,24,8,32]
[13,25,32,11]

[2,11,7,15]
[24,32,8,12]
*/
