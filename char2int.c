#include <stdinc.h>
#include <extvab.h>
#include <extfunc.h>

char char2int(char c);
char char2intgen(char c);

char char2int(char c)
{
	int	i, k;

	for(i = 0; i < total_nuc; i ++)		{
		if(c == na_name[i])	{
			k = i;
			break;
		}
	}

	if(i == total_nuc)	{
		printf("Not found %c\n", c);
		k = ran_number(4, &idum);
	}

	if(k > 3)	{
		k = ran_number(4, &idum);
	}

	return(k);
}

char char2intgen(char c)
{
	int	i, k;

	for(i = 0; i < total_nuc; i ++)		{
		if(c == na_name[i])	{
			k = i;
			break;
		}
	}

	if(i == total_nuc)	{
		printf("Not found %c\n", c);
		k = ran_number(4, &idum);
	}

	return(k);
}
