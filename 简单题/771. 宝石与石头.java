// https://leetcode.cn/problems/jewels-and-stones/
// 题解：Hash表，注意接口函数的使用。
import java.util.*;

class Solution {
    public int numJewelsInStones(String jewels, String stones) {
        int ans = 0;
        Set<Character> set_list = new HashSet<>();

        for(int i = 0; i < jewels.length(); i++) {
            set_list.add(jewels.charAt(i));
        }
        for(int i = 0; i < stones.length(); i++) {
            Character c = stones.charAt(i);
            if(set_list.contains(c)) ans++;
        }

        return ans;
    }
}

/*
"aA"
"aAAbbbb"
"z"
"ZZ"

3
0
*/