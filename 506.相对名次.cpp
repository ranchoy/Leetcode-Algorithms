#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> findRelativeRanks(vector<int>& score);
void max_heap(vector<int>& nums, int i, int len);
void heap_sort(vector<int>& nums);

int main()
{
	int i;
	vector<string> vstr_arr;
	vector<int> nums = {5, 4, 3, 3, 2, 1};
	
	heap_sort(nums);
	
	for(i=0; i<nums.size(); i++)
	{
		cout << nums[i] << endl;
	}
	
	vstr_arr = findRelativeRanks(nums);
	cout << vstr_arr.size() << endl;
	for(i=0; i<vstr_arr.size(); i++)
		cout << vstr_arr[i] << endl;

	return 0;
}

vector<string> findRelativeRanks(vector<int>& score)
{
	int i, n_size;
	
	map<int, string> s_map;
	vector<string> vstr_arr;
	vector<int> nums = {score.begin(), score.end()};
	
	heap_sort(nums); // sort
	n_size = (int)nums.size();
	
	for(i=0; i<n_size; i++)
	{
		if(s_map.find(nums[i]) == s_map.end())
		{
			if(i == 0)
				s_map[nums[i]] = "Gold Medal";
			else if(i == 1)
				s_map[nums[i]] = "Silver Medal";
			else if(i == 2)
				s_map[nums[i]] = "Bronze Medal";
			else
				s_map[nums[i]] = to_string(i+1);
		}
	}

	for(i=0; i<n_size; i++)
		vstr_arr.push_back(s_map[score[i]]);
	
	return vstr_arr;
}


void max_heap(vector<int>& nums, int i, int len)
{
	// 升序排列: num[i]>=nums[l] && nums[i]>=nums[r]
	// 降序排列: nums[i]<=nums[l] && nums[i]<=nums[r]
	int l,r,large;
	for(; 2*i+1<=len; )
	{
		large = i;
		l = 2*i + 1;
		r = 2*i + 2;
		
		if(l<=len && nums[l] < nums[i])
			large = l;

		if(r<=len && nums[r] < nums[large])
			large = r;
		
		if(i!=large)
		{
			swap(nums[i], nums[large]);
			i = large;
		}
		else
		{
			break;
		}
	}
}

void heap_sort(vector<int>& nums)
{
	int i;
	int len = nums.size() - 1;
	
	for(i=len/2; i>=0; i--) // 建大根堆
		max_heap(nums, i, len);

	for(i=len; i>=0; i--) // 排序,堆顶于堆低互换
	{
		swap(nums[0], nums[len]);
		len = len - 1;
		max_heap(nums, 0, len);
	}	
}
