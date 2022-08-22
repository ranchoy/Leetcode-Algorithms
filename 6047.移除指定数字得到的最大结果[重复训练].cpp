// https://leetcode.cn/problems/remove-digit-from-number-to-maximize-result/
// 模拟题目，字符串截取函数s.substr(int _pos, int _len)
class Solution {
public:
    string removeDigit(string number, char digit) {
        int pre = -1;
        int len = number.size();

        for(int i = 0; i < len; i++) {
            if(number[i] != digit) continue;
            pre = i;
            if(i+1 < len && number[i+1] > number[i]) {
                break; // 重要，贪心算法，越在前面结束越好
            }
        }

        return number.substr(0, pre) + number.substr(pre+1, len-pre-1);
    }

    string removeDigit2(string number, char digit) {
        string mx_str, cur_str;
        int len = number.size();

        for(int i = 0; i < len; i++) {
            if(number[i] != digit) continue;

            if(i == 0 || i == len-1) {
                int t = (i == 0) ? 1 : 0;
                cur_str = number.substr(t, len-1);
            } else {
                cur_str = number.substr(0, i);
                cur_str += number.substr(i+1, len-i-1);
            }

            if(mx_str.size() == 0 || comp_str(mx_str, cur_str) == false) {
                mx_str = cur_str;
            }
        }

        return mx_str;
    }

    bool comp_str(string mx_str, string cur_str) {
        int len = mx_str.size();
        for(int i = 0; i < len; i++) {
            if(mx_str[i] == cur_str[i]) continue;

            if(mx_str[i] > cur_str[i]) {
                return true;
            } else{
                return false;
            }
        }
        return false; // 相等，不需要更新
    }
};

/*
"133235"
"3"
"15454"
"4"

"13325"
"1554"
*/
