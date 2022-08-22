// https://leetcode-cn.com/problems/4sum/
// 双指针，注意极端情况，nums[i] + nums[j] + nums[left] + nums[right]
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 0xffff
using namespace std;

vector<vector<int> > fourSum(vector<int>& nums, int target);

int main()
{
	int i, target = 4000000000;
	int num_arr[] = {1000000000, 1000000000, 1000000000, 1000000000};
	vector<vector<int> > res;
	vector<int> nums(num_arr, num_arr+6);
	
	res = fourSum(nums, target);
	vector<vector<int> >::iterator iter;
	
	for(iter=res.begin(); iter!=res.end(); iter++)
	{
		for(i=0; i<(int)(*iter).size(); i++)
			cout << (*iter)[i] << " ";
		cout << endl;
	}
}

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // 双指针，nums[i] + nums[j] + nums[left] + nums[right] 与 target 的关系，注意筛出不合适条件
        if(nums.size() == 0) return {};

        long long temp;
        int size = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for(int i=0; i<size-3; i++) {
            if(i>0 && nums[i]==nums[i-1]) // 重要
                continue;
            // 筛除极端情况
            temp = (long long)nums[i] + (long long)nums[i+1] + (long long)nums[i+2] + (long long)nums[i+3];
            if(temp > target) break;
            temp = (long long)nums[i] + (long long)nums[size-3] + (long long)nums[size-2] + (long long)nums[size-1];
            if(temp < target) continue;

            for(int j=i+1; j<size-2; j++) {
                if(j>i+1 && nums[j]==nums[j-1]) // 重要
                    continue;
                temp = (long long)nums[i] + (long long)nums[j] + (long long)nums[j+1] + (long long)nums[j+2];
                if(temp > target) break;
                temp = (long long)nums[i] + (long long)nums[j] + (long long)nums[size-2] + (long long)nums[size-1];
                if(temp < target) continue;

                int left = j + 1;
                int right = size - 1;
                while(left < right) {
                    temp = (long long)nums[i] + (long long)nums[j] + (long long)nums[left] + (long long)nums[right];
                    if(temp < target) {
                        left++;
                    } else if (temp > target) {
                        right--;
                    } else {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        // 去重
                        while(left < right && nums[left] == nums[left+1]) left++;
                        while(left < right && nums[right] == nums[right-1]) right--;
                        left++;
                        right--;
                    }
                }
            }
        }
        return res;
    }
};
