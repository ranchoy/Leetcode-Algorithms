// links: https://leetcode-cn.com/problems/merge-intervals/
// 思路: 区间合并，左端排序
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals);

int main()
{
	int i;
	int nums[][2] = {{1,3}, {8,10}, {2,6}, {15, 18}};
	vector<vector<int>> temp, ans;

	for(i=0; i<4; i++)
	{
		temp.push_back({nums[i][0], nums[i][1]});
	}
		
	ans = merge(temp);	
	for(i=0; i<ans.size(); i++)
	{
		cout << ans[i][0] << " " << ans[i][1] << endl;
	}
	
	return 0;
}

vector<vector<int>> merge(vector<vector<int>>& intervals)
{
	int i, l, r, v_size;
	vector<vector<int>> ans;
	
	sort(intervals.begin(), intervals.end()); // sort
	v_size = intervals.size();
	
	for(i=0; i<v_size; i++)
	{
		l = intervals[i][0];
		r = intervals[i][1];
		if(ans.empty() || ans.back()[1] < l)
			ans.push_back({l, r});
		else
			ans.back()[1] = max(ans.back()[1], r);
	}
	
	return ans;
}
