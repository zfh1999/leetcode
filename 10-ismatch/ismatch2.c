#include <stdio.h>
#include <stdlib.h>

typedef unsigned char bool;

#define MATCH(x, y) (x == y || y == '.')

bool is_match_helper(char *s, char *p, int s_size, int p_size)
{
	if (s_size == 0)
	{
		return 0;
	}
	else
	{
		return MATCH(s[s_size - 1], p[p_size - 1]);
	}
}

bool isMatch(char *s, char *p)
{
	int sl = strlen(s);
	int pl = strlen(p);

	bool dp[sl + 1][pl + 1];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for (int i = 0; i <= sl; ++i)
	{
		for (int j = 1; j <= pl; ++j)
		{
			if (p[j - 1] == '*')
			{
				if (is_match_helper(s, p, i, j - 1))
				{
					dp[i][j] |= dp[i - 1][j] || dp[i][j - 2];
				}
				else
				{
					dp[i][j] = dp[i][j - 2];
				}
			}
			else
			{
				dp[i][j] |= is_match_helper(s, p , i, j) && dp[i-1][j -1];
			}
		}
	}
	return dp[sl][pl];
}