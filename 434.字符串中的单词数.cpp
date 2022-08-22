// https://leetcode-cn.com/problems/number-of-segments-in-a-string/
#include <bits/stdc++.h>
using namespace std;

int countSegments(string s);

int main()
{
	string s = ", , , ,   a, aaa";
	
	cout << countSegments(s) << endl;
	
	return 0;
}

int countSegments(string s)
{
	char ch;
	int res = 0;
	int len = s.size();
	
	for(int i=0; i<len; i++)
	{
		if((i==0 && s[i]!=' ') || (i>0 && s[i-1]==' ' && s[i]!=' '))
			res +=1 ;
	}
		
	return res;
}
