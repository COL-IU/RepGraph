/* ckopen - open file; check for success */

#include <stdinc.h>
#include <extfunc.h>

void *ckalloc(int amount);
FILE *ckopen(char *name, char *mode);

FILE *ckopen(char *name, char *mode)
{
	FILE *fp;

	if ((fp = fopen(name, mode)) == NULL)	{
		printf("Cannot open %s.\n", name);
		exit(-1);
	}
	return(fp);
}


/* ckalloc - allocate space; check for success */

void *ckalloc(int amount)
{
	void *p;

	if(amount == 0)	{
		amount = (unsigned) 100;
	}
	if ((p = (void *) calloc( (unsigned) amount, 1)) == NULL)	{
		printf("Ran out of memory.\n");
                printf("There may be errors as follows:\n");
                printf("1) Not enough memory.\n");
                printf("2) The ARRAY may be overrode.\n");
                printf("3) The wild pointers.\n");
                exit(-1);
	}
	return(p);
}
