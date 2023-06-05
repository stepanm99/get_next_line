/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:24:58 by smelicha          #+#    #+#             */
/*   Updated: 2023/06/06 00:07:42 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*void	data_init(t_data *data)
{
	data->remains = NULL;
	data->big_buffer_small_file = 0;
	data->iter = 0;
	data->callnr = 0;
}*/

/*char	*remains_update(int i, char *remains)
{
	int		j;
	char	*intermediate;

	j = 0;
	intermediate = malloc(BUFFER_SIZE - i);
	while (*(remains + i))
	{
		*(intermediate + j) = *(remains + i);
		i++;
		j++;
	}
	return (intermediate);
}*/



/*copies one buffer to another*/
void	buffer_to_buffer(char *buffer1, char *buffer2)
{

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
		return (-1);
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
void	bufer_add_resize(char *buffer, char *temp_buffer)
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
	*(temp_buffer + 1) = '\0';
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








	/*
	char			*buffer;
	static t_data	*data;
	static char		*remains;
	char			*result;
	int				i;
	int				j;
	int				readreturn;



	i = 0;
	j = 0;
	if (!data)
	{
		data = malloc(sizeof(t_data));
		if (!data)
			return (NULL);
		data_init(data);
	}
	buffer = malloc(BUFFER_SIZE);
	readreturn = read(fd, buffer, BUFFER_SIZE);
	if (readreturn < BUFFER_SIZE)
		data->big_buffer_small_file = 1;
	while (*(buffer + i) != '\n')
		i++;
	result = malloc(sizeof(char)*(i + 1));
	i = 0;
	while (*(buffer + i) != '\n')
	{
		*(result + i) = *(buffer + i);
		i++;
	}
	i++;
	*(result + i) = '\n';
	remains = malloc(BUFFER_SIZE - i);
	return (result);*/




	/*buffer = malloc(BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	read(fd, buffer, BUFFER_SIZE);
	while (*(buffer + i) != '\n')
		i++;
	result = malloc(sizeof(char)*(i + 1));
	i = 0;
	while (*(buffer + i) != '\n')
	{
		*(result + i) = *(buffer + i);
		i++;
	}
	i++;
	*(result + i) = '\n';
	remains = malloc(BUFFER_SIZE - i);
	while (*(buffer + i))
	{
		*(remains + j) = *(buffer + i);
		i++;
		j++;
	}
	remains = remains_update(i, remains);
	free(buffer);
	data->callnr++;
	return (result);*/
}


/*void	print_data(t_data *data)
{
	printf("\ndata->first_link: %p\n", data->first_link);
	printf("data->last_link: %p\n", data->last_link);
	printf("data->link: %p\n", data->link);
}

void	init_data(t_data *data)
{
	data->first_link = NULL;
	data->last_link = NULL;
	data->link = NULL;
}

char	*get_next_line(int fd)
{
	t_data	*data;
	char	*buffer;
	int		i;

	data = malloc(sizeof(t_data));
	buffer = malloc(BUFFER_SIZE);
	if (!data && !buffer)
		return (NULL);
	if (!data->first_link)
		new_list();
	init_data(data);
	print_data(data);
	return (buffer);
}*/


/*char	*get_next_line(int fd)
{
	char			*buffer;
	char			*buffer_start;
	static int		eoflag;
	int				i;

	eoflag = 1;
	i = 0;
	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (0);
	buffer_start = buffer;
	while ((*(buffer - 1) != '\n' && eoflag) && i <= BUFFER_SIZE)
	{
		eoflag = read(fd, buffer, 1);
		if (eoflag == 0)
		{
			*(buffer_start + (i + 1)) = '\0';
			return (buffer_start);
		}
		*(buffer + 1) = '\0';
		buffer++;
		i++;
	}
	*(buffer_start + (i + 1)) = '\0';
	return (buffer_start);
}*/

/*char	*get_next_line(int fd)
{
	char	buffer;
	int		i;
	int		eoflag;

	buffer = '\0';
	i = 0;
	eoflag = 1;
	while ((buffer != '\n' || buffer != EOF) && i < 50 && eoflag)
	{
		eoflag = read(fd, &buffer, 1);
		if (eoflag)
			printf("%c", buffer);
		i++;
	}
	return (NULL);
}*/
