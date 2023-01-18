// https://leetcode.cn/problems/strong-password-checker-ii/
class Solution {
    public boolean strongPasswordCheckerII(String password) {
        int n = password.length();
        String str = "!@#$%^&*()-+";
        boolean flag1 = false, flag2 = false, flag3 = false, flag4 = false, flag5 = true;

        if(n < 8) return false;
        for(int i = 0; i < n; i++) {
            char ch = password.charAt(i);
            if(Character.isUpperCase(ch)) flag1 = true;
            if(Character.isLowerCase(ch)) flag2 = true;
            if(Character.isDigit(ch)) flag3 = true;
            if(str.indexOf(ch) != -1) flag4 = true;
            if(i > 0 && ch == password.charAt(i-1)) flag5 = false;
        }

        return flag1 & flag2 & flag3 & flag4 & flag5;
    }
}

/*
"IloveLe3tcode!"
"11A!A!Aa"


true
false
*/