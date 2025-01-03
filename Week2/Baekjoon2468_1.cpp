#include <bits/stdc++.h>
using namespace std;

bool visited[100][100];
int n, adj[100][100], ret = -1, depth;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

void DFS(int y, int x)
{
	visited[y][x] = 1;
	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (visited[ny][nx]) continue;
		if (adj[ny][nx] > depth) DFS(ny, nx);
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> adj[i][j];
		}
	}

	for (int i = 0; i < 100; ++i)
	{
		memset(visited, 0, sizeof(visited));
		int connectedComponent = 0;
		depth = i;
		for (int y = 0; y < n; ++y)
		{
			for (int x = 0; x < n; ++x)
			{
				if (!visited[y][x] && adj[y][x] > depth)
				{
					DFS(y, x);
					connectedComponent++;
				}
			}
		}
		ret = max(ret, connectedComponent);
	}

	cout << ret << "\n";
}