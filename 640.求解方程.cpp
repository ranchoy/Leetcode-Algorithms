// https://leetcode.cn/problems/solve-the-equation/
// 题解：等式消元模拟题，注意等号左右的符号问题，以及数字是代表"x"还是具体值。
class Solution {
public:
    string solveEquation(string equation) {
        bool valid;
        int i = 0, n = 0, sign1 = 1, sign2;
        int factor = 0, val = 0; // factor * x  = val;
        int len = equation.length();

        while(i < len) {
            if(equation[i] == '=') {
                sign1 = -1; i++; continue;
            }

            n = 0; sign2 = sign1; valid = false; // init
            if(equation[i] == '-' || equation[i] == '+') {
                sign2 = (equation[i] == '-') ? -sign1 : sign1;
                i++;
            }

            while(i < len && isdigit(equation[i])) {
                n = n * 10 + (equation[i] - '0');
                i++; valid = true;
            }

            if(i < len && equation[i] == 'x') {
                factor += valid ? sign2 * n : sign2; // +x
                i++;
            } else {
                val += sign2 * n; // +5-3
            }
        }

        if(factor == 0) {
            return (val == 0) ? "Infinite solutions" : "No solution";
        }
        return string("x=") + to_string(-val / factor);
    }
};

/*
"x=x"
"0x=0"
"x+5-3+x=6+x-2"

"Infinite solutions"
"Infinite solutions"
"x=2"
*/
