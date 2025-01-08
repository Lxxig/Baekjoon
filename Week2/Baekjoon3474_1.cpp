#include <bits/stdc++.h>
using namespace std;

int t, numCnt5, numCnt2;
vector<int> ret;

void solve(int a)
{
	numCnt2 = 0;
	numCnt5 = 0;
	for (int i = 2; i <= a; i *= 2)
	{
		numCnt2 += a / i;
	}
	for (int i = 5; i <= a; i *= 5)
	{
		numCnt5 += a / i;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--)
	{
		int temp;
		cin >> temp;
		solve(temp);
		numCnt2 = min(numCnt2, numCnt5);
		std::cout << numCnt2 << "\n";
	}
}