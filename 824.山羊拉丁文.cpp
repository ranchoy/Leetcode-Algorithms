class Solution {
public:
    string toGoatLatin(string s) {
        if(s.size() == 0) return s;
        string sub_str, new_s;
        int k = 0, cnts = 1;
        int left = 0, len = s.size();
        set<char> st({'a', 'e', 'i', 'o', 'u'});

        for(int i = 0; i < len; i++) {
            if(s[i] == ' ' || i == len-1) {
                int sub_len = (i == len-1) ? i-left+1 : i-left;
                sub_str = s.substr(left, sub_len);

                if(st.count(tolower(sub_str[0])) > 0) { // 重要
                    sub_str += "ma";
                } else {
                    char head_c = sub_str[0];
                    sub_str.erase(0, 1);
                    sub_str = (sub_str + head_c) + "ma";
                }
                k = 0;
                while(k < cnts) {
                    sub_str += 'a'; k++;
                }
                left = i + 1; // 更新left
                cnts++; // 更新cnts

                if(i < s.size()-1) {
                    new_s += sub_str + " ";
                } else {
                    new_s += sub_str;
                }
            }
        }

        return new_s;
    }
};

/*
"I speak Goat Latin"
"Imaa peaksmaaa oatGmaaaa atinLmaaaaa"

"The quick brown fox jumped over the lazy dog"
"heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
*/
