#include <bits/stdc++.h>
using namespace std;

bool visited[100][100];
int adj[100][100], m, n, k, componentCnt, cnt;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
vector<int> vCnt;

void DFS(int y, int x)
{
	cnt++;
	visited[y][x] = 1;
	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= m || nx >= n)continue;
		if (visited[ny][nx]) continue;
		if (!adj[ny][nx]) DFS(ny, nx);
	}
}

int main()
{
	cin >> m >> n >> k;
	while (k--)
	{
		int ly, lx, ry, rx;
		cin >> lx >> ly >> rx >> ry;
		for (int i = ly; i < ry; ++i)

		{
			for (int j = lx; j < rx; ++j)
			{
				adj[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (!visited[i][j] && adj[i][j] == 0)
			{
				cnt = 0;
				DFS(i, j);
				componentCnt++;
				vCnt.push_back(cnt);
			}
		}
	}

	sort(vCnt.begin(), vCnt.end());
	std::cout << componentCnt << "\n";
	for (int v : vCnt)
	{
		std::cout << v << " ";
	}
}