#include <stdinc.h>
#include <extvab.h>
#include <extfunc.h>

int readph(ALIGN **align, char **src_seq, int *len_seq, FILE *fp, int MIN_LEG, double MIN_ID);

int readph(ALIGN **align, char **src_seq, int *len_seq, FILE *fp, int MIN_LEG, double MIN_ID)
{
	int	i, j, k, l, m, n, s1, s2, pos;
	int	len1, len2, pos1, pos2, len;
	int	nall;
	int	*sapp;
	char	dir[10];
	double	id;
	char	str[500];

	sapp = (int *) ckalloc(len_seq[0] * sizeof(int));

	nall = n = 0;
	while(fgets(str, 400, fp))	{
		pos = 0;
                if(!strncmp(str, "Database", 8))        continue;
                if(!strncmp(str, "Sequence", 8))        continue;
		for(i = 0; i < strlen(str); i ++)	{
			if(str[i] == ':')	{
				pos = i;
				break;
			}
		}
		if(i < strlen(str))	{
			for(i = 0; i < strlen(str); i ++)	{
				if(str[i] > '9' || str[i] < '0' && str[i] != '-')	str[i] = ' ';
			}
			sscanf(&str[pos + 2], "%d%d%d%d", &pos1, &pos2, &len1, &len2);
			if(pos1 >= 0)	{
				dir[0] = 'F';
				pos1 --;
				pos2 --;
			} else	{
				dir[0] = 'R';
				pos1 = -pos1;
				pos1 --;
				pos2 --;
				pos1 = len_seq[0] - pos1 - 1;
			}
			if(len1 < MIN_LEG || len2 < MIN_LEG)	continue;
			if(dir[0] == 'F')	{
				s1 = s2 = 0;
				k = ALIGN0(&src_seq[0][pos1 - 1], &src_seq[0][pos2 - 1], len1, len2,
					  -band, band, W, g, h, sapp, len1 + len2, len1 + len2);
				id = cal_identity(&src_seq[0][pos1], len1, &src_seq[0][pos2], len2, sapp);
				if(id >= MIN_ID)	{
					align[0] = new_align(sapp, align[0], s1, s2,
						    pos1, pos2, len1, len2);
					nall ++;
				}
			} else	{
				s1 = 1;
				s2 = 0;
				k = ALIGN0(&src_seq[1][pos1 - 1], &src_seq[0][pos2 - 1], len1, len2,
					  -band, band, W, g, h, sapp, len1 + len2, len1 + len2);
				id = cal_identity(&src_seq[1][pos1], len1, &src_seq[0][pos2], len2, sapp);
				if(id >= MIN_ID)	{
					align[1] = new_align(sapp, align[1], s1, s2,
						    pos1, pos2, len1, len2);
					nall ++;
				}
			}
			n ++;
		}
	}
	free((void *) sapp);
	return(nall);
}
