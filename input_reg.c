#include <stdio.h>
#include <perdef.h>
#include <extfunc.h>

int input_reg(FILE *fp, SEGMENT *segment);

int input_reg(FILE *fp, SEGMENT *segment)
{
	int	i, j, k, l, n;
	char	str[400];

	n = 0;
	while(fgets(str, 390, fp))	{
		if(str[0] != '#')	{
			sscanf(str, "%*s%d%*s%d%d%d%d\n", &k, &(segment[n].pos[0]), &(segment[n].pos[1]),
				&(segment[n].eq_pos[0]), &(segment[n].eq_pos[1]));
			segment[n].chro = k - 1;
			n ++;
		}
	}
	return(n);
}
