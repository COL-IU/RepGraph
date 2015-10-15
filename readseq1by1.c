#include <stdinc.h>
#include <extfunc.h>

#define MAXNUM 250000000

int readseq1by1(char **src_seq, char **src_name, int *len_seq, FILE *fp);
int readseq1by1gen(char **src_seq, char **src_name, int *len_seq, FILE *fp);

int readseq1by1(char **src_seq, char **src_name, int *len_seq, FILE *fp)
{
	int	i, j, k, n;
	char	*seq, c;
	char	str[500];

	seq = (char *) ckalloc(MAXNUM * sizeof(char));

	n = 0;
	k = -1;
	while(fgets(str, 450, fp))	{
		if(str[0] == '#')	continue;
		if(str[0] == '>')	{
			if(k >= 0)	{
				len_seq[k] = n;
				src_seq[k] = (char *) ckalloc((n + 1) * sizeof(char));
				for(i = 0; i < n; i ++)		src_seq[k][i] = seq[i];
			}
			n = 0;
			k ++;
			sscanf(&str[1], "%s", src_name[k]);
		} else {
			for(i = 0; i < strlen(str); i ++)	{
				if(str[i] >= 'a' && str[i] <= 'z') {
					c = char2int(str[i]);
					seq[n ++] = c;
				} else if(str[i] >= 'A' && str[i] <= 'Z') {
					c = char2int(str[i] - 'A' + 'a');
					seq[n ++] = c;
				}
			}
		}
	}

	if(k >= 0)	{
		len_seq[k] = n;
		src_seq[k] = (char *) ckalloc((n + 1) * sizeof(char));
		for(i = 0; i < n; i ++)		src_seq[k][i] = seq[i];
	}
	k ++;

	free((void *) seq);
	return(k);
}

int readseq1by1gen(char **src_seq, char **src_name, int *len_seq, FILE *fp)
{
	int	i, j, k, n;
	char	*seq, c;
	char	str[500];

	seq = (char *) ckalloc(MAXNUM * sizeof(char));

	n = 0;
	k = -1;
	while(fgets(str, 450, fp))	{
		if(str[0] == '#')	continue;
		if(str[0] == '>')	{
			if(k >= 0)	{
				len_seq[k] = n;
				src_seq[k] = (char *) ckalloc((n + 1) * sizeof(char));
				for(i = 0; i < n; i ++)		src_seq[k][i] = seq[i];
			}
			n = 0;
			k ++;
			sscanf(&str[1], "%s", src_name[k]);
		} else {
			for(i = 0; i < strlen(str); i ++)	{
				if(str[i] >= 'a' && str[i] <= 'z') {
					c = char2intgen(str[i]);
					seq[n ++] = c;
				} else if(str[i] >= 'A' && str[i] <= 'Z') {
					c = char2intgen(str[i] - 'A' + 'a');
					seq[n ++] = c;
				}
			}
		}
	}

	if(k >= 0)	{
		len_seq[k] = n;
		src_seq[k] = (char *) ckalloc((n + 1) * sizeof(char));
		for(i = 0; i < n; i ++)		src_seq[k][i] = seq[i];
	}
	k ++;

	free((void *) seq);
	return(k);
}
