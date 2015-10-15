#include <stdinc.h>
#include <extvab.h>
#include <extfunc.h>

int comput_bp(int *rep1, int length1, int *rep2, int length2);

int comput_bp(int *rep1, int length1, int *rep2, int length2)
{
	int	i, j, k, l, m, n;
	int	*pointlist1, *pointlist2;

	pointlist1 = (int *) ckalloc(2 * length1 * sizeof(int));
	pointlist2 = (int *) ckalloc(2 * length2 * sizeof(int));
	for(i = 0; i < length1 - 1; i ++)	{
		pointlist1[2 * i] = rep1[i];
		pointlist1[2 * i + 1] = rep1[i + 1];
	}
	for(i = 0; i < length2 - 1; i ++)	{
		pointlist2[2 * i] = rep2[i];
		pointlist2[2 * i + 1] = rep2[i + 1];
	}
	n = 0;
	for(i = 0; i < length1 - 1; i ++)	{
		for(j = 0; j < length2 - 1; j ++)	{
			if((pointlist1[i * 2] == pointlist2[j * 2] && 
			   pointlist1[i * 2 + 1] == pointlist2[j * 2 + 1]) || 
			   (pointlist1[i * 2] == -pointlist2[j * 2 + 1] && 
			   pointlist1[i * 2 + 1] == -pointlist2[j * 2]))	{
				n ++;
				break;
			}
		}
	}
	free((void *) pointlist1);
	free((void *) pointlist2);
	return(n);
}
