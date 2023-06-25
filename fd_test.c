#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int	main()
{
	char	*buffer;
	int		fd;
	int		buffer_size;
	int		i;
	int		read_return;

	fd = 0;
	i = 0;
	read_return = 0;
	buffer_size = 10;
	buffer = (char*)calloc(buffer_size + 1, sizeof(char));
	if (!buffer)
		return (-1);
	fd = open("test.txt", O_RDONLY);
	printf("File descriptor after opening a file: %d\n", fd);
	read_return = read(fd, buffer, buffer_size);
	printf("read output: %s\n", buffer);
	printf("read_return = %d\n", read_return);
	close(fd);
	printf("File descriptor after closing a file: %d\n", fd);
	while(i != buffer_size)
	{
		*(buffer + i) = '\0';
		i++;
	}
	read_return = read(fd, buffer, buffer_size);
	printf("read output: %s\n", buffer);
	printf("read_return = %d\n", read_return);
	return (0);
}
