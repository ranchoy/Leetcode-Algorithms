// https://leetcode.cn/problems/bianry-number-to-string-lcci/
// 题解：二进制模拟，数num乘以二等于二进制小数点右移一位。
class Solution {
    public String printBin(double num) {
        StringBuilder ans = new StringBuilder("0.");

        while(ans.length() <= 32 && num != 0.0) {
            num = num * 2;
            int a = (int) num;
            ans.append(a);
            num -= a;
        }

        return (ans.length() <= 32) ? ans.toString() : "ERROR";
    }
}

/*
0.1
0.625

"ERROR"
"0.101"
*/