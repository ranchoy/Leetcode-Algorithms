// https://leetcode-cn.com/problems/find-smallest-letter-greater-than-target/
// 二分查找，注意最终letters[left]可能不满足条件，需要判断。
class Solution {
public:
    char nextGreatestLetter(vector<char> &letters, char target) {
        int len = letters.size();
        int mid, left = 0, right = len-1;

        while(left < right) {
            mid = left + ((right-left)>>1);
            if(letters[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if(left+1 < len && letters[left] <= target) {
            return letters[left+1];
        } else if(left == len-1 && letters[left] <= target) {
            return letters[0];
        }

        return letters[left];
    }
};

/*
["c","f","j"]
"d"
["c","f","j"]
"c"
["c","f","j"]
"j"

"f"
"f"
"c"
*/
