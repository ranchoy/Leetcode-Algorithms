// https://leetcode.cn/problems/find-k-closest-elements/
// 题解：二分查找+双指针，注意左右指针扩张条件。
class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        List<Integer> ans = new ArrayList<>();
        int n = arr.length;
        int idx = lower_bound(arr, x);
        int left = idx - 1, right = idx;

        while(k-- > 0) {
            if(left < 0) {
                right++;
            } else if(right >= n) {
                left--;
            } else if(x - arr[left] <= arr[right] - x) { // important!
                left--;
            } else {
                right++;
            }
        }

        System.out.println(idx + " " + left + " " + right);

        for(int i = left + 1; i < right; i++) {
            ans.add(arr[i]);
        }
        
        return ans;
    }

    public int lower_bound(int[] arr, int x) {
        int n = arr.length;
        int left = 0, right = n - 1;

        while(left < right) {
            int mid = left + (right - left) / 2;
            if(arr[mid] >= x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
}

/*
[1,2,3,4,5]
4
-1
[0,0,1,2,3,3,4,7,7,8]
3
5
[1,1,1,10,10,10]
1
9

[1,2,3,4]
[3,3,4]
[1]
*/