#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef unsigned char bool;

#define MATCH(x, y) (x == y || y == '.')

bool isMatch(char *s, char *p)
{
	while (1)
	{
		if (*p == '*')
		{
			p++;
		}
		else
		{
			break;
		}
	}

	int sl = strlen(s);
	int pl = strlen(p);

	while (sl > 0 && pl > 0)
	{
		if (MATCH(s[sl - 1], p[pl - 1]))
		{
			sl--;
			pl--;
		}
		else if (p[pl - 1] == '*')
		{
			if (MATCH(s[sl - 1], p[pl - 2]))
			{
				sl--;
			}
			else
			{
				pl = pl - 2;
			}
		}
		else
		{
			return 0;
		}
	}

	if(sl == 0)
	{
		if(pl == 0)
		{
			return 1;
		}
		else if(pl % 2 == 0)
		{
			while(pl > 0)
			{
				if(p[pl - 1] != '*')
				{
					return 0;
				}
				pl = pl - 2;
			}
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

int main()
{
	if (isMatch("aaa", "ab*a*c*a"))
	{
		printf("true");
	}
	else
	{
		printf("false");
	}
}