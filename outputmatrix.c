#include <stdinc.h>
#include <extvab.h>
#include <extfunc.h>

void outputmatrix(FILE *fp, double *EvoDist, int num_seq, char **repnames);

void outputmatrix(FILE *fp, double *EvoDist, int num_seq, char **repnames)
{
	int	i, j, k, l;

	for(i = 0; i < num_seq; i ++)	{
		fprintf(fp, "Segment %d %s\n", i + 1, repnames[i]);
	}
	fprintf(fp, "--------------------------------------------------\n");
	fprintf(fp, "       ");
	for(i = 0; i < num_seq; i ++)	{
		fprintf(fp, "%-6d ", i + 1);
	}
	fprintf(fp, "\n");
	for(i = 0; i < num_seq; i ++)	{
		fprintf(fp, "%6d ", i + 1);
		for(j = 0; j < num_seq; j ++)	{
			k = numc(i, j);
			if(i == j)	{
				fprintf(fp, "--    ", EvoDist[k]);
			} else	{
				fprintf(fp, "%-6.3f ", EvoDist[k]);
			}
		}
		fprintf(fp, "\n");
	}
	fprintf(fp, "--------------------------------------------------\n");
}
