// https://www.nowcoder.com/practice/8fecd3f8ba334add803bf2a06af1b993?tpId=13&tqId=23288&ru=/ta/sql-quick-study&qru=/ta/sql-quick-study/question-ranking
// ×Ö·û´®ÅÅÐò£¬to_string(), a_str + b_str < b_str + a_str
class Solution {
public:
    string PrintMinNumber(vector<int> &nums) {
        // a+b < b+a ÔòÅÅÐò a b
        string s;
        sort(nums.begin(),nums.end(), comp);
        
        for(int i=0; i<nums.size(); i++)
            s += to_string(nums[i]);

        return s;
    }

    static bool comp(int a, int b) {
        string s1 = to_string(a) + to_string(b);
        string s2 = to_string(b) + to_string(a);
        return s1 < s2;
    }
};
