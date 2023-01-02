// https://leetcode.cn/problems/check-if-numbers-are-ascending-in-a-sentence/
// 题解：stringstream + stoi的使用，注意要求是严格递增。
class Solution {
public:
    bool areNumbersAscending(string s) {
        int pre = -1, cur = -1;
        string temp_s;
        stringstream ss(s);

        while(ss >> temp_s) {
            if(isalpha(temp_s[0])) continue;
            pre = cur; cur = stoi(temp_s);
            if(pre >= cur) return false;
        }

        return true;
    }
};

/*
"hello world 5 x 5"
"1 box has 3 blue 4 red 6 green and 12 yellow marbles"

false
true
*/
