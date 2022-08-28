// https://leetcode.cn/problems/minimum-size-subarray-sum/
// ��⣺�������ڣ����������С���������飬���Ȼ���������
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        int len, min_len = INT_MAX;

        // map<int, vector<int>> mp; // ��ֵ-��������

        int sum = nums[0];
        while(left <= right && right < n) {
            if(sum >= target) {
                min_len = min(min_len, right-left+1);
                sum -= nums[left];
                left += 1;
            } else {
                right += 1;
                if(right >= n) break;
                sum += nums[right];
            }
    
            // // ��¼������
            // if(sum >= target) mp[right - left + 1].push_back(left);
        }

        // // �����С����
        // vector<int> vt = mp[min_len];
        // for(int i=0; i<vt.size(); i++)
        //     cout << vt[i] << endl;

        return (min_len == INT_MAX) ? 0 : min_len;
    }
};

/*
7
[2,3,1,2,4,3]
2
*/
