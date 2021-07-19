#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	char *line = NULL;

	while((get_next_line(&line)) > 0)
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
	printf("%s\n", line);
	free(line);
	line = NULL;
	return (0);
}