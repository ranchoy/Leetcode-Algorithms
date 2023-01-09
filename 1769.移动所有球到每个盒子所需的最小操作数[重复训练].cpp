// https://leetcode.cn/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/
// 题解：模拟，定义left和right分别为boxes[i]的左右边球数量，则res[i+1]=res[i]+left-right;
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> res(n,0);
        int left = boxes[0] - '0', right = 0, move_cnt = 0;

        for(int i = 1; i < n; i++) {
            if(boxes[i] == '1') {
                right++;
                move_cnt += i;
            }
        }

        res[0] = move_cnt;
        for(int i = 1; i < n; i++) {
            move_cnt += left - right;
            if(boxes[i] == '1') {
                left++; right--;
            }
            res[i] = move_cnt;
        }

        return res;
    }
};

/*
"110"
"001011"

[1,1,3]
[11,8,5,4,3,4]
*/
