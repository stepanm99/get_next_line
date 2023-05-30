#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>



int	main(void)
{
	char	*buffer;
	char	*buffer_start;
	int		fd;

	buffer = malloc(1024);
	if (buffer == NULL)
		return (0);
	buffer_start = buffer;
	fd = open("test.txt", O_RDONLY);
	while (*(buffer - 1) != '\n')
	{
		read(fd, buffer, 1);
		printf("%c", *buffer);
		buffer++;
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
	return (0);
}