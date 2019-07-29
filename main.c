
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	for (int k = 0; k < argc; ++k)
	{
		FILE *file;
		if (argc == 1) 
		{
			file = stdin;
		}
		else if (!k)
		{
			continue;	
		}
		int cmpres = strcmp(argv[k], "-");
		if (!cmpres)
		{
			file = stdin;
		}
		else if (argc != 1)
		{
			file = fopen(argv[k], "r");	
		}
		if (!file && cmpres)
		{
			fprintf(stderr, "File %s doesn't exist! Exiting.\n", argv[k]);
			return -2;
		}
		char ch[] = {' ', '\0'};
		short i = 0, j = 31, add = 1;
		while ((ch[0] = fgetc(file)) != EOF)
		{
			printf("\033[%d;%dm%c", i, j, ch[0]);
			if (ch[0] == '\n' || ch[0] == '\t')
			{
				continue;
			}
			if (i)
			{
				++j;
			}
			i += add;
			add *= -1;
			if (j > 36)
			{
				j = 31;
			}
		}
		fclose(file);
	}
	printf("\033[0m");
	return 0;
}
