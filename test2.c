#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <fcntl.h>

void	check_leaks();

int	main(void)
{
	int		fd;
	int		rd_ret;
	char	*buffer;

	fd = 0;
	buffer = NULL;
	rd_ret = 1;
	fd = open("test.txt", O_RDONLY);
	buffer = malloc(101);
	*(buffer + 11) = '\0';
	while (rd_ret)
	{
		rd_ret = read(fd, buffer, 10);
		printf("\n|%s|\n", buffer);
	}
	free(buffer);
	close(fd);
	check_leaks();
	return (0);
}