// https://leetcode-cn.com/problems/longest-palindromic-substring/
// Manacher问题，p[i]表示以i为中心包括i的回文串最大半径，mx与mid分别表示当前最大右边界与中心点, 初始mx=mid=1
// 核心：p[i] = (mx > i) ? min(p[2*mid-1], mx-i) : 1;
// 索引：0 --- j=2*mid-1 --- mid --- i --- mx
class Solution {
public:
    string longestPalindrome(string s) {
        string n_str = get_new_string(s);
        int len = n_str.length();
        int left, right;
        int p[5010] = {0}; p[0] = 1;
        int mx = 1, mid = 1, res = 0;

        for(int i = 1; i < len; i++) {
            p[i] = (mx > i) ? min(p[2*mid-1], mx-i) : 1;
            while(n_str[i - p[i]] == n_str[i + p[i]]) {
                p[i]++;
            }
            if(p[i] > mx-i) {
                mid = i; mx = i+ p[i];
            }
            if(p[i] > res) {
                res = p[i];
                left = i - p[i];
                right = i + p[i];
            }
        }

        string ans_str;
        for(int i = left+1; i <= right-1; i++) {
            if(n_str[i] != '$' && n_str[i] != '#') {
                ans_str += n_str[i];
            }
        }

        return ans_str;
    }

    string get_new_string(string s) {
        string n_str("$#"); // $#a#a#b#a#d#
        for(int i = 0; i < s.length(); i++) {
            n_str += s[i];
            n_str += '#';
        }
        return n_str;
    }
};

/*
"babad"
"bab"
*/
