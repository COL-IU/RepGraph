#include <stdinc.h>
#include <extvab.h>
#include <extfunc.h>

int align2seq(char *seq1, int len_seq1, char *seq2, int len_seq2, char **alnseq);

int align2seq(char *seq1, int len_seq1, char *seq2, int len_seq2, char **alnseq)
{
	int	i, j, k, l;
	int	*sapp;
	int	windows;
	int	gscore, ALIGN0();

	sapp = (int *) ckalloc((len_seq1 + len_seq2 + 1) * sizeof(int));
	alnseq[0] = (char *) ckalloc((len_seq1 + len_seq2 + 1) * sizeof(char));
	alnseq[1] = (char *) ckalloc((len_seq1 + len_seq2 + 1) * sizeof(char));
	windows = abs(len_seq1 - len_seq2) + 1000;
	gscore = ALIGN0(&seq1[-1], &seq2[-1], len_seq1, len_seq2, -windows, windows, W, 16, 4, sapp, len_seq1 + len_seq2 + 1,
			 len_seq1 + len_seq2 + 1);
	i = j = k = 0;
	l = 0;
	while(i < len_seq1 && j < len_seq2)	{
		if(sapp[k] == 0)	{
			alnseq[0][l] = seq1[i];
			alnseq[1][l] = seq2[j];
			i ++;
			j ++;
			l ++;
		} else if(sapp[k] > 0)	{
			j += sapp[k];
		} else	{
			i -= sapp[k];
		}
		k ++;
	}
	free((void *) sapp);
	return(l);
}
