#include<bits/stdc++.h>
using namespace std;

vector<int> get_next_arr(string s) {
    int n = s.size(), k = -1; // k表示下标。
    vector<int> next(n, 0);

    next[0] = next[1] = -1; // next[i]表示s[0,i]内前后缀相等的最长前缀结尾索引。
    for(int i = 2; i < n; i++) {
        while(k > -1 && next[i] != next[k+1]) {
            k = next[k];
        }

        if(next[i] == next[k+1]) {
            k++;
        }
        next[i] = k;
    }

    return next;
}

bool KMP(string s1, string s2) {
    int len = 0;
    int n = s1.size(), k = -1;
    vector<int> next = get_next_arr(s2);

    for(int i = 0; i < n; i++) {
        while(k > -1 && s1[i] != s2[k+1]) {
            k = next[k];
        }

        if(s1[i] == s2[k+1]) {
            k++;
        }
        len = max(len, k + 1);
        if(len == s2.size()) return true;
    }

    return false;
}

int main()
{
    string s1("abcabcc123"), s2("abcc");
    cout << s1 << " " << s2 << endl;
    bool is_substr = KMP(s1, s2);

    cout << is_substr << endl;
    return 0;
}

/*
"abcabcc123"
"abcc"

true
*/
