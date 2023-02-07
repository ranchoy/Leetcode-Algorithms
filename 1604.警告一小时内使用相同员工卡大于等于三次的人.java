// https://leetcode.cn/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/
// 题解：哈希表HashMap+排序Collections.sort()，注意返回排序后的结果。
class Solution {
    public List<String> alertNames(String[] keyName, String[] keyTime) {
        int n = keyName.length;
        List<String> ans = new ArrayList<>();
        Map<String, List<Integer>> map_list = new HashMap<>();

        for(int i = 0; i < n; i++) {
            String k = keyName[i], v = keyTime[i];
            map_list.putIfAbsent(k, new ArrayList<Integer>());
            int hour = (v.charAt(0) - '0') * 10 + (v.charAt(1) - '0');
            int minute = (v.charAt(3) - '0') * 10 + (v.charAt(4) - '0');
            map_list.get(k).add(hour * 60 + minute);
        }

        for(var name : map_list.keySet()) {
            List<Integer> t = map_list.get(name);
            Collections.sort(t);
            for(int i = 2; i < t.size(); i++) {
                if(t.get(i) - t.get(i-2) <= 60) {
                    ans.add(name); break;
                }
            }
        }

        Collections.sort(ans);
        return ans;
    }
}

/*
["daniel","daniel","daniel","luis","luis","luis","luis"]
["10:00","10:40","11:00","09:00","11:00","13:00","15:00"]
["leslie","leslie","leslie","clare","clare","clare","clare"]
["13:00","13:20","14:00","18:00","18:51","19:30","19:49"]

["daniel"]
["clare","leslie"]
*/