// https://leetcode.cn/problems/determine-if-two-events-have-conflict/
// 题解：模拟，通过String类的比较函数直接进行区间是否存在交集判断。
class Solution {
    public boolean haveConflict(String[] event1, String[] event2) {
        return event1[0].compareTo(event2[1]) <= 0 && event1[1].compareTo(event2[0]) >= 0;
    }
}

/*
["01:15","02:00"]
["02:00","03:00"]
["01:00","02:00"]
["01:20","03:00"]
["10:00","11:00"]
["14:00","15:00"]

true
true
false
*/