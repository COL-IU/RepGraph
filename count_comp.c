#include <stdinc.h>
#include <extvab.h>
#include <extfunc.h>

int count_comp(double *prob, int *visit, double probthresh, int num_subrep, int index);

int count_comp(double *prob, int *visit, double probthresh, int num_subrep, int index)
{
	int	i, j, k, l, m, n;

	k = 0;
	for(i = 0; i < num_subrep; i ++)	{
		if(visit[i] == 1)	continue;
		visit[i] = 1;
		if(index < i)	{
			n = numc(index, i);
		} else {
			n = numc(i, index);
		}
		if(prob[n] > probthresh)	{
			k += count_comp(prob, visit, probthresh, num_subrep, i);
			k ++;
		}
	}
	return(k);
}
