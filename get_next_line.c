/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 23:21:49 by smelicha          #+#    #+#             */
/*   Updated: 2023/06/23 23:22:07 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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