// https://leetcode.cn/problems/number-of-students-unable-to-eat-lunch/
// 题解：模拟，一旦没有学生取出栈顶元素则结束。
class Solution {
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches) {
        vector<int> cnt(2);
        for(int i : students) cnt[i]++;
        for(int i : sandwiches) {
            if(cnt[i] > 0) cnt[i]--;
            else break;
        }
        return cnt[0] + cnt[1];
    }
};

/*
[1,1,0,0]
[0,1,0,1]
[1,1,1,0,0,1]
[1,0,0,0,1,1]

0
3
*/
