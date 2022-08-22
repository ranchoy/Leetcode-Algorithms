// https://leetcode-cn.com/problems/qJnOS7/
// 动态规划，s1和s2的最长公共子序列
class Solution {
public:
    // int longestCommonSubsequence(string text1, string text2) {
    //     int size1 = text1.size();
    //     int size2 = text2.size();
    //     int i, j;
    //     int dp[1010][1010] = {0}; // dp[i][j]表示s1长i,s2长j,公共子序列最大长度

    //     for(i=1; i<=size1; i++) {
    //         for(j=1; j<=size2; j++) {
    //             if(text1[i-1] == text2[j-1]) {
    //                 dp[i][j] = dp[i-1][j-1] + 1;
    //             } else {
    //                 dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    //             }
    //         }
    //     }

    //     // for(i=0; i<=size1; i++) {
    //     //     for(j=0; j<=size2; j++) {
    //     //         cout << dp[i][j] << " ";
    //     //     } cout<<endl;
    //     // }

    //     return dp[size1][size2];
    // }

    int longestCommonSubsequence(string text1, string text2) {
    	int i, j, prev;
		int dp[1010] = {0};
        int size1 = text1.size();
        int size2 = text2.size();
        
        for(i=1; i<=size1; i++) {
            prev = dp[0];
            for(j=1; j<=size2; j++) {
                int temp = dp[j]; // 这里, temp = dp[i-1][j-1]
                if(text1[i-1] == text2[j-1]) {
                    dp[j] = prev + 1;
                } else {
                    dp[j] = max(dp[j], dp[j-1]);
                }
                prev = temp;
            }
			// for(int k=0; k<=size2; k++)
			//     cout << dp[k] << " ";
			// cout << endl;
        }

        return dp[size2];
    }
    
	int longestCommonSubsequence(string text1, string text2) {
        int prev, cur;
        int dp[1010] = {0}; // 当text2长度为j时，lcs长度是dp[j]
        int len1 = text1.size();
        int len2 = text2.size();

        for(int i=1; i<=len1; i++) {
            prev = 0;
            for(int j=1; j<=len2; j++) {
                cur = dp[j]; // dp[i-1][j-1]
                if(text1[i-1] == text2[j-1]) {
                    dp[j] = prev + 1;
                } else {
                    dp[j] = max(dp[j], dp[j-1]); // max(dp[i-1][j], dp[i][j-1])
                }
                prev = cur; // 重要，上一层的dp[i-1][j-1]，不是当前层的dp[i][j]
            }
            // for(int k=0; k<=size2; k++)
			//     cout << dp[k] << " ";
			// cout << endl;
        }

        return dp[len2];
    }
};

/*
二维dp[i][j]: s1长度为i时且s2长度为j时，公共子序列长度；
if(s1[i-1] == s[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

一维dp[j]：s2长度为j时，公共子序列长度；
temp = dp[j];
prev = dp[i-1][j-1];
if(s1[i-1] == s2[j-1]) dp[j] = prev + 1;
else dp[j] = max(dp[j], dp[j-1])
prev = dp[j];

"abcba"
"abcbcba"

dp[i][j] = [
    0 0 0 0 0 0 0 0 
    0 1 1 1 1 1 1 1 
    0 1 2 2 2 2 2 2 
    0 1 2 3 3 3 3 3 
    0 1 2 3 4 4 4 4 
    0 1 2 3 4 4 4 5
]

一维dp[i]
0 1 1 1 1 1 1 1 
0 1 2 2 2 2 2 2 
0 1 2 3 3 3 3 3 
0 1 2 3 4 4 4 4 
0 1 2 3 4 4 4 5 

*/
