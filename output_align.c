#include <stdinc.h>
#include <extvab.h>
#include <extfunc.h>

void output_align(ALIGN *align, char **src_name, char **src_seq, int *len_seq, int num_seq);

void output_align(ALIGN *align, char **src_name, char **src_seq, int *len_seq, int num_seq)
{
	int	i, j, k, l, m, n, len;
	int	read1, read2, pos1, pos2;
	int	*seq1, *seq2;
	char	*match;
	int	l1, l2;

	l1 = l2 = 0;
	read1 = align -> reads[0];
	read2 = align -> reads[1];
	seq1 = (int *) ckalloc((len_seq[read1] + len_seq[read2]) * sizeof(int));
	seq2 = (int *) ckalloc((len_seq[read1] + len_seq[read2]) * sizeof(int));
	match = (char *) ckalloc((len_seq[read1] + len_seq[read2]) * sizeof(char));
	k = 0;
	for(i = 0; i < align -> length - 1; i ++)	{
		pos1 = align -> pos[0][i];
		pos2 = align -> pos[1][i];
		while(pos1 < align -> pos[0][i + 1] && pos2 < align -> pos[1][i + 1])	{
			seq1[k] = pos1;
			seq2[k] = pos2;
			if(src_seq[read1][pos1] == src_seq[read2][pos2])	match[k] = 1;
			else							match[k] = 2;
			k ++;
			pos1 ++;
			pos2 ++;
		}
		if(pos1 < align -> pos[0][i + 1])	{
			for(j = pos1; j < align -> pos[0][i + 1]; j ++)	{
				seq1[k] = j;
				seq2[k] = -1;
				k ++;
			}
		}
		if(pos2 < align -> pos[1][i + 1])	{
			for(j = pos2; j < align -> pos[1][i + 1]; j ++)	{
				seq1[k] = -1;
				seq2[k] = j;
				k ++;
			}
		}
	}
	len = k;

	if(read1 >= num_seq)	{
		m = reverse_read(read1, num_seq);
	} else	{
		m = read1;
	}
	if(read2 >= num_seq)	{
		k = reverse_read(read2, num_seq);
	} else	{
		k = read2;
	}

	printf("read %d %s %d %s length %d %d regions %d %d %d %d mis_match %d length %d\n", read1, src_name[m], read2,
		 src_name[k], len_seq[m], len_seq[k], align -> pos[0][0], align -> pos[0][align -> length - 1],
		 align -> pos[1][0], align -> pos[1][align -> length - 1], align -> mis_match, align -> length);
	m = len / 60 + 1;
	for(i = 0; i < m; i ++)	{
		if(i == m - 1)	l = len % 60;
		else		l = 60;
		for(j = 0; j < l; j ++)	{
			if(seq1[i * 60 + j] < 0)	{
				printf("-");
			} else	{
				printf("%c", na_name[src_seq[read1][seq1[i * 60 + j]]]);
			}
		}
		printf("\n");
		for(j = 0; j < l; j ++)	{
			if(match[i * 60 + j] == 1)	{
				printf("|");
			} else if(match[i * 60 + j] == 2)	{
				printf(".");
			} else	{
				printf(" ");
			}
		}
		printf("\n");
		for(j = 0; j < l; j ++)	{
			if(seq2[i * 60 + j] < 0)	{
				printf("-");
			} else	{
				printf("%c", na_name[src_seq[read2][seq2[i * 60 + j]]]);
			}
		}
		printf("\n\n\n");
	}
	free((void *) seq1);
	free((void *) seq2);
	free((void *) match);
}
