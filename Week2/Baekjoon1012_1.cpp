#include <bits/stdc++.h>
using namespace std;

bool visited[50][50];
int t, m, n, k, adj[50][50];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void DFS(int y, int x)
{
	visited[y][x] = 1;
	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (visited[ny][nx]) continue;
		if (adj[ny][nx]) {
			DFS(ny, nx);
		}
	}
}

int main()
{
	cin >> t;
	while (t--)
	{
		memset(visited, 0, sizeof(visited));
		memset(adj, 0, sizeof(adj));
		int connectedCompnentCnt = 0;

		cin >> m >> n >> k;
		while (k--)
		{
			int y, x;
			cin >> x >> y;
			adj[y][x] = 1;
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (!visited[i][j] && adj[i][j] == 1) 
				{
					DFS(i, j);
					connectedCompnentCnt++;
				}
			}
		}

		cout << connectedCompnentCnt << "\n";
	}
}