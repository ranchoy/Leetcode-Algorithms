// https://leetcode.cn/problems/shortest-subarray-to-be-removed-to-make-array-sorted/
// 题解：双指针，首先确定右递增半区，再随着左指针left递增，找到满足题意的最短子数组。
class Solution {
    public int findLengthOfShortestSubarray(int[] arr) {
        int n = arr.length, ans = 0;
        int left = 0, right = n - 1;

        while(right - 1 >= 0 && arr[right-1] <= arr[right]) {
            right--;
        }
        if(right == 0) return 0;

        ans = right; // arr[right]元素本身不算
        for(left = 0; left < n; left++) {
            while(right < n && arr[left] > arr[right]) {
                right++;
            }

            ans = Math.min(ans, right - left - 1); // n - (n - right) - (left + 1)
            if(left + 1 < n && arr[left] > arr[left + 1]) break; // imporant!
        }

        return ans;
    }
}

/*
[1,2,3]
[5,4,3,2,1]
[1,2,3,10,4,2,3,5]

0
4
3
*/