#include <stdio.h>
#include <math.h>
#include <perdef.h>
#include <param.h>
#include <extvab.h>
#include <extfunc.h>

char resfile[100];
char chriname[100];

int min_length, nchro;

void initenv(int argc, char **argv);
int segcompar(SEGMENT *a, SEGMENT *b);

main(int argc, char **argv)
{
	int	i, j, k, l, m, n;
	char	name[1000], temp[1000], c, str[100];
	int	nv, ne, nst, nt, nseg, nsub;
	FILE	*fp;

	sprintf(resfile, "split/watch.%s.simp", argv[1]);
/*	Input chromsomal information	*/
	fp = ckopen(resfile, "r");
	while(fgets(str, 300, fp))	{
		if(!strncmp(str, "Vertices", 8))	{
			fgets(str, 300, fp);
			fgets(str, 300, fp);
			sscanf(str, "%d%d%*d%*d%d%d", &nv, &ne, &nt, &nst);
			break;
		}
	}
	fclose(fp);

	sprintf(name, "count_rep -l chromosome.length <split/%s.txt >tmpfile", argv[1]);
	system(name);

	fp = ckopen("tmpfile", "r");
	fgets(str, 300, fp);
	sscanf(str, "%d%*s%*s%*s%d", &nseg, &nsub);
	fclose(fp);

	printf("%s	%d	%d	%d	%d	%d	%d\n",
		argv[1], nv, ne, nt, nst, nsub, nseg);
}
