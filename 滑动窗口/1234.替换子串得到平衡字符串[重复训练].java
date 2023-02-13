// https://leetcode.cn/problems/replace-the-substring-for-balanced-string/
// 题解：滑动窗口，设替换区间为[left, right]，只要替换区间外的字符个数都cnt[x]<=m，则替换区间有效。否则，无论怎么替换都不满足题意。
class Solution {
    public int balancedString(String s) {
        int ans = s.length();
        int n = s.length(), m = n / 4;
        int[] cnt = new int['X']; // 记录替换区间外的字符出现次数;
        char[] s_arr = s.toCharArray();
        
        for(char c : s_arr) cnt[c]++;
        if(cnt['Q'] == m && cnt['W'] == m && cnt['E'] == m && cnt['R'] == m) {
            return 0;
        }
        for(int right = 0, left = 0; right < n; right++) {
            cnt[s_arr[right]]--; // right递增，替换区间[left,right]外的cnt减小
            while(cnt['Q'] <= m && cnt['W'] <= m && cnt['E'] <= m && cnt['R'] <= m) {
                cnt[s_arr[left]]++;
                ans = Math.min(ans, right - left + 1);
                left++;
            }
        }

        return ans;
    }
}

/*
"QWER"
"QQWE"
"QQQW"

0
1
2
*/