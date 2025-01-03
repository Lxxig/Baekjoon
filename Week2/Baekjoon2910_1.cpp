#include <bits/stdc++.h>
using namespace std;

int n, c;
map<int, int> m1;
map<int, int> m2;

bool cmp(int left, int right)
{
	if (m1[left] == m1[right])
	{
		return m2[left] < m2[right];
	}

	return m1[left] > m1[right];
}

int main()
{
	cin >> n >> c;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		m1[temp]++;
		m2.insert({ temp, i });
		v[i] = temp;
	}

	sort(v.begin(), v.end(), cmp);

	for (int i : v)
	{
		std::cout << i << " ";
	}
}