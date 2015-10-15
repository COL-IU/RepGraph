#include <stdio.h>


void restore_scale(FILE *fp);
void prt_Trailer(FILE *fp, int pages);
void showpage(FILE *fp);
void prt_Page(FILE *fp, int page);
void change_scale(FILE *fp, double *scale);
void page_trailer(FILE *fp);

void page_trailer(FILE *fp)
{
	fprintf(fp, "%%%%PageTrailer\n");
}


void prt_Trailer(FILE *fp, int pages)
{
	fprintf(fp, "%%%%Trailer\n");
}



void showpage(FILE *fp)
{
	fprintf(fp, "\nshowpage\n");
}



/*
void prt_Page(FILE *fp, int page, char *pagefont)
*/
void prt_Page(FILE *fp, int page)
{
/*
	fprintf(fp, "%%%%Pagefont: %s\n", pagefont);
*/
	fprintf(fp, "%%%%Page %d %d\n", page, page);
	fprintf(fp, "%%%%PageBoundingBox %d %d %d %d\n", 0, 0, 900, 900);
	fprintf(fp, "%%%%EndPageComments\n\n");
	
}


void change_scale(FILE *fp, double *scale)
{
	fprintf(fp, "gsave\n");
	fprintf(fp, "%2.1f %2.1f scale\n", scale[0], scale[1]);
}

void restore_scale(FILE *fp)
{
	fprintf(fp, "grestore\n");
}
