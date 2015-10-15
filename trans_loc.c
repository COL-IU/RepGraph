#include <stdinc.h>
#include <extvab.h>
#include <extfunc.h>

int trans_loc(int loc, int *range, int num);

int trans_loc(int loc, int *range, int num)
{
        int     i, j, k, l;

        k = 0;
        if(loc <= range[0])      return(loc);
        k += SEGLEN;
        for(i = 0; i < num - 1; i ++)   {
                if(loc >= range[2 * i + 1] && loc <= range[2 * i + 2])    {
                        return(k + loc - range[2 * i + 1] - 1);
                }
                k += range[2 * i + 2] - range[2 * i + 1];
                k += SEGLEN;
        }
        if(loc >= range[2 * i + 1])      return(k + loc - range[2 * i + 1] - 1);
        printf("Location not found: %d.\n", loc);
        for(i = 0; i < num; i ++)   {
		printf("range %d %d\n", range[2 * i], range[2 * i + 1]);
	}
        exit(-1);
}
