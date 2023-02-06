// https://leetcode.cn/problems/take-gifts-from-the-richest-pile/
class Solution {
    public long pickGifts(int[] gifts, int k) {
        long ans = 0;
        PriorityQueue<Integer> pri_que = new PriorityQueue<>(new Comparator<Integer>() {
            @Override
            public int compare(Integer a, Integer b) {
                return b - a;
            }
        });
        for(int item : gifts) pri_que.offer(item);

        while(k > 0) {
            int t = pri_que.poll();
            if(t == 0) break;
            pri_que.offer((int) Math.sqrt(t));
            k--;
        }
        while(!pri_que.isEmpty()) {
            ans += pri_que.poll();
        }

        return ans;
    }
}