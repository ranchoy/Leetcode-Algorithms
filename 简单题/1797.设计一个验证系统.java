// https://leetcode.cn/problems/design-authentication-manager/
// 题解：哈希表HashMap，注意rnew()方法的设计。
class AuthenticationManager {

    private int timeToLive;
    private Map<String, Integer> map_list; // <tokenId, currTime>

    public AuthenticationManager(int timeToLive) {
        this.timeToLive = timeToLive;
        this.map_list = new HashMap<>();
    }

    public void generate(String tokenId, int currentTime) {
        map_list.put(tokenId, currentTime + timeToLive);
    }

    public void renew(String tokenId, int currentTime) {
        if(map_list.containsKey(tokenId) && map_list.get(tokenId) > currentTime) {
            map_list.put(tokenId, currentTime + timeToLive);
        }
    }

    public int countUnexpiredTokens(int currentTime) {
        int count = 0;
        for(String k : map_list.keySet()) {
            if(map_list.get(k) > currentTime) {
                count++;
            }
        }

        return count;
    }
}
/*
["AuthenticationManager","renew","generate","countUnexpiredTokens","generate","renew","renew","countUnexpiredTokens"]
[[5],["aaa",1],["aaa",2],[6],["bbb",7],["aaa",8],["bbb",10],[15]]
["AuthenticationManager","renew","countUnexpiredTokens","countUnexpiredTokens","generate","generate","renew","generate","generate","countUnexpiredTokens","countUnexpiredTokens","countUnexpiredTokens","renew","countUnexpiredTokens","countUnexpiredTokens","countUnexpiredTokens","generate","countUnexpiredTokens","renew"]
[[13],["ajvy",1],[3],[4],["fuzxq",5],["izmry",7],["puv",12],["ybiqb",13],["gm",14],[15],[18],[19],["ybiqb",21],[23],[25],[26],["aqdm",28],[29],["puv",30]]

[null,null,null,0,null,null,null,0]
[null,null,0,0,null,null,null,null,null,4,3,3,null,2,2,2,null,2,null]
*/

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager obj = new AuthenticationManager(timeToLive);
 * obj.generate(tokenId,currentTime);
 * obj.renew(tokenId,currentTime);
 * int param_3 = obj.countUnexpiredTokens(currentTime);
 */