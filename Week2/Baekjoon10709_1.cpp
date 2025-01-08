#include <bits/stdc++.h>
using namespace std;

int adj[100][100], h, w, previous;

int main()
{
	cin >> h >> w;

	for (int i = 0; i < h; ++i)
	{
		int hour = 1;
		previous = -1;
		for (int j = 0; j < w; ++j)
		{
			char temp;
			cin >> temp;
			if (temp == '.' && previous == -1)
			{
				adj[i][j] = -1;
			}
			if (temp == 'c') 
			{
				adj[i][j] = 0;
				hour = 1;
			}

			if (previous > -1 && temp != 'c')
			{
				adj[i][j] = hour;
				++hour;
			}

			previous = adj[i][j];
		}
	}

	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			std::cout << adj[i][j] << " ";
		}
		std::cout << "\n";
	}
}