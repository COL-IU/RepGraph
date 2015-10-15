#include <stdio.h>

int parsestr(char *str, char **items, char *delimiter);

int parsestr(char *str, char **items, char *delimiter)
{
	int	i, j, k, len;
	int	num_item, l_del;

	num_item = 0;
	len = strlen(str);
	l_del = strlen(delimiter);
	i = k = 0;
	while(i < len)	{
		if(strncmp(&str[i], delimiter, l_del))	{ 
			items[num_item][k ++] = str[i];
			i ++;
		} else	{
			for(i ++; i < len; i ++)	{
				if(strncmp(&str[i], delimiter, l_del))	break;
			}
			items[num_item][k] = '\0';
			num_item ++;
			k = 0;
		}
	}
	return(num_item + 1);
}
