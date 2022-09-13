// https://leetcode.cn/problems/minimum-area-rectangle/
// Ã‚Ω‚£∫map∫Õset
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int i, j, min_size;
        int x1, y1, x2, y2;
        int len = (int)points.size();
        unordered_map<int, unordered_set<int>> mp;
    
        for(i=0; i<len; i++) {
            mp[points[i][0]].insert(points[i][1]);
        }

        min_size = INT_MAX;
        for(i=0; i<len; i++) {
           for(j=i+1; j<len; j++) {
               x1 = points[i][0]; y1 = points[i][1];
               x2 = points[j][0]; y2 = points[j][1];

                if(mp.count(x1) > 0 && mp[x1].count(y2) > 0 &&
                    mp.count(x2) > 0 && mp[x2].count(y1) > 0 &&
                    abs((x1-x2)*(y1-y2))>0) {
                    min_size = min(min_size, abs((x1-x2)*(y1-y2)));
                }
            }
        }
        return min_size == INT_MAX ? 0 : min_size;
    }
};

/*
[[1,1],[1,3],[3,1],[3,3],[2,2]]
[[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]

4
2
*/
