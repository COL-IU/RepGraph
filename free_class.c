#include <stdinc.h>

READINTERVAL *free_readinterval(READINTERVAL *readinterval);
int size_readinterval(READINTERVAL *readinterval);

READINTERVAL *free_readinterval(READINTERVAL *readinterval)
{
	READINTERVAL	*cl;

	cl = readinterval -> next;
	free((void *) readinterval);
	return(cl);
}

int size_readinterval(READINTERVAL *readinterval)
{
	int	n;
	READINTERVAL	*cl;

	n = 0;
	cl = readinterval;
	while(cl)	{
		n ++;
		cl = cl -> next;
	}
	return(n);
}
