#include <stdinc.h>
#include <extvab.h>
#include <extfunc.h>

int chk_consist(PATH *startpath, PATH *midpath, int num_midpath, int *n);

int chk_consist(PATH *startpath, PATH *midpath, int num_midpath, int *n)
{
	int	i, j, k, l, c;

	c = -1;
	for(i = 0; i < num_midpath; i ++)	{
		if(startpath -> len_path <= midpath[i].len_path)	{
			for(j = 0; j < startpath -> len_path; j ++)	{
				if(startpath -> edge[j] != midpath[i].edge[j])	{
					break;
				}
			}
			if(j == startpath -> len_path)	{
				c = 0;
				*n = i;
				break;
			}
		} else	{
			for(j = 0; j < midpath[i].len_path; j ++)	{
				if(startpath -> edge[j] != midpath[i].edge[j])	{
					break;
				}
			}
			if(j == midpath[i].len_path)	{
				c = i + 1;
				break;
			}
		}
	}

	return(c);
}
