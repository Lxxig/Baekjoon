#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> ret;

void Solve(string s)
{
	while (true)
	{
		if (s.front() == '0') s = s.substr(1);
		else break;

		if (s.size() == 0) break;
	}

	if (s.size())
	{
		ret.push_back(s);
	}
	else
	{
		ret.push_back("0");
	}
}

int main()
{
	cin >> n;

	while (n--)
	{
		string s;
		string temp = "";
		cin >> s;
		for (int i = 0; i < s.size(); ++i)
		{
			if ('0' <= s[i] && s[i] <= '9')
			{
				temp += s[i];
			}
			else if(temp.size())
			{
				Solve(temp);
				temp = "";
			}
		}
		if (temp.size())
		{
			Solve(temp);
		}
	}

	if(ret.size()) 
	{
		sort(ret.begin(), ret.end(), [](string left, string right)->bool 
			{ 
				if (left.size() == right.size())
					return left < right;
				return left.size() < right.size();
			});
		for (string i : ret)
		{
			std::cout << i << "\n";
		}
	}
}