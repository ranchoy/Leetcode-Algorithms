// https://leetcode.cn/problems/subdomain-visit-count/
// 题解：stringstream流+字符串分割，注意substr()和to_string()函数的参数列表。
class Solution {
public:
    vector<string> subdomainVisits(vector<string> &cpdomains) {
        string temp;
        vector<string> res;
        map<string, int> mps;
        int n = cpdomains.size(), cnt;
        
        for(int i = 0; i < n; i++) {
            stringstream ss(cpdomains[i]);
            ss >> cnt >> temp;
            mps[temp] += cnt;
            for(int k = 0; k < temp.size(); k++) {
                if(temp[k] == '.') {
                    mps[temp.substr(k+1)] += cnt;
                }
            }
        }

        for(auto it = mps.begin(); it != mps.end(); it++) {
            res.push_back(to_string(it->second) + " " + it->first);
        }

        return res;
    }
};

/*
["9001 discuss.leetcode.com"]

["9001 com","9001 discuss.leetcode.com","9001 leetcode.com"]
*/
