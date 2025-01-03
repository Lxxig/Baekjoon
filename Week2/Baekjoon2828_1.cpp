#include <bits/stdc++.h>
using namespace std;

int n, m, l, r, b, ret, j;

int main() 
{
	cin >> n >> m;
	cin >> j;
	l = 1; r = m;
	while (j--)
	{
		cin >> b;
		if (b > r)
		{
			int s = b - r;
			r += s;
			l += s;
			ret += s;
		}
		else if (b<=r && b>=l)
		{
			continue;
		}
		else if (b < l)
		{
			int s = l - b;
			r -= s;
			l -= s;
			ret += s;
		}
	}
	std::cout << ret << "\n";
}