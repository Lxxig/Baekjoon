#include <bits/stdc++.h>
using namespace std;

string s;
int adj[100][100], visited[100][100];
int n, m;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void BFS(int y, int x)
{
	visited[y][x] = 1;
	queue<pair<int, int>> q;
	q.push({ y, x });

	while(q.size())
	{
		pair<int, int> p;
		p = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int ny = p.first + dy[i];
			int nx = p.second + dx[i];
			if (ny<0 || nx<0 || ny>=n || nx>=m || visited[ny][nx]) continue;
			if (adj[ny][nx] == 1)
			{
				visited[ny][nx] = visited[p.first][p.second] + 1;
				q.push({ ny, nx });
			}
		}
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		cin >> s;
		for (int j = 0; j < s.size(); ++j)
		{
			adj[i][j] = s[j] - '0';
		}
	}

	BFS(0, 0);

	std::cout << visited[n - 1][m - 1] << "\n";
}