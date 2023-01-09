// https://leetcode.cn/problems/number-of-different-integers-in-a-string/
// 题解：模拟，注意以数字结尾的情况，以及全零数字情况。
class Solution {
public:
    int numDifferentIntegers(string word) {
        string temp;
        int n = word.size();
        set<string> hash_list;

        for(int i = 0, flag = 0; i < n; i++) {
            if(isalpha(word[i])) {
                if(!temp.empty()) hash_list.insert(temp);
                temp.clear(); flag = 0;
            } else {
                if(flag == 0 && word[i] == '0' && ((i < n-1 && isalpha(word[i+1])) || i == n-1)) {
                    if(hash_list.count(string("0")) == 0) {
                        hash_list.insert(string("0")); // important!
                    }
                }
                if(flag == 0 && word[i] == '0') continue;
                if(isdigit(word[i]) && word[i] != '0') flag = 1;
                temp += word[i];
            }
        }
        if(!temp.empty()) hash_list.insert(temp); // important!

        return hash_list.size();
    }
};

/*
"0a0"
"a1b01c001"
"a123bc34d8ef34"

1
1
3
*/
