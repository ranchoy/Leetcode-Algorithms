// https://leetcode-cn.com/problems/add-binary/
#include <bits/stdc++.h>
using namespace std;

string addBinary(string a, string b)
{
	string res;
	int i, k, pre, max_len, bit_a, bit_b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	max_len = max(a.size(), b.size());
	
	pre = 0;
	for(i=0; i<max_len; i++)
	{
		bit_a = (i < a.size()) ? (int)(a[i] - '0') : 0;
		bit_b = (i < b.size()) ? (int)(b[i] - '0') : 0;
		k = bit_a + bit_b + pre;
		res.push_back((k%2==0) ? '0' : '1');
		pre = k / 2;
	}
	if(pre == 1)
		res.push_back('1');
	reverse(res.begin(), res.end());
	return res;
}

int main()
{
	string res;
	string a("11");
	string b("1");
	
	res = addBinary(a, b);
	cout << res << endl;
	
	return 0;
}
