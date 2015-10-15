#include <stdinc.h>
#include <extfunc.h>

int readins(int *insertpos, int *insertlen, FILE *fp);

int readins(int *insertpos, int *insertlen, FILE *fp)
{
	int	i, j, k, n;
	char	str[300];

	n = 0;
	while(fgets(str, 290, fp))	{
		if(str[0] == '#')	continue;
		sscanf(str, "%d%d%*s", &insertpos[n], &insertlen[n]);
		n ++;
	}
	return(n);
}
