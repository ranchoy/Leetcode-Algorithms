// https://leetcode.cn/problems/count-vowel-strings-in-ranges/
// 题解：前缀和，dp[i+1]表示[0,i]区间内的元音字符串数。
class Solution {
    public static final Set<Character> hash_list = new HashSet<>(Arrays.asList('a', 'o', 'e', 'i', 'u'));

    public int[] vowelStrings(String[] words, int[][] queries) {
        int n = words.length, m = queries.length;
        int[] ans = new int[m];
        int[] dp = new int[n + 1];

        for(int i = 0; i < n; i++) {
            int len = words[i].length();
            Character t1 = words[i].charAt(0), t2 = words[i].charAt(len - 1);
            dp[i + 1] = dp[i];
            if(hash_list.contains(t1) && hash_list.contains(t2)) {
                dp[i + 1]++;
            }
        }

        for(int i = 0; i < m; i++) {
            int a = queries[i][0], b = queries[i][1];
            ans[i] = dp[b + 1] - dp[a];
        }

        return ans;
    }
}

/*
["aba","bcb","ece","aa","e"]
[[0,2],[1,4],[1,1]]
["bzmxvzjxfddcuznspdcbwiojiqf","mwguoaskvramwgiweogzulcinycosovozppl","uigevazgbrddbcsvrvnngfrvkhmqszjicpieahs","uivcdsboxnraqpokjzaayedf","yalc","bbhlbmpskgxmxosft","vigplemkoni","krdrlctodtmprpxwditvcps","gqjwokkskrb","bslxxpabivbvzkozzvdaykaatzrpe","qwhzcwkchluwdnqjwhabroyyxbtsrsxqjnfpadi","siqbezhkohmgbenbkikcxmvz","ddmaireeouzcvffkcohxus","kjzguljbwsxlrd","gqzuqcljvcpmoqlnrxvzqwoyas","vadguvpsubcwbfbaviedr","nxnorutztxfnpvmukpwuraen","imgvujjeygsiymdxp","rdzkpk","cuap","qcojjumwp","pyqzshwykhtyzdwzakjejqyxbganow","cvxuskhcloxykcu","ul","axzscbjajazvbxffrydajapweci"]
[[4, 4],[6, 17],[10, 17],[9, 18],[17, 22],[5, 23],[2, 5],[17, 21],[5, 17],[4, 8],[7, 17],[16, 19],[7, 12],[9, 20],[13, 23],[1, 5],[19, 19]]

[2,3,0]
[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
*/