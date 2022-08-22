// link: https://leetcode-cn.com/problems/beautiful-arrangement/
// 思路: DFS搜索
#include <iostream>
#include <vector>
using namespace std;

int countArrangement(int n);
int countArrangement_1(int n);
int dfs(int n, int i, int *vis);

int main()
{
	int res;
	int n = 15;
	
	res = countArrangement(n);
	
	cout << res << endl;
	
	return 0;
}

// DFS + 状态压缩
// dp[i][stste]表示在第i个数时状态state对应的数为dp[i][state]
int countArrangement(int n)
{
	int i,k,state;
	int mask = 1 << n;
	int dp[15+1][1<<15]={0};
	dp[0][0] = 1;
	
	for(i=1; i<=n; i++) // n个数
	{
		for(state=0; state<mask; state++) // 所有状态
		{
			for(k=1; k<=n; k++) // 位置i选的数是k
			{
				if(((state>>(k-1)) & 1) == 0) // state第k位必须是1
					continue;	
				if(k%i!=0 && i%k!=0) // 必须满足整除关系
					continue;
				dp[i][state] += dp[i-1][state & (~(1<<(k-1)))]; // 没有k时的状态
			}
		}
	}
	
	return dp[n][mask-1];
}


int countArrangement_1(int n)
{
	int vis[20] = {0};
	return dfs(n, 1, vis);
}

int dfs(int n, int i, int *vis)
{
	if(i > n) // 此时，序列最长，存在一个结果
		return 1;
	
	int num;
	int res = 0;
	
	for(num=1; num<=n; num++)
	{
		if(vis[num]==0 && (num%i==0 || i%num==0))
		{
			vis[num] = 1;
			res += dfs(n, i+1, vis);
			vis[num] = 0;
		}
	}
	
	return res;
}
