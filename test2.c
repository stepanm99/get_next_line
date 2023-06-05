#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <fcntl.h>

void	check_leaks();

void	bufferfiller(char *buffer)
{
	int	i;

	i = 0;
	while(i < 5)
	{
		*(buffer +i) = 'x';
		i++;
	}
}

int	main(void)
{
	int		fd;
	int		rd_ret;
	char	*buffer;
	char	*ptr;

	fd = 0;
	buffer = NULL;
	rd_ret = 1;
	fd = open("test.txt", O_RDONLY);
	buffer = malloc(101);
	*(buffer + 11) = '\0';
	ptr = buffer;
	while (rd_ret)
	{
		rd_ret = read(fd, buffer, 10);
		*(buffer + (rd_ret)) = '\0';
		printf("\n|%s|\n", buffer);
		printf("read_return: %d\n", rd_ret);
	}
	bufferfiller(ptr);
	printf("\nlast one: |%s|\n", buffer);
	free(buffer);
	close(fd);
	check_leaks();
	return (0);
}