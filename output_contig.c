#include <stdinc.h>
#include <extvab.h>
#include <extfunc.h>

void output_contig(NODES **vertex, int num_vertex, char **src_name, char **src_seq,
		 int num_seq, FILE *fp, FILE *fp1, FILE *fp2, FILE *fp3);
void writeseq(FILE *fp, char *seq, char *name, int length);

void output_contig(NODES **vertex, int num_vertex, char **src_name, char **src_seq,
		 int num_seq, FILE *fp, FILE *fp1, FILE *fp2, FILE *fp3)
{
	int	i, j, k, l, n;
	char	temp[100];
	EDGE	*edge;

	write_graph(vertex, num_vertex, fp, fp1);
	for(i = 0; i < num_vertex; i ++)	{
		for(j = 0; j < vertex[i] -> num_nextedge; j ++)	{
			edge = vertex[i] -> nextedge[j];
			edge -> visit = 0;
		}
	}
	n = 0;
	for(i = 0; i < num_vertex; i ++)	{
		for(j = 0; j < vertex[i] -> num_nextedge; j ++)	{
			edge = vertex[i] -> nextedge[j];
			if(edge -> visit == 0)	{
				sprintf(temp, "Contig%d", n);
				writeseq(fp2, edge -> seq, temp, edge -> length);
/*
				writeace(fp3, edge -> seq, edge -> class, edge -> multip, edge -> length, src_name,
					 src_seq, num_seq);
*/
				n ++;
				edge -> visit = edge -> bal_edge -> visit = 1;
			}
		}
	}
	printf("# Contigs: %d.\n", n);
}

void writeseq(FILE *fp, char *seq, char *name, int length)
{
	int	i, j, k;

	fprintf(fp, ">%s\n", name);
	for(i = 0; i < length; i ++)	{
		fprintf(fp, "%c", na_name[seq[i]]);
		if(i % 50 == 49)	{
			fprintf(fp, "\n");
		}
	}
	if(i % 50 != 0)	{
		fprintf(fp, "\n");
	}
}
