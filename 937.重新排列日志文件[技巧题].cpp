// https://leetcode-cn.com/problems/reorder-data-in-log-files/
// stable_sort()函数不改变相对位置，重写排序函数，注意有特殊样例。
class Solution {
public:
    vector<string> reorderLogFiles(vector<string> &logs) {
        int n = logs.size();
        stable_sort(logs.begin(), logs.end(), comp_string);
        return logs;
    }

    static bool comp_string(const string &a, const string &b) {
        string s1, s2;
        int pos1 = a.find_first_of(" ");
        int pos2 = b.find_first_of(" ");
        bool flag1 = isdigit(a[pos1+1]);
        bool flag2 = isdigit(b[pos2+1]);

        // 全数字日志
        if(flag1 && flag2) {
            return false;
        }
        // 全字母日志
        if(!flag1 && !flag2) {
            s1 = a.substr(pos1);
            s2 = b.substr(pos2);
            if(s1 != s2) {
                return s1 < s2;
            }
            return a < b; // 重要
        }
        // 数字a字母b，字母a与数字b
        return flag1 ? false : true;
    }
};

/*
["t kvr", "r 3 1", "i 403", "7 so", "t 54"]
["zoey i love you","lucas i love you","rong i love you"]
["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]


["lucas i love you","rong i love you","zoey i love you"]
["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]
*/
