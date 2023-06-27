/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 23:21:49 by smelicha          #+#    #+#             */
/*   Updated: 2023/06/27 18:40:17 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*static_buffer[FD_SETSIZE];
	char		*return_buffer;

	return_buffer = NULL;
	if (((BUFFER_SIZE <= 0) || (read(fd, 0, 0) < 0)) && static_buffer[fd])
		return (free(static_buffer[fd]), static_buffer[fd] = NULL, NULL);
	if (((BUFFER_SIZE <= 0) || (read(fd, 0, 0) < 0)) && !static_buffer[fd])
		return (static_buffer[fd] = NULL, NULL);
	if (!static_buffer[fd])
		static_buffer[fd] = ft_calloc(BUFFER_SIZE + 1);
	return_buffer = read_fd(static_buffer[fd], fd);
	if (buffer_length(return_buffer))
		return (return_buffer);
	if (!buffer_length(static_buffer[fd]) && static_buffer[fd])
		return (free(static_buffer[fd]), static_buffer[fd] = NULL, NULL);
	return (NULL);
}

char	*read_fd(char *stat_buf, int fd)
{
	int		rd_ret;
	char	*ret_buf;

	ret_buf = NULL;
	rd_ret = BUFFER_SIZE;
	if (check_new_line(stat_buf))
	{
		ret_buf = line_from_buffer(stat_buf);
		line_remove(stat_buf);
		return (ret_buf);
	}
	while (!check_new_line(stat_buf))
	{
		if (rd_ret < 1 && !buffer_length(stat_buf) && !buffer_length(ret_buf))
			return (NULL);
		if (rd_ret != BUFFER_SIZE && !check_new_line(stat_buf))
			break ;
		ret_buf = buffer_add_resize(ret_buf, stat_buf);
		rd_ret = read(fd, stat_buf, BUFFER_SIZE);
		read_fd_helper(ret_buf, stat_buf, rd_ret, (BUFFER_SIZE + 1));
	}
	if (rd_ret != 0)
		ret_buf = read_fd_helper(ret_buf, stat_buf, 0, 1);
	line_remove(stat_buf);
	return (ret_buf);
}

char	*read_fd_helper(char *ret_buff, char *stat_buff, int rdr, int flag)
{
	char	*temp1;
	char	*temp2;

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
	temp = ft_calloc (return_buffer_l + static_buffer_l + 1);
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
		return_buffer = ft_calloc(line_length + 1);
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
