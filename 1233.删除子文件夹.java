import java.util.*;
// https://leetcode.cn/problems/remove-sub-folders-from-the-filesystem/
// 题解：排序+思维，如果folder[i]不是ans[last]的子串，则将folder[i]加入ans数组。
class Solution {
    public List<String> removeSubfolders(String[] folder) {
        List<String> ans = new ArrayList<String>();
        Arrays.sort(folder); ans.add(folder[0]);

        for (int i = 1; i < folder.length; ++i) {
            int pre = ans.get(ans.size() - 1).length();
            if (!(pre < folder[i].length() && ans.get(ans.size() - 1).equals(folder[i].substring(0, pre)) && folder[i].charAt(pre) == '/')) {
                ans.add(folder[i]);
            }
        }
        return ans;
    }
}

/*
["/a/b/c","/a/b/ca","/a/b/d"]
["/ap/ax/ay","/ap/aq/au","/aa/ab/af","/aa/ai/am","/ap/ax","/ap/aq/ar"]

["/a/b/c","/a/b/ca","/a/b/d"]
["/aa/ab/af","/aa/ai/am","/ap/aq/ar","/ap/aq/au","/ap/ax"]
*/