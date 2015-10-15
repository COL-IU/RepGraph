#include <stdinc.h>
#include <extvab.h>
#include <extfunc.h>

int input_segment(SEGMENT *segment, char **chrname, int num_chro, FILE *fp);

int input_segment(SEGMENT *segment, char **chrname, int num_chro, FILE *fp)
{
	int	k;
	int	num_segment;
	char	str[500], name[100], temp[100];

	num_segment = 0;
	while(fgets(str, 400, fp))	{
		if(!strncmp(str, "chromosome", 10))	continue;
//		sscanf(str, "%s%d%d%*d%*s%s%d%d%d", name, &(segment[num_segment].pos[0]),
		sscanf(str, "%s%d%d%*s%s%d%d%d", name, &(segment[num_segment].pos[0]),
			&(segment[num_segment].pos[1]), temp,
			&(segment[num_segment].src_pos[0]), &(segment[num_segment].src_pos[1]), 
			&(segment[num_segment].length));
		segment[num_segment].pos[0] --;
		segment[num_segment].pos[1] --;
		if(segment[num_segment].src_pos[0] > segment[num_segment].src_pos[1])	{
			k = segment[num_segment].src_pos[1];
			segment[num_segment].src_pos[1] = segment[num_segment].src_pos[0];
			segment[num_segment].src_pos[0] = k;
			segment[num_segment].eq_pos[1] = 1;
		}
		segment[num_segment].chro = findgenname(name, chrname, num_chro);
		segment[num_segment].eq_pos[0] = atoi(&temp[1]);
		num_segment ++;
	}
	return(num_segment);
}
