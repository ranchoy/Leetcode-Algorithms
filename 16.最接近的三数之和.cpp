// link: https://leetcode-cn.com/problems/3sum-closest/
// 思路：双指针
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 0xffff
using namespace std;

int threeSumClosest(vector<int>& nums, int target);

int main()
{
	int res, target = -5;
	int num_arr[] = {-1,2,1,-4};
	vector<int> nums(num_arr, num_arr+6);
	
	res = threeSumClosest(nums, target);
	cout << res << endl;
}

int threeSumClosest(vector<int>& nums, int target)
{
	int i, l, r;
	int size, sum, res=0xffff;
	
	size = nums.size();
	sort(nums.begin(), nums.end()); // sort
	
	for(i=0; i<size-2; i++)
	{
		l = i+1;
		r = size-1;

		while(l < r)
		{
			sum = nums[i] + nums[l] + nums[r];
			
			if(sum == target)
			{
				return sum;
			}
			else if(sum > target)
			{
				r--;
			}
			else
			{
				l++;
			}
			
			if(abs(res - target) > abs(sum - target))
			{
				res = sum;
			}
		}
	}
	
	return res;
}
