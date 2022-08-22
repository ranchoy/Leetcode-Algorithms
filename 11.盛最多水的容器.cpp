// https://leetcode-cn.com/problems/container-with-most-water/
// 贪心算法+双指针，left和right指针向中间靠近，优先将高度小的向中靠近。
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
