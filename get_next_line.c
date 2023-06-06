/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:24:58 by smelicha          #+#    #+#             */
/*   Updated: 2023/06/06 20:08:23 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*line_remove(char *buffer)
{
	char	*temp_buffer;
	int		line_length;
	int		buffer_length;

	line_length = check_new_line(buffer);
	buffer_length = buffer_lenth(buffer);
	temp_buffer = malloc((buffer_length - line_length) + 1);
	if (!temp_buffer)
		return (NULL);
	buffer_to_buffer(temp_buffer, (buffer + line_length));
	free (buffer);
	return (temp_buffer);
}

char	*line_from_buffer(char *buffer)
{
	char	*return_buffer;
	int		line_length;
	int		i;

	i = 0;
	line_length = check_new_line(buffer);
	if (!line_length)
		return (NULL);
	return_buffer = malloc(line_length + 1);
	*(return_buffer + line_length) = '\0';
	while (*(buffer + i) != '\n')
	{
		*(return_buffer + i) = *(buffer + i);
		i++;
	}
	return (return_buffer);
}

/*copies one buffer to another*/
void	buffer_to_buffer(char *buffer1, char *buffer2)
{
	int	i;

	while (*(buffer2 + i) != '\0')
	{
		*(buffer1 + i) = *(buffer2 + i);
		i++;
	}
	i++;
	*(buffer1 + i) = '\0';
}


/*counts how long buffer is*/
int	buffer_length(char *buffer)
{
	int	i;

	i = 0;
	if (buffer == NULL)
		return (NULL);
	while (*(buffer + i))
		i++;
	return (i);
}

/*checks whether is newline character present in buffer*/
int	check_new_line(char *buffer)
{
	int	i;

	i = 0;
	if (buffer == NULL)
		return (NULL);
	while (*(buffer + i) != '\n')
		i++;
	return (i);
}

/*appends temporary buffer from read_fd to static buffer
initializes three variables, temporary buffer (temp) and lengths of both buffers;
allocates temporary buffer to the total memory of the two buffers to be merged with a space for nullterminator
copies contents of the original buffer to temp by buffer_to_buffer function
frees the memory previously alocated to buffer
copies additional memory from temp_buffer to temporary buffer offset by the length of original buffer
returns temp as new buffer
*/
char	*bufer_add_resize(char *buffer, char *temp_buffer)
{
	char	*temp;
	int	buffer_l;
	int	temp_buffer_l;

	buffer_l = buffer_length(buffer);
	temp_buffer_l = buffer_length(temp_buffer);
	temp = malloc(buffer_l + temp_buffer_l + 1);
	if (!temp)
		return ;
	buffer_to_buffer(temp, buffer);
	free(buffer);
	buffer_to_buffer((temp + buffer_l), temp_buffer);
	return (temp);
}
/*read_fd reads from file descriptor until it find newline or file is at its end*/
char	*read_fd(int fd, char *buffer)
{
	int		read_return;
	char	*temp_buffer;

	read_return = 0;
	temp_buffer = malloc(BUFFER_SIZE + 1);
	if (!temp_buffer)
		return (NULL);
	*(temp_buffer + (BUFFER_SIZE + 1)) = '\0';
	while (!check_new_line(buffer))
	{
		read_return = read(fd, temp_buffer, BUFFER_SIZE);
		if (read_return == 0)
			break ;
		if (!check_new_line(temp_buffer))
			buffer = buffer_add_resize(buffer, temp_buffer);
		else
		{
			buffer = buffer_add_resize(buffer, temp_buffer);
			break ;
		}
	}
	free(temp_buffer);
	return (buffer);
}

char *get_next_line(fd)
{
	char		*rdbuffer;
	char		*resbuffer;
	static char	*persbuffer;
	int			bytes_read;

	bytes_read = 0;
	rdbuffer = NULL;
	rdbuffer = malloc((BUFFER_SIZE + 1));
	if (!rdbuffer)
		return (NULL);
	*(rdbuffer + (BUFFER_SIZE + 1)) = '\0';
	bytes_read = read(fd, rdbuffer, BUFFER_SIZE);
	printf("\nread buffer: \n%s\n\n", rdbuffer);
	printf("bytes read: %d\n", bytes_read);
	return (rdbuffer);
}
