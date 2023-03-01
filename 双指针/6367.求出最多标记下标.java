import java.util.*;
// https://leetcode.cn/problems/find-the-maximum-number-of-marked-indices/
// 题解：双指针，检测能不能匹配k对，nums[i]越小越好，而nums[j]越大越好。
class Solution {
    public int maxNumOfMarkedIndices(int[] nums) {
        int n = nums.length, i = 0;

        Arrays.sort(nums);
        for(int j = (n + 1)/2; j < n; j++) {
            if(2 * nums[i] <= nums[j]) {
                i++;
            }
        }

        return i * 2;
    }
}

/*
[1]
[3,5,2,4]
[42,83,48,10,24,55,9,100,10,17,17,99,51,32,16,98,99,31,28,68,71,14,64,29,15,40]

0
2
26
*/