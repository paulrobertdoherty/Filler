#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

int main(void)
{
	printf("Hi!\n");
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		printf("Hello?\n");
		free(line);
	}
	return 0;
}
