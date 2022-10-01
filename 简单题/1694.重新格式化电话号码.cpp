// https://leetcode.cn/problems/reformat-phone-number/
class Solution {
public:
    string reformatNumber(string number) {
        string s, res;
        for(int i = 0; i < number.size(); i++) {
            if(isdigit(number[i])) s += number[i];
        }

        int len = s.size();
        for(int i = 0; i < len; i += 3) {
            if(i + 5 > len) {
                if(i + 3 >= len) res += s.substr(i); // 123-4 123-4
                else res += s.substr(len-4,2) + '-' + s.substr(len-2,2); // 123-45-67
                break;
            }
            res += s.substr(i, 3) + '-';
        }

        return res;
    }
};

/*
"1-2"
"1-234"
"1-234567"
"1-2345678"

"12"
"12-34"
"123-45-67"
"123-456-78"
*/
