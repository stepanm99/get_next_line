/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:24:58 by smelicha          #+#    #+#             */
/*   Updated: 2023/06/03 01:06:49 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	data_init(t_data *data)
{
	data->remains = NULL;
	data->big_buffer_small_file = 0;
	data->iter = 0;
	data->callnr = 0;
}

char	*remains_update(int i, char *remains)
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
}

char *get_next_line(fd)
{
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
