#include <stdinc.h>
#include <extvab.h>
#include <extfunc.h>

int copyseq(char *seq1, char *seq2, int len_seq);
int reverse_seq(char *seq, int len);

int copyseq(char *seq1, char *seq2, int len_seq)
{
	int	i, len;

	len = 0;
	for(i = 0; i < len_seq; i ++)	{
		seq1[i] = seq2[i];
	}
	return(len_seq);
}

int reverse_seq(char *seq, int len)
{
	int	i;
	char	c;

	for(i = 0; i < len / 2; i ++)	{
		c = rev(seq[i]);
		seq[i] = rev(seq[len - 1 - i]);
		seq[len - 1 - i] = c;
	}
	if(len % 2 == 1)	{
		seq[len / 2] = rev(seq[len / 2]);
	}
}
