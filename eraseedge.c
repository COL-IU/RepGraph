#include <stdinc.h>
#include <extvab.h>
#include <extfunc.h>

void erasedge(EDGE *edge);

void erasedge(EDGE *edge)
{
	int	i, j, k, l, n, m;
	NODES	*begin, *end;

	begin = edge -> begin;
	end = edge -> end;
	k = searcherase(begin -> nextedge, edge, begin -> num_nextedge);
	erasenext(begin, k);
	k = searcherase(end -> lastedge, edge, end -> num_lastedge);
	eraselast(end, k);

	free((void *) edge -> readinterval);
	free((void *) edge);
}
