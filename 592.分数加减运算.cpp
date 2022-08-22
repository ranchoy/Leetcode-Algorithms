// https://leetcode.cn/problems/fraction-addition-and-subtraction/
// 题解：istringstream的使用
class Solution {
public:
    string fractionAddition(string expression) {
        char op;
        int a = 0, b = 1;
        int num1 = 0, num2 = 0;
        istringstream ss(expression);

        while(ss >> num1 >> op >> num2) {
            a = a * num2 + num1 * b;
            b = b * num2;
            int g = abs(__gcd(a, b));
            a = a / g; b = b / g;
        }
        return to_string(a) + "/" + to_string(b);
    }
};

/*
"-1/2+1/2"
"1/3-1/2"

"0/1"
"-1/6"
*/
