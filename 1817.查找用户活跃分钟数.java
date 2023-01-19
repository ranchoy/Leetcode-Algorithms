// https://leetcode.cn/problems/finding-the-users-active-minutes/
// 题解：HashMap的使用，注意Map.Entry<K,V>的遍历方式。
class Solution {
    public int[] findingUsersActiveMinutes(int[][] logs, int k) {

        int n = logs.length;
        Map<Integer, Set<Integer>> map_list = new HashMap<Integer, Set<Integer>>();

        for(int[] log : logs) {
            int id = log[0], time = log[1];
            map_list.putIfAbsent(id, new HashSet<Integer>());
            map_list.get(id).add(time);
        }

        int[] ans = new int[k];
        for(Set<Integer> times : map_list.values()) {
            ans[times.size() - 1] ++;
        }

        return ans;
    }
}

/*
[[1,1],[2,2],[2,3]]
4
[[0,5],[1,2],[0,2],[0,5],[1,3]]
5

[1,1,0,0]
[0,2,0,0,0]
*/