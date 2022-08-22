// link: https://leetcode-cn.com/problems/group-anagrams/
// 思路：hash表
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs);

int main()
{
	vector<string> strs;
	vector<vector<string>> ans;
	string str_arr[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
	strs.insert(strs.begin(), str_arr, str_arr+6);
	
	ans = groupAnagrams(strs);
	
	for(auto i=ans.begin(); i!=ans.end(); i++)
	{
		for(auto j=i->begin(); j!=i->end(); j++)
		{
			cout << *j << " ";
		}
		cout << endl;
	}
	
	return 0;
}

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
	vector<vector<string>> ans;
	unordered_map<string, vector<string>> hash_map;
	
	for(auto it=strs.begin(); it!=strs.end(); it++)
	{
		string key = *it;
		sort(key.begin(), key.end());
		hash_map[key].emplace_back(*it); // a vector
	}
	
	for(auto it=hash_map.begin(); it!=hash_map.end(); it++)
	{
		ans.emplace_back(it->second);
	}
	
	return ans;
}
