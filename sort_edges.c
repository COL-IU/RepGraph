#include <stdinc.h>
#include <extvab.h>
#include <extfunc.h>

static int bincompar(BINDEX *a, BINDEX *b);
int sort_edges(EDGE **impedges, int num_imp, BINDEX *index, int pos);
int getedges(NODES **vertex, int num_vertex, EDGE **edge);

int getedges(NODES **vertex, int num_vertex, EDGE **edge)
{
	int	i, j, k, l;

	k = 0;
	for(i = 0; i < num_vertex; i ++)	{
		for(j = 0; j < vertex[i] -> num_nextedge; j ++)	{
			edge[k ++] = vertex[i] -> nextedge[j];
		}
	}
	return(k);
}

int sort_edges(EDGE **impedges, int num_imp, BINDEX *index, int pos)
{
	int	i, j, k, l;
	int	n;
	EDGE	*edge;

	n = 0;
	for(i = 0; i < num_imp; i ++)	{
		for(j = 0; j < impedges[i] -> multip; j ++)	{
			if(impedges[i] -> readinterval[j].eq_read == pos)	{
				index[n].index = i;
				index[n].index_mul = j;
				index[n ++].begin = impedges[i] -> readinterval[j].begin;
			}
		}
	}

	qsort(index, n, sizeof(BINDEX), (void *) bincompar);
	return(n);
}

static int bincompar(BINDEX *a, BINDEX *b)
{
	if(a -> begin > b -> begin)	return(1);
	else				return(-1);
}
