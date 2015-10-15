#include <stdinc.h>
#include <extvab.h>

void readpar()
{
	int	i;

	LOW_COV = 1;
	MIN_END = 100;
	END_LEG = 800;
	INT_LEG = 200;
	MIN_INT = 450;
	MIN_OTH_LEN = 5000;
	idum = 10;
	max_seq = 20000;
	start_ent = 100;
	end_ent = 450;
	band = 500;
	MIN_IDENTITY = 0.94;
	MIN_PERC = 0.9;
	SHORTEND = 50;
	SHORTLEG = 50;
	SHORTCYC = 500;
	MAX_BRA = 1000;
	MAX_TMP_LEG = 5000000;
	MIN_WHIRL_SIZE = 100;
	g = 12;
	h = 4;
	overlaplen = 20;
	word_len = 10;
	n_ban = 1;
	SEGLEN = 500;
	for(i = 0; i < word_len; i ++)	n_ban *= 4;
}
