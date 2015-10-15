#include <stdinc.h>
#include <extvab.h>
#include <extfunc.h>

int readposition(int *pos1, int *pos2, int *dir1, int *dir2, int *len_seq, int num_seq, FILE *fp);

int readposition(int *pos1, int *pos2, int *dir1, int *dir2, int *len_seq, int num_seq, FILE *fp)
{
	int	i, j, k, l, m, n, s1, s2, pos[100], nc;
	int	len1, len2, len[100], dir[100], dir_l[100], pos_l[100];
	int	nall;
	char	str[500];

	nall = 0;
	while(fgets(str, 400, fp))	{
                if(str[0] != ' ')	{
			for(i = 0; i < 100; i ++)	{
				pos[i] = dir[i] = pos_l[i] = dir_l[i] = 0;
			}
		} else	{
			l = strlen(str);
			nc = 0;
			j = 0;
			while(j < l)	{
				sscanf(&str[j], "%d%d", &pos[nc], &dir[nc]);
				if(dir[nc] < 0)	{
					dir[nc] = -dir[nc] - 1 + num_seq;
					pos[nc] = len_seq[dir[nc]] - pos[nc];
				} else	{
					pos[nc] -= 1;
					dir[nc] -= 1;
				}
				for(j ++; j < l; j ++)	{
					if(str[j] == ';')	break;
				}
				j += 2;
				nc ++;
			}
			if(nc <= 1)	continue;
			for(m = 1; m < nc; m ++)	{
				if(pos[m] == 0)	continue;
				dir1[nall] = dir[0];
				dir2[nall] = dir[m];
				pos1[nall] = pos[0];
				pos2[nall] = pos[m];
				nall ++;
			}
		}
	}
	return(nall);
}
