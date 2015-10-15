#include <stdio.h>


void prt_Header(FILE *fp, char *title, char *creator, char *creationdate, int pages);

void prt_Header(FILE *fp, char *title, char *creator, char *creationdate, int pages)
{
	fprintf(fp, "%%!PSADOBE-1.0\n");
	fprintf(fp, "%%%%Creator: %s\n", creator);
	fprintf(fp, "%%%%Title: %s\n", title);
	fprintf(fp, "%%%%Creation date: %s\n", creationdate);
	if(pages != 0)
		fprintf(fp, "%%%%Pages: %d\n", pages);
	else
		fprintf(fp, "%%%%Pages: (atend)\n");
	fprintf(fp, "%%%%DocumentFonts: Times-Roman Times-Italic Times-Bold\n");
	fprintf(fp, "%%%%BoundingBox: 0 0 900 900\n");
	fprintf(fp, "%%%%EndComments\n\n");
}
