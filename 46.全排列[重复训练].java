// https://leetcode.cn/problems/permutations/
// 题解：深度优先遍历DFS，注意vis[]标记数组的使用，以及ArrayList的深浅拷贝。
class Solution {
    private List<List<Integer>> ans = new ArrayList<>();

    public List<List<Integer>> permute(int[] nums) {
        int n = nums.length;
        boolean[] vis = new boolean[n];
        List<Integer> perm_arr = new ArrayList<>();

        dfs(nums, perm_arr, vis, 0);
        return ans;
    }

    void dfs(int[] nums, List<Integer> perm_arr, boolean[] vis, int i) {
        if(i == nums.length) {
            ans.add(new ArrayList<>(perm_arr)); // deep copy.
            return;
        }

        for(int k = 0; k < nums.length; k++) {
            if(!vis[k]) {
                vis[k] = true;
                perm_arr.add(nums[k]);
                dfs(nums, perm_arr, vis, i + 1);
                perm_arr.remove(perm_arr.size() - 1);
                vis[k] = false;
            }
        }
    }
}

/*
[1,2,3]

[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/