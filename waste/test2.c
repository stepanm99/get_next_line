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
	rd_ret = read(fd, buffer, 0);
	printf("\nread return when reading 0 bytes from the middle of file: %d\n", rd_ret);
	*(buffer + 11) = '\0';
	ptr = buffer;
	while (rd_ret)
	{
		rd_ret = read(fd, buffer, 100);
		*(buffer + (rd_ret)) = '\0';
		printf("\n|%s|\n", buffer);
		printf("read_return: %d\n", rd_ret);
	}
	bufferfiller(ptr);
	printf("\nlast one: |%s|\n", buffer);
	rd_ret = read(fd, buffer, 1);
	printf("\nread return when reading 1 byte from the end of file: %d\n", rd_ret);
	free(buffer);
	close(fd);
	check_leaks();
	return (0);
}