// https://leetcode.cn/problems/making-file-names-unique/
// 题解：哈希表HashMap，注意文件名后缀重复时，不仅更新不加数字的文件名次数，也要更新加数字的文件名次数。
class Solution {
    public String[] getFolderNames(String[] names) {
        int n = names.length;
        String[] ans = new String[n];
        Map<String, Integer> map_list = new HashMap<>();

        for(int i = 0; i < n; i++) {
            String name = names[i];

            if(!map_list.containsKey(name)) {
                ans[i] = name;
                map_list.put(name, 1); // <"name", 1>
            } else {
                int k = map_list.get(name);
                while(map_list.containsKey(getSuffixName(name, k))) {
                    k++;
                }
                ans[i] = getSuffixName(name, k);
                map_list.put(name, k + 1); // <"name", k+1>
                map_list.put(ans[i], 1);   // <"name(k)", 1>
            }
        }

        return ans;
    }

    String getSuffixName(String name, int k) {
        return (name + "(" + k + ")");
    }
}

/*
["wano","wano","wano","wano"]
["gta","gta(1)","gta","avalon"]
["kaido","kaido(1)","kaido","kaido(1)"]

["wano","wano(1)","wano(2)","wano(3)"]
["gta","gta(1)","gta(2)","avalon"]
["kaido","kaido(1)","kaido(1)","kaido(1)(1)"]
*/