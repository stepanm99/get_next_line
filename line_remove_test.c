#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
/*TODO:
line from buffer return all the buffer contents, not just one line!!!!!!!!!!!*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 12
# endif

int		check_new_line(char *buffer);
void	line_remove(char *buffer);
char	*line_from_buffer(char *buffer);
int		buffer_length(char *buffer);

int	main(void)
{
	char	buffer[BUFFER_SIZE + 1];
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
	return (0);
}

char	*line_from_buffer(char *buffer)
{
	char	*return_buffer;
	int		line_length;
	int		i;

	i = 0;
	return_buffer = NULL;
	line_length = check_new_line(buffer);
	printf("\nbuffer_length from line_from_buffer: %d\n", buffer_length(buffer));
	if (line_length == 0 && !buffer_length(buffer))
		return (NULL);
	else
		line_length = buffer_length(buffer);
	return_buffer = malloc(line_length + 1);
	*(return_buffer + line_length) = '\0';
	while (i < line_length)
	{
		*(return_buffer + i) = *(buffer + i);
		i++;
	}
	if (*(buffer + i) == '\n')
	{
		*(return_buffer + i) = *(buffer + i);
	}
	return (return_buffer);
}

int	check_new_line(char *buffer)
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
	printf("\nfrom line_remove: %d\n", line_length);
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
int	buffer_length(char *buffer)
{
	int	i;

	i = 0;
	if (buffer == NULL)
		return (0);
	while (*(buffer + i))
		i++;
	return (i);
}
