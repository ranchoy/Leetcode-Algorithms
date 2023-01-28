// https://leetcode.cn/problems/greatest-english-letter-in-upper-and-lower-case/
class Solution {
    public String greatestLetter(String s) {
        int ans = -1;
        int n = s.length(), k;
        int[] mark = new int[26];

        for(int i = 0; i < n; i++) {
            boolean flag = (s.charAt(i) >= 'A' && s.charAt(i) <= 'Z');
            k = s.charAt(i) - (flag ? 'A' : 'a');

            if(mark[k] == 0) mark[k] = flag ? 1 : 2;
            if((mark[k] == 1 && flag == false) || (mark[k] == 2 && flag == true)) {
                ans = Math.max(ans, k);
            }
        }

        return (ans == -1) ? "" : String.valueOf((char)(ans + 'A'));
    }
}

/*
"AAAAA"
"lEeTcOdE"
"arRAzFif"
"nzmguNAEtJHkQaWDVSKxRCUivXpGLBcsjeobYPFwTZqrhlyOIfdM"

""
"E"
"R"
"Z"
*/