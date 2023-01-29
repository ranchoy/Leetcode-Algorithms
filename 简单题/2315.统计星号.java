// https://leetcode.cn/problems/count-asterisks/
class Solution {
    public int countAsterisks(String s) {
        int ans = 0;
        int n = s.length();
        boolean flag = false;

        for(int i = 0; i < n; i++) {
            if(s.charAt(i) == '*' && flag == false) ans++;
            if(s.charAt(i) == '|') flag = !flag;
        }

        return ans;
    }
}

/*
"l|*e*et|c**o|*de|"
"yo|uar|e**|b|e***au|tifu|l"

2
5
*/