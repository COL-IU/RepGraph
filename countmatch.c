#include <stdinc.h>
#include <extvab.h>
#include <extfunc.h>

int searchlast(NODES *vertex, EDGE *edge, PATH *path, int num_path, int *match);
int searchnext(NODES *vertex, EDGE *edge, PATH *path, int num_path, int *match);
int countmatch(EDGE *edge1, EDGE *edge2, PATH *path, int num_path);
int countstartmatch(EDGE *edge, NODES *vertex, PATH *path, int num_path);
int countendmatch(EDGE *edge, NODES *vertex, PATH *path, int num_path);

int countstartmatch(EDGE *edge, NODES *vertex, PATH *path, int num_path)
{
	int	i, j, k, l, n, m;
	int	*match;

	match = (int *) ckalloc(vertex -> num_nextedge * sizeof(int));

	for(i = 0; i < vertex -> num_path; i ++)	{
		k = vertex -> path_index[i];
		j = vertex -> path_pos[i];
		if(j != 0 && j != path[k].len_path && path[k].edge[j - 1] == edge)	{
			n = searcherase(vertex -> nextedge, path[k].edge[j], vertex -> num_nextedge);
			match[n] ++;
		}
	}

	n = 0;
	for(i = 0; i < vertex -> num_nextedge; i ++)	{
		if(match[i] > 0)	{
			n ++;
		}
	}
	free((void *) match);
	return(n);
}

int countmatch(EDGE *edge1, EDGE *edge2, PATH *path, int num_path)
{
	int	i, j, k, l, n, m;
	NODES	*vertex;

	if(edge1 -> end != edge2 -> begin)	{
		printf("edge1 %d %d edge2 %d %d\n", edge1, edge1 -> end, edge2, edge2 -> begin);
		printf("Edge not connected in countmatch\n");
		exit(-1);
	}

	vertex = edge1 -> end;

	n = 0;
	for(i = 0; i < vertex -> num_path; i ++)	{
		k = vertex -> path_index[i];
		j = vertex -> path_pos[i];
		if(j != 0 && j != path[k].len_path && path[k].edge[j - 1] == edge1 &&
		   path[k].edge[j] == edge2)	{
			n ++;
		}
	}

	return(n);
}

int searchnext(NODES *vertex, EDGE *edge, PATH *path, int num_path, int *match)
{
	int	i, j, k, l, n, m, *next;

	next = (int *) ckalloc(vertex -> num_nextedge * sizeof(int));

	for(i = 0; i < vertex -> num_path; i ++)	{
		k = vertex -> path_index[i];
		j = vertex -> path_pos[i];
		if(j > 0 && j < path[k].len_path && path[k].edge[j - 1] == edge &&
		   path[k].edge[j] != edge)	{
			m = searcherase(vertex -> nextedge, path[k].edge[j], vertex -> num_nextedge);
			next[m] = 1;
		}
	}

	n = 0;
	for(i = 0; i < vertex -> num_nextedge; i ++)	{
		if(next[i] == 1 && vertex -> nextedge[i] -> end != edge -> begin)	{
			match[n ++] = i;
		}
	}

	free((void *) next);

	return(n);
}

int searchlast(NODES *vertex, EDGE *edge, PATH *path, int num_path, int *match)
{
	int	i, j, k, l, n, m, *last;

	last = (int *) ckalloc(vertex -> num_lastedge * sizeof(int));

	for(i = 0; i < vertex -> num_path; i ++)	{
		k = vertex -> path_index[i];
		j = vertex -> path_pos[i];
		if(j > 0 && j < path[k].len_path && path[k].edge[j] == edge &&
		   path[k].edge[j - 1] != edge)	{
			m = searcherase(vertex -> lastedge, path[k].edge[j], vertex -> num_lastedge);
			last[m] = 1;
		}
	}

	n = 0;
	for(i = 0; i < vertex -> num_lastedge; i ++)	{
		if(last[i] == 1 && vertex -> lastedge[i] -> begin != edge -> end)	{
			match[n ++] = i;
		}
	}

	free((void *) last);

	return(n);
}

int countendmatch(EDGE *edge, NODES *vertex, PATH *path, int num_path)
{
	int	i, j, k, l, n, m;
	int	*match;

	match = (int *) ckalloc(vertex -> num_lastedge * sizeof(int));

	for(i = 0; i < vertex -> num_path; i ++)	{
		k = vertex -> path_index[i];
		j = vertex -> path_pos[i];
		if(j != 0 && j != path[k].len_path && path[k].edge[j] == edge)	{
			n = searcherase(vertex -> lastedge, path[k].edge[j - 1], vertex -> num_lastedge);
			match[n] ++;
		}
	}

	n = 0;
	for(i = 0; i < vertex -> num_lastedge; i ++)	{
		if(match[i] > 0)	{
			n ++;
		}
	}
	free((void *) match);
	return(n);
}
