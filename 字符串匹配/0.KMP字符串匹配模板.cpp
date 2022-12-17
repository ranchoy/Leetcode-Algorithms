// KMP匹配模板，核心是构建next[i]数组，next[i]表示模式串s[0,i]的最长公共前后缀的结尾索引，最长公共串的长度为next[i]+1。
// 注意：1. KMP的核心是next[i]的构建。当遇到不匹配情况时，跳过公共部分，至next[i]。
//       2. 字符串"abab"，前缀"aba"，后缀"bab"，长公共前后缀"ba"。
#include<bits/stdc++.h>
using namespace std;

void get_next_arr(string s, vector<int> &next) {
    int n = s.size(), k;

    k = next[0] = -1;
    for(int i = 1; i < n; i++) {
        while(k > -1 && s[i] != s[k+1]) {
            k = next[k];
        }
        if(s[i] == s[k+1]) {
            k++;
        }
        next[i] = k;
    }
}

int main()
{
    string s("abababzabababaz");
    int n = s.size();
    vector<int> next(n, 0);

    get_next_arr(s, next);
    for(int i = 0; i < n; i++) {
        cout << next[i] << " ";
    } cout << endl;

    return 0;
}
