#include <bits/stdc++.h>
using namespace std;

int n, adj[64][64];
vector<char> ret;

void solve(int y, int x, int size)
{
	int temp = adj[y][x];
	bool flag = false;
	for (int iy = y; iy < y + size; ++iy)
	{
		for (int ix = x; ix < x + size; ++ix)
		{
			if (temp != adj[iy][ix]) 
			{
				flag = true;
				break;
			}
		}
		if (flag) break;
	}

	if (flag)
	{
		ret.push_back('(');
		solve(y, x, size / 2);
		solve(y, x + size / 2, size / 2);
		solve(y + size / 2, x, size / 2);
		solve(y + size / 2, x + size / 2, size / 2);
		ret.push_back(')');
	}
	else
	{
		ret.push_back(temp + '0');
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		for (int j = 0; j < n; ++j)
		{
			adj[i][j] = s[j] - '0';
		}
	}

	solve(0, 0, n);

	for (char i : ret)
	{
		std::cout << i;
	}
}