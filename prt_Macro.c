#include <stdio.h>


void prt_Macro(FILE *fp);

void prt_Macro(FILE *fp)
{
	fprintf(fp, "/m { moveto } def\n");
	fprintf(fp, "/l { lineto } def\n\n");
}
