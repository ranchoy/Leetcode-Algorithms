// https://leetcode.cn/problems/find-longest-subarray-lcci/
// 题解：前缀和 + 哈希表HashMap，alpha_num表示[0,i]中多出的字母个数，当出现两次alpha_num（第一次索引idx）时，子数组的范围是[idx+1, idx+ans_len]。注意初始哈希表HashMap插入元素<0,-1>。
class Solution {
    public String[] findLongestSubarray(String[] array) {
        int n = array.length;
        int alpha_num = 0, ans_idx = 0, ans_len = 0;
        Map<Integer,Integer> map_list = new HashMap<>();

        map_list.put(0, -1); // important!
        for(int i = 0; i < n; i++) {
            alpha_num = is_alpha(array[i]) ? alpha_num + 1 : alpha_num - 1;

            if(map_list.containsKey(alpha_num)) {
                int idx = map_list.get(alpha_num);
                if(i - idx > ans_len) {
                    ans_idx = idx + 1;
                    ans_len = i - idx;
                }
            } else {
                map_list.put(alpha_num, i); // <字母多的个数，索引>
            }
        }

        if(ans_len == 0) return new String[0]; // 不存在

        String[] ans = new String[ans_len];
        System.arraycopy(array, ans_idx, ans, 0, ans_len); // copy array list.

        return ans;
    }

    public boolean is_alpha(String s) {
        char c = s.charAt(0);
        if(Character.isUpperCase(c) || Character.isLowerCase(c)) {
            return true;
        }
        return false;
    }
}

/*
["A","A"]
["A","B","1","2","A","B"]
["A","1","B","C","D","2","3","4","E","5","F","G","6","7","H","I","J","K","L","M"]

[]
["A","B","1","2"]
["A","1","B","C","D","2","3","4","E","5","F","G","6","7"]
*/