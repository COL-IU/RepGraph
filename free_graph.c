#include <stdinc.h>
#include <extvab.h>
#include <extfunc.h>

void free_graph(NODES **vertex, int num_vertex);

void free_graph(NODES **vertex, int num_vertex)
{
	int	i, j;

	for(i = 0; i < num_vertex; i ++)	{
		for(j = 0; j < vertex[i] -> num_nextedge; j ++)	{
			if(!(vertex[i] -> nextedge[j] -> seq))	{
				free((void *) vertex[i] -> nextedge[j] -> seq);
			}
			free((void *) vertex[i] -> nextedge[j] -> readinterval);
			free((void *) vertex[i] -> nextedge[j]);
		}
		free((void **) vertex[i] -> lastedge);
		free((void **) vertex[i] -> nextedge);
		free((void *) vertex[i] -> position);
		free((void *) vertex[i]);
	}
}
