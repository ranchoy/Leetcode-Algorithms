// https://leetcode-cn.com/problems/container-with-most-water/
// ̰���㷨+˫ָ�룬left��rightָ�����м俿�������Ƚ��߶�С�����п�����
class Solution {
public:
    int maxArea(vector<int>& height) {
        int mx = 0;
        int left = 0, right = height.size()-1;
        
        while(left < right) {
            int val = min(height[left], height[right]) * (right - left);
            mx = max(mx, val);
            if(height[left] > height[right]) right--;
            else left++;
        }
        return mx;
    }
};

/*
[1,8,6,2,5,4,8,3,7]
49
*/
