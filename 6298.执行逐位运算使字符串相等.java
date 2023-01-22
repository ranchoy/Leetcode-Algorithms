// https://leetcode.cn/problems/apply-bitwise-operations-to-make-strings-equal/
// 题解：思维，字符串s和target中需要"1"的出现，都出现或者都不出现。
class Solution {
    public boolean makeStringsEqual(String s, String target) {
        boolean a = false, b = false;
        for(int i = 0; i < s.length(); i++) {
            if(s.charAt(i) == '1') a = true;
            if(target.charAt(i) == '1') b = true;
        }

        return a == b;
    }
}

/*
"1010"
"0110"
"000000"
"000000"
"001000"
"000100"

true
true
true
*/