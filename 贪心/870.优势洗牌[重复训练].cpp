// https://leetcode.cn/problems/advantage-shuffle/
// 题解：贪心+idx索引+双指针，当nums1最小元素大于nums2最小元素时，对应nums2元素位置赋值；当小于nums2最小元素时，nums2最大元素赋值。
// 注意idx索引数组存放的是nums数组元素从小到大排列的索引。
// https://leetcode.cn/problems/advantage-shuffle/
// 题解：贪心+idx索引+双指针，当nums1最小元素大于nums2最小元素时，对应nums2元素位置赋值；当小于nums2最小元素时，nums2最大元素赋值。
// 注意idx索引数组存放的是nums数组元素从小到大排列的索引。
class Solution {
public:
    vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2) {
        int a, b, left, right;
        int n = nums1.size();
        vector<int> res(n,0), idx; // nums2第i大元素在idx[i]处

        for(int i = 0; i < n; i++) {
            idx.push_back(i);
        }
        sort(nums1.begin(), nums1.end(), less<int>());
        sort(idx.begin(), idx.end(), [&](int i, int j){return nums2[i] < nums2[j];});

        left = 0; right = n-1;
        for(int i = 0, k = 0; i < n; i++) {
            a = idx[left]; b = idx[right];
            if(nums1[i] > nums2[a]) {
                res[a] = nums1[i];
                left++;
            } else {
                res[b] = nums1[i];
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
