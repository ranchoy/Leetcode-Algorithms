// https://leetcode.cn/problems/swap-adjacent-in-lr-string/
// 题解：双指针+排除法，指定单向变化("XL"->"LX","RX"->"XR")不满足是返回不可行。
class Solution {
public:
    bool canTransform(string start, string end) {
        int i = 0, j = 0;
        int len = start.size();
        
        while(i < len && j < len) {
            while(i < len && start[i] == 'X') {
                i++;
            }
            while(j < len && end[j] == 'X') {
                j++;
            }

            if(i < len && j < len) {
                if(start[i] != end[j]) return false;
                if((start[i] == 'L' && i < j) || (start[i] == 'R' && i > j)) return false;
                i++; j++;
            }
        }

        while(i < len) {
            if(start[i++] != 'X') return false;
        }
        while(j < len) {
            if(end[j++] != 'X') return false;
        }

        return true;
    }
};

/*
"RXXLRXRXL"
"XRLXXRRLX"

true
*/
