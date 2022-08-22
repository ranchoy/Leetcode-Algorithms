// https://www.nowcoder.com/practice/b56799ebfd684fb394bd315e89324fb4?tpId=117
// 滑动窗口，巧用left索引，类似无重复最长子串
class Solution {
public:
    int maxLength(vector<int>& arr) {
        int mx = 0, left, key;
        int n = arr.size();
        map<int, int> mp; // 值-索引
        
        left = 0;
        for(int i=0; i<n; i++) {
            key = arr[i];
            if(mp.find(key) != mp.end()) {
                mx = max(mx, i-left);
                left = max(left, mp[key]+1);
            } else {
                mx = max(mx, i-left+1);
            }
            mp[key] = i; // 更新索引
        }
        return mx;
    }
};
