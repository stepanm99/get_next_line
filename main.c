#include "src/get_next_line.h"

int	main(void)
{
	int		fd;
	char	*buffer;
	int		i;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	while (i < 5)
	{
		buffer = get_next_line(fd);
		printf("%s", buffer);
		free(buffer);
		i++;
	}
/*	buffer = buffer_start;
	while (*buffer != '\n')
	{
		if (*buffer == '\n')
			printf("found a new line!\n");
		printf("%c", *buffer);
		buffer++;
		i--;
	}*/
	close(fd);
	return (0);
}