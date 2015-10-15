#include <stdinc.h>
#include <extvab.h>
#include <extfunc.h>

void add_path(NODES *vertex, int path_index, int path_pos);
void rem_path(NODES *vertex, int path_index, int path_pos);
void set_path(NODES **vertex, int num_vertex, PATH *path, int num_path);

void set_path(NODES **vertex, int num_vertex, PATH *path, int num_path)
{
	int	i, j, k;
	NODES	*begin;

	for(i = 0; i < num_vertex; i ++)	{
		vertex[i] -> num_path = 0;
	}

	for(i = 0; i < num_path; i ++)	{
		if(path[i].len_path == 0)	continue;
		begin = path[i].edge[0] -> begin;
		add_path(begin, i, 0);
		for(j = 0; j < path[i].len_path; j ++)	{
			begin = path[i].edge[j] -> end;
			add_path(begin, i, j + 1);
		}
	}
}

void rem_path(NODES *vertex, int path_index, int path_pos)
{
	int	i, j, k, l;
	int	*index, *pos;

	for(i = vertex -> num_path - 1; i >= 0; i --)	{
		if(vertex -> path_index[i] == path_index && vertex -> path_pos[i] == path_pos)	{
			for(j = i; j < vertex -> num_path - 1; j ++)	{
				vertex -> path_index[j] = vertex -> path_index[j + 1];
				vertex -> path_pos[j] = vertex -> path_pos[j + 1];
			}
			vertex -> num_path --;
		}
	}
}


void add_path(NODES *vertex, int path_index, int path_pos)
{
	int	i, j, k, l, label;
	int	*index, *pos;

	index = (int *) ckalloc((vertex -> num_path) * sizeof(int));
	pos = (int *) ckalloc((vertex -> num_path) * sizeof(int));
	for(i = 0; i < vertex -> num_path; i ++)	{
		index[i] = vertex -> path_index[i];
		pos[i] = vertex -> path_pos[i];
	}
	free((void *) vertex -> path_index);
	free((void *) vertex -> path_pos);
	vertex -> path_index = (int *) ckalloc((vertex -> num_path + 1) * sizeof(int));
	vertex -> path_pos = (int *) ckalloc((vertex -> num_path + 1) * sizeof(int));

	label = 0;
	for(i = 0; i < vertex -> num_path; i ++)	{
		vertex -> path_index[i] = index[i];
		vertex -> path_pos[i] = pos[i];
		if(index[i] == path_index && pos[i] == path_pos)	{
			label = 1;
		}
	}
	free((void *) index);
	free((void *) pos);
	if(label == 0)	{
		vertex -> path_index[vertex -> num_path] = path_index;
		vertex -> path_pos[vertex -> num_path] = path_pos;
		vertex -> num_path ++;
	}
}
