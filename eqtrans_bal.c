#include <stdinc.h>
#include <extvab.h>
#include <extfunc.h>

int nsuper, *numtangle, *maxmultip, *maxlength, *avelength, *mlength;

int eqtrans_bal(NODES **vertex, int num_vertex, PATH *path, int num_path);

int eqtrans_bal(NODES **vertex, int num_vertex, PATH *path, int num_path)
{
	int	i, j, k, l, n, m;
	int	tot_edge, tot_edge_old, tot_path, tot_path_old;
	int	**num_pa;
	int	votethresh;
	EDGE	*edge, **all_edge, *edge1, *edge2, *edge0;

	votethresh = LOW_COV;

	num_pa = (int **) ckalloc(MAX_BRA * sizeof(int *));
	for(i = 0; i < MAX_BRA; i ++)	{
		num_pa[i] = (int *) ckalloc(MAX_BRA * sizeof(int));
	}

	tot_edge = count_edge_simp(vertex, num_vertex, num_pa);
	printf("In the beginning, %d vertices, %d edges, %d sources/sinks.\n",
		num_vertex, tot_edge, num_pa[1][0] * 2);
	do	{
		tot_edge_old = tot_edge;
		tot_path_old = tot_path;
		num_vertex = vertex_run(vertex, num_vertex, path, num_path, votethresh);
		num_vertex = merge_graph_path(vertex, num_vertex, path, num_path, votethresh);
		tot_edge = count_edge_simp(vertex, num_vertex, num_pa);
		tot_path = count_path(path, num_path);
		printf("Transforming EULER graph: %d vertices, %d edges, %d sources and %d sinks.\n",
			num_vertex, tot_edge, num_pa[0][1], num_pa[1][0]);
	} while(tot_edge_old > tot_edge || tot_path_old > tot_path);

	num_vertex = splitbeg(vertex, num_vertex, path, num_path);
	num_vertex = merge_graph_path(vertex, num_vertex, path, num_path, votethresh);
	tot_edge = count_edge_simp(vertex, num_vertex, num_pa);
	printf("Finally %d vertices, %d edges, %d sources/sinks.\n", num_vertex, tot_edge, num_pa[0][1] * 2);

	for(i = 0; i < MAX_BRA; i ++)	{
		free((void *) num_pa[i]);
	}
	free((void **) num_pa);
	return(num_vertex);
}
