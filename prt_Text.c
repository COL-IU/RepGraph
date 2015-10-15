#include <stdio.h>


void prt_Text(FILE *fp, char *text, int position[2], int size, int angle);

void prt_Text(FILE *fp, char *text, int position[2], int size, int angle)
{
	fprintf(fp, "gsave\n");
	fprintf(fp, "0 0 0 setcolor\n");
	fprintf(fp, "/Times-Roman findfont %d scalefont setfont\n", size);
	fprintf(fp, "%4d%4d m\n", position[0], position[1]);
	if(angle != 0)	{
/*
		fprintf(fp, "%4d%4d translate\n", position[0], position[1]);
*/
		fprintf(fp, "%d rotate\n", angle);
	}
	fprintf(fp, "(%s) show\n", text);
	fprintf(fp, "grestore\n");
}
