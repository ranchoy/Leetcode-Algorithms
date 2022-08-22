// 升序排列大顶堆，降序排列小顶堆
#include <iostream>
#include <vector>
using namespace std;

void heap_sort(vector<int> &nums);
void max_heap(vector<int> &nums, int i, int len);

int main()
{
	int i;
	vector<int> nums={5,1,1,2,8,8};

	heap_sort(nums);

	for(i=0; i<(int)nums.size(); i++)
	{
		cout << nums[i] << endl;	
	}
	
	return 0;
}

void heap_sort(vector<int> &nums)
{
	int i;
	int n = nums.size() - 1;

	for(i=n/2; i>=0; i--) // 首先,构造一个大顶堆
	{
		max_heap(nums, i, n);
	}

	for(i=n; i>=0; i--) // 堆首nums[0]和堆尾nums[i]互换,长度len-1,再排序
	{
		swap(nums[0], nums[i]);
		max_heap(nums, 0, i-1); // 已经排好了一个元素
	}
}

void max_heap(vector<int> &nums, int i, int n)
{
	int lson, rson, large_idx;
	for(; 2*i+1<=n; )
	{
		lson = 2*i+1;
		rson = 2*i+2;
		large_idx = i;
		
		if(lson <= n && nums[lson] > nums[i])
			large_idx = lson;
		if(rson <= n && nums[rson] > nums[large_idx])
			large_idx = rson;
		
		if(large_idx != i)
		{
			swap(nums[i], nums[large_idx]);
			i = large_idx; // 把大的提上来，小的沉下去
		}
		else
			break; // 重要终止条件
	}
}
