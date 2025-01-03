#include <bits/stdc++.h>
using namespace std;

string s;

bool isVowel(char c)
{
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main()
{
	while (cin >> s)
	{
		if (s == "end") break;
		bool flag = false;
		bool includeV = false;
		int vCnt = 0;  // 모음 카운트
		int cCnt = 0;  // 자음 카운트
		char preAlpha = -1;
		char curAlpha;


		for (int i = 0; i < s.size(); ++i)
		{
			curAlpha = s[i];
			if (isVowel(curAlpha))
			{
				includeV = true;
				vCnt++;
				cCnt = 0;
			}
			else
			{
				vCnt = 0;
				cCnt++;
			}
			if (vCnt == 3 || cCnt == 3) flag = true;
			if (curAlpha == preAlpha && curAlpha != 'e' && curAlpha != 'o') flag = true;
			preAlpha = curAlpha;
		}

		if (!includeV) flag = true;
		if (flag) std::cout << '<' << s << '>' << " is not acceptable.\n";
		else std::cout << '<' << s << '>' << " is acceptable.\n";
	}
}