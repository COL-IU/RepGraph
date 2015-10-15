#include <stdinc.h>
#include <extvab.h>
#include <extfunc.h>

int readblast(ALIGN **align, FILE *fp, int MIN_LEG, double MIN_ID);

int readblast(ALIGN **align, FILE *fp, int MIN_LEG, double MIN_ID)
{
	int	i, j, k, l, m, n, s1, s2;
	int	length, *pos[2], len;
	int	nall;
	int	ma, tot_len, last;
	int	beg1, beg2, mis;
	double	id;
	ALIGN	*align0;
	char	str[500], temp[100], temp1[100], temp2[100],
		seq1[1000], seq2[1000];

	pos[0] = (int *) ckalloc(10000 * sizeof(int));
	pos[1] = (int *) ckalloc(10000 * sizeof(int));

	nall = 0;
	while(fgets(str, 400, fp))	{
		sscanf(str, "%s", temp);
		if(!strcmp(temp, "Length"))	{
			sscanf(str, "%*s%*s%d", &len);
			break;
		}
	}
	while(fgets(str, 400, fp))	{
		if(!strncmp(&str[1], "Identities", 10))	{
			sscanf(str, "%*s%*s%s", temp);
			for(i = 0; i < strlen(temp); i ++)	{
				if(temp[i] == '/')	temp[i] = ' ';
			}
			sscanf(temp, "%d%d", &ma, &tot_len);
			id = ((double) ma) / tot_len;
			if(tot_len >= MIN_LEG && id >= MIN_ID)	{
				fgets(str, 400, fp);
				sscanf(str, "%*s%*s%s%*s%s", temp1, temp2);
				if(!strncmp(temp1, "Plus", 4))	{
					s1 = 0;
				} else	{
					s1 = 1;
				}
				if(!strncmp(temp2, "Plus", 4))	{
					s2 = 0;
				} else	{
					s2 = 1;
				}

/*	Don't consider alignments both from '-' strands	*/
				if(s1 == 1 && s2 == 1)	continue;

				while(fgets(str, 400, fp))	{
					if(!strncmp(str, "Query", 5))	{
						sscanf(str, "%*s%d%s", &beg1, seq1);
					}
					if(!strncmp(str, "Sbjct", 5))	{
						sscanf(str, "%*s%d%s", &beg2, seq2);
						break;
					}
				}
				beg1 --;
				beg2 --;
				if(s1 == 1)	beg1 = len - beg1 - 1;
				if(s2 == 1)	beg2 = len - beg2 - 1;
/*	If s1 == s2 && beg1 == beg2, alignments start from the same position;
	if s1 != s2, choose only the half of the all alignments	*/
				
				/*[hatang 03/16/15] removing these 2 to accomodate legacy blast */
				//if(s1 == s2 && beg1 >= beg2 || s1 == 0 && s2 == 1 && beg1 <= len / 2 ||
				//   s1 == 1 && s2 == 0 && beg2 <= len / 2)	continue;
				mis = 0;
				align0 = (ALIGN *) ckalloc(1 * sizeof(ALIGN));
				align0 -> reads[0] = s1;
				align0 -> reads[1] = s2;
				pos[0][0] = beg1;
				pos[1][0] = beg2;
				length = 1;
				last = 0;
				do	{
					l = strlen(seq1);
					for(i = 0; i < l; i ++)	{
						if(seq1[i] == '-')	{
							beg2 ++;
							last = 1;
						} else if(seq2[i] == '-')	{
							beg1 ++;
							last = 1;
						} else	{
							if(last == 1)	{
								last = 0;
								pos[0][length] = beg1;
								pos[1][length] = beg2;
								length ++;
							}
							if(seq1[i] >= 'a' && seq1[i] <= 'z' ||
							   seq1[i] >= 'A' && seq1[i] <= 'Z')	{
								if(seq1[i] != seq2[i])	mis ++;
								beg1 ++;
								beg2 ++;
							}
						}
					}
					while(fgets(str, 400, fp))	{
					        if(!strncmp(str, "Lambda", 6) || !strncmp(str, " Score", 6))	break;
						if(!strncmp(str, "Query", 5))	{
							sscanf(str, "%*s%*d%s", seq1);
						}
						if(!strncmp(str, "Sbjct", 5))	{
							sscanf(str, "%*s%*d%s", seq2);
							break;
						}
					}
					if(!strncmp(str, " Score", 6) || !strncmp(str, "Lambda", 6))	break;
				} while(l > 0);
				pos[0][length] = beg1;
				pos[1][length] = beg2;
				length ++;
				align0 -> pos[0] = (int *) ckalloc(length * sizeof(int));
				align0 -> pos[1] = (int *) ckalloc(length * sizeof(int));
				align0 -> length = length;
				for(j = 0; j < length; j ++)	{
					align0 -> pos[0][j] = pos[0][j];
					align0 -> pos[1][j] = pos[1][j];
				}
				align0 -> mis_match = mis;
				nall ++;
				if(s1 == 0)	{
					align0 -> next = align[0];
					align[0] = align0;
				} else	{
					align0 -> next = align[1];
					align[1] = align0;
				}
			}
		}
	}
	free((void *) pos[0]);
	free((void *) pos[1]);
	return(nall);
}
