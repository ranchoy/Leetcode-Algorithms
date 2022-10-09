// https://leetcode.cn/contest/season/2022-fall/problems/1GxJYY/
// 题解：模拟+标记，需要记录起始索引s_idx和花索引idx，花索引大小不超过cnt;
class Solution {
public:
    const int N = 1e9+7;
    
    int beautifulBouquet(vector<int> &flowers, int cnt) {
        int res = 0;
        int type, s_idx = 0;
        int n = flowers.size();
        map<int, int> mps; // type, count
        map<int, queue<int>> mps_idx; // type, idx_arr
        
        for(int i = 0; i < n; i++) {
            type = flowers[i];
            if(mps[type] < cnt) {
                mps[type]++;
                res = (res + i - s_idx + 1) % N;
            } else {
                while(mps_idx[type].size() > cnt) {
                    mps_idx[type].pop();  // important!
                }
                s_idx = max(s_idx, mps_idx[type].front() + 1); // important!
                res = (res + i - s_idx + 1) % N;

            }
            cout << s_idx << " " << i << " " << res << endl;
            mps_idx[type].push(i); // insert idx of flower
        }
        
        return res;
    }
};

/*
[1,2,3,2]
1
[5,3,3,3]
2
[1,10,1,10,1,10]
2
[98495,98495,99801,34717,34717,99801,98495,99801,99801,98495]
2

8
8
18
39
*/
