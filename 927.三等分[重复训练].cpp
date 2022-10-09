// https://leetcode.cn/problems/three-equal-parts/
// 题解：模拟题，根据1的次数进行下标切割，再判断三部分是否相等。
class Solution {
public:
    vector<int> threeEqualParts(vector<int> &arr) {
        int n = arr.size(), len;
        int sum = accumulate(arr.begin(), arr.end(), 0);
        int partial = sum / 3;
        int idx1 = 0, idx2 = 0, idx3 = 0; // [idx1,idx1+len],[idx2,idx2+len],[idx3,idx3+len]

        if(sum == 0) return {0,2};
        if(sum % 3 != 0) return {-1,-1};
        for(int i = 0, k = 0; i < n; i++) {
            if(arr[i] == 1) {
                if(k == 0) idx1 = i;
                else if(k == partial) idx2 = i;
                else if(k == 2 * partial) idx3 = i;
                k++;
            }
        }

        len = n - idx3;
        if(idx1 + len <= idx2 && idx2 + len <= idx3) {
            for(int i = 0; idx3 + i < n; i++) {
                if(arr[idx1+i] != arr[idx2+i] || arr[idx1+i] != arr[idx3+i]) {
                    return {-1,-1};
                }
            }
            return {idx1+len-1, idx2+len};
        }
        
        return {-1,-1};
    }
};

/*
[0,0,0,0,0]
[1,0,1,0,1]
[1,1,0,1,1]

[0,2]
[0,3]
[-1,-1]
*/
