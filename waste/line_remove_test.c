#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
/*TODO:
In test 3 with buffer size 42 and 43 characters in file without new line:
prints the line two times and second time it prints less characters...
And I yet don't know why. More info at the end of log.txt
*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

//void check_leaks();

int		check_new_line(char *buffer);
void	line_remove(char *buffer);
char	*line_from_buffer(char *buffer);
int		buffer_length(char *buffer);
char	*get_next_line(int fd);
char	*read_fd(char *static_buffer, int fd);
char	*read_fd_helper(char *ret_buff, char *stat_buff, int rdr, int flag);
char	*buffer_add_resize(char *buffer, char *temp_buffer);
int		buffer_to_buffer(char *buffer1, char *buffer2);

int	main(void)
{
	int		fd;
	char	*buffer;
	int		i;

	i = 0;
	buffer = NULL;
	fd = open("test.txt", O_RDONLY);
//	printf("File descriptor : %d\n\n", fd);
//	printf("BUFFER_SIZE : %d\n\n", BUFFER_SIZE);
	while (i < 1000)
	{
		buffer = get_next_line(fd);
		if (buffer == NULL)
			break ;
		write(1, buffer, buffer_length(buffer));
		free(buffer);
		i++;
	}
	close(fd);
//	check_leaks();
	return (0);


	/*char	buffer[BUFFER_SIZE + 1];
	char	*result;
	int		i;

	i = 0;
	while (i < 4)
	{
		*(buffer + i) = i + '0';
		i++;
	}
	*(buffer + i) = '\n';
	i++;
	while (i < BUFFER_SIZE)
	{
		*(buffer + i) = i + '0';
		i++;
	}
	*(buffer + 8) = '\n';
	printf("\n%s\n", buffer);
	result = line_from_buffer(buffer);
	printf("\nline from buffer: |%s|\n", result);
	free(result);
	line_remove(buffer);
	printf("\n%s\n", buffer);
	result = line_from_buffer(buffer);
	printf("\nline from buffer: |%s|\n", result);
	free(result);
	line_remove(buffer);
	printf("\n%s\n", buffer);
	result = line_from_buffer(buffer);
	printf("\nline from buffer: |%s|\n", result);
	free(result);
	line_remove(buffer);
	printf("\n%s\n", buffer);
	result = line_from_buffer(buffer);
	printf("\nline from buffer: |%s|\n", result);
	free(result);
	line_remove(buffer);
	printf("\n%s\n", buffer);
	return (0);*/
}

char	*get_next_line(int fd)
{
	static char	*static_buffer;
	char		*return_buffer;

	return_buffer = NULL;
	if (!static_buffer && (BUFFER_SIZE > 0) && ((fd > 0) && (fd < 1000)))
		static_buffer = malloc(BUFFER_SIZE + 1);
	if (!static_buffer || (BUFFER_SIZE <= 0) || (fd <= 0))
		return (NULL);
	return_buffer = read_fd(static_buffer, fd);
	if (buffer_length(return_buffer))
		return (return_buffer);
	if (!buffer_length(static_buffer) && static_buffer)
	{
		free(static_buffer);
		return (NULL);
	}
	return (NULL);
}

char	*read_fd(char *static_buffer, int fd)
{
	int		read_return;
	char	*return_buffer;

	return_buffer = NULL;
	read_return = BUFFER_SIZE;
	if (check_new_line(static_buffer))
	{
		return_buffer = line_from_buffer(static_buffer);
		line_remove(static_buffer);
		return (return_buffer);
	}
	while (!check_new_line(static_buffer))
	{
		if (read_return == 0 && !buffer_length(static_buffer) && !buffer_length(return_buffer))
			return (NULL);
		if (read_return != BUFFER_SIZE && !check_new_line(static_buffer))
			break ;
		return_buffer = buffer_add_resize(return_buffer, static_buffer);
		read_return = read(fd, static_buffer, BUFFER_SIZE);
		read_fd_helper(return_buffer, static_buffer, read_return, (BUFFER_SIZE + 1));
	}
	if (read_return != 0)
		return_buffer = read_fd_helper(return_buffer, static_buffer, 0, 1);
	line_remove(static_buffer);
	return (return_buffer);
}

