#include <stdinc.h>

ALIGN *free_align(ALIGN *align);
int size_align(ALIGN *align);

ALIGN *free_align(ALIGN *align)
{
	int	i;
	ALIGN	*cl;

	cl = align -> next;
	for(i = 0; i < 2; i ++)
		free((void *) align -> pos[i]);
	if(align -> last)	{
		align -> last -> next = align -> next;
	}
	if(align -> next)	{
		align -> next -> last = align -> last;
	}
	free((void *) align);
	return(cl);
}

int size_align(ALIGN *align)
{
	int	n;
	ALIGN	*cl;

	n = 0;
	cl = align;
	while(cl)	{
		n ++;
		cl = cl -> next;
	}
	return(n);
}
