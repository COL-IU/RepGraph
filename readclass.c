#include <stdinc.h>
#include <extvab.h>
#include <extfunc.h>

int readclass(ALIGN **eq_class, int num_seq, FILE *fp);

int readclass(ALIGN **eq_class, int num_seq, FILE *fp)
{
	int	i, j, k, l, n;
	int	num_class;
	ALIGN	*class;

	l = 0;
	for(i = 0; i < 2 * num_seq; i ++)	{
		fread(&n, sizeof(int), 1, fp);
		l += n;
		for(j = 0; j < n; j ++)	{
			class = (ALIGN *) ckalloc(1 * sizeof(ALIGN));
			class -> reads[0] = i;
			fread(&(class -> reads[1]), sizeof(int), 1, fp);
			fread(&(class -> mis_match), sizeof(int), 1, fp);
			fread(&(class -> length), sizeof(int), 1, fp);
			for(k = 0; k < 2; k ++)	{
				class -> pos[k] = (int *) ckalloc(class -> length * sizeof(int));
			}
			fread(class -> pos[0], sizeof(int), class -> length, fp);
			fread(class -> pos[1], sizeof(int), class -> length, fp);
			class -> next = eq_class[i];
			class -> last = NULL;
			if(eq_class[i])	{
				eq_class[i] -> last = class;
			}
			eq_class[i] = class;
		}
	}
	return(l);
}
