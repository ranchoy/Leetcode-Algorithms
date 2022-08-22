// https://leetcode-cn.com/problems/QTMn0o/
// ǰ׺�� + �Ȳ + HashMap
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // k = sum(i,...,j) = sum(0,..j) - sum(0,...,i)
        // ӳ��<sum, cnt>�� ���mp[sum(0,..,i)]���ڣ���ͳ�ƴ�������mp[sum-k]
        // ע��mp[0] = 1����Ϊ��numsֻ��һ��Ԫ��kʱ������Ϊ1
        unordered_map<int, int> mp; // <sum, k>
        mp[0] = 1;
        int sum = 0;
        int res = 0;
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            if(mp.count(sum-k) == 1)
                res += mp[sum-k];
            if(mp.count(sum) == 0)
                mp[sum] = 1;
            else
                mp[sum] += 1;
        }
        return res;
    }
};
