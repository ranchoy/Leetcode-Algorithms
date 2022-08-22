// https://leetcode-cn.com/problems/find-the-distance-value-between-two-arrays/
// 二分查找，时间复杂度为O(nlog(n))
class Solution {
public:
    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d) {
        int cnt = 0;
        int v_min, v_max;
        int len2 = arr2.size();

        sort(arr2.begin(), arr2.end()); // sort
        for(int i = 0; i < arr1.size(); i++) {
            v_min = arr1[i] - d;
            v_max = arr1[i] + d;
            if(is_in_region(arr2, v_min, v_max, 0, len2-1) == false) {
                cnt++;
            }
        }
        return cnt;
    }

    bool is_in_region(vector<int> &arr2, int v_min, int v_max, int left, int right) {
        if(left > right) return false;
        if(arr2[left] > v_max || arr2[right] < v_min) {
            return false;
        }
        int mid = left + ((right - left)>>1);
        if(arr2[mid] >= v_min && arr2[mid] <= v_max) {
            return true;
        } else if(arr2[mid] > v_max) {
            return is_in_region(arr2, v_min, v_max, left, mid-1);
        }
        return is_in_region(arr2, v_min, v_max, mid+1, right);
    }
};

/*
[4,5,8]
[10,9,1,8]
2

2
*/
