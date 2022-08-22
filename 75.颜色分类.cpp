#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int>& nums);
void sortColors1(vector<int>& nums);

int main()
{
	int i;
	vector<int> nums = {2,0,2,1,1,0};
	
	sortColors(nums);
	
	for(i=0; i<nums.size(); i++)
	{
		cout << nums[i] << " ";
	}cout << endl;
	
	return 0;
}

void sortColors(vector<int>& nums)
{
	int i, r, g, b, temp;
	int v_size = nums.size();
	
	r = g = b = 0;
	for(i=0; i<v_size; i++)
	{
		temp = nums[i];
		
		nums[b] = 2;
		b++;
		
		if(temp <= 1)
		{
			nums[g] = 1;
			g++;
		}
		
		if(temp == 0)
		{
			nums[r] = 0;
			r++;
		}
	}
}

void sortColors1(vector<int>& nums)
{
	int max_size = 301;
	int i, j, k, v_size;
	int num_arr[305] = {0};
	v_size = nums.size();
	
	for(i=0; i<v_size; i++)
	{
		k = nums[i];
		num_arr[k] ++;
	}
	
	if(v_size > 1)
	{
		nums.clear();
		for(i=0; i<max_size; i++)
		{
			k = num_arr[i];
			for(j=0; j<k; j++)
			{
				nums.push_back(i);
			}
		}
	}
}