char	*read_fd_helper(char *ret_buff, char *stat_buff, int rdr, int flag)
{
	char *temp1;
	char *temp2;

	temp1 = NULL;
	if (flag == 1)
	{
		temp1 = line_from_buffer(stat_buff);
		temp2 = buffer_add_resize(ret_buff, temp1);
		free(temp1);
		temp1 = NULL;
		return (temp2);
	}
	if (flag > 2)
		*(stat_buff + rdr) = '\0';
	return (NULL);
}
/*returns reallocated return_buffer with added data from static_buffer*/
char	*buffer_add_resize(char *return_buffer, char *static_buffer)
{
	char	*temp;
	int		return_buffer_l;
	int		static_buffer_l;

	temp = NULL;
	return_buffer_l = buffer_length(return_buffer);
	static_buffer_l = buffer_length(static_buffer);
	if ((return_buffer_l + static_buffer_l) == 0)
		return (NULL);
	temp = malloc(return_buffer_l + static_buffer_l + 1);
	if (!temp)
		return (NULL);
	*(temp + (return_buffer_l + static_buffer_l)) = '\0';
	if (return_buffer)
	{
		buffer_to_buffer(temp, return_buffer);
		free(return_buffer);
		return_buffer = NULL;
	}
	buffer_to_buffer((temp + return_buffer_l), static_buffer);
	return (temp);
}

char	*line_from_buffer(char *static_buffer)
{
	char	*return_buffer;
	int		line_length;
	int		i;

	i = 0;
	return_buffer = NULL;
	line_length = check_new_line(static_buffer);
	if (line_length == 0 && !buffer_length(static_buffer))
		return (NULL);
	else if (!line_length && buffer_length(static_buffer))
		line_length = buffer_length(static_buffer);
	if (line_length > 0)
		return_buffer = malloc(line_length + 1);
	else
		return (NULL);
	*(return_buffer + line_length) = '\0';
	while (i < line_length)
	{
		*(return_buffer + i) = *(static_buffer + i);
		i++;
	}
	return (return_buffer);
}

int		check_new_line(char *buffer)
{
	int	i;
	int	new_line_pos;

	i = 0;
	new_line_pos = 0;
	if (!buffer)
		return (0);
	while (*(buffer + i) && !new_line_pos)
	{
		if (((*(buffer + i) == '\n') && !new_line_pos))
			new_line_pos = i + 1;
		if ((((*(buffer + i) == '\0')) && !new_line_pos) && (i < BUFFER_SIZE))
			new_line_pos = i + 1;
		i++;
	}
	return (new_line_pos);
}

void	line_remove(char *buffer)
{
	int	line_length;
	int	i;

	i = 0;
	line_length = check_new_line(buffer);
//	printf("\nfrom line_remove: %d\n", line_length);
	if (line_length == 0)
	{
		while (i != BUFFER_SIZE)
		{
			*(buffer + i) = '\0';
			i++;
		}
	}
	while ((i + line_length) != BUFFER_SIZE)
	{
		*(buffer + i) = *(buffer + (i + line_length));
		i++;
	}
	while (i != BUFFER_SIZE)
	{
		*(buffer + i) = '\0';
		i++;
	}
}
int		buffer_length(char *buffer)
{
	int	i;

	i = 0;
	if (buffer == NULL)
		return (0);
	while (*(buffer + i))
		i++;
	return (i);
}
int	buffer_to_buffer(char *buffer1, char *buffer2)
{
	int	i;

	i = 0;
	while (*(buffer2 + i))
	{
		*(buffer1 + i) = *(buffer2 + i);
		i++;
	}
//	i++;
	*(buffer1 + i) = '\0';
	return (i);
}