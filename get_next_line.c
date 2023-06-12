/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:54:53 by smelicha          #+#    #+#             */
/*   Updated: 2023/06/11 23:20:02 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**/
char	*get_next_line(int fd)
{
	static char	persbuff[BUFFER_SIZE + 1];
	char		*resbuff;
	int			rdreturn;

	while (!check_new_line(resbuff))
	{
	if (check_new_line(persbuff))
	{
		resbuff = line_from_buffer(persbuff);
		line_remove(persbuff);
		return (resbuff);
	}
	if (!check_new_line(persbuff))
	{
		resbuff = buffer_to_buffer(persbuff);
		rdreturn = read(fd, persbuff, BUFFER_SIZE);
		if (rdreturn == 0)
			return (NULL);
		if (rdreturn < BUFFER_SIZE)
			return (resbuff);
		if (rdreturn == BUFFER_SIZE)
			resbuff = buffer_add_resize(resbuff, persbuff);
	}
	}
	return (NULL);
}

char	*line_from_buffer(char *buffer)
{
	char	*return_buffer;
	int		line_length;
	int		i;

	i = 0;
	return_buffer = NULL;
	line_length = check_new_line(buffer);
//	if (!line_length)
//		return (NULL);
	return_buffer = malloc(line_length + 1);
	*(return_buffer + line_length) = '\0';
	while (*(buffer + i) != '\n')
	{
		*(return_buffer + i) = *(buffer + i);
		i++;
	}
	if (*(buffer + i) == '\n')
	{
//		i++;
		*(return_buffer + i) = *(buffer + i);
	}
	return (return_buffer);
}

char	*buffer_add_resize(char *buffer, char *temp_buffer)
{
	char	*temp;
	int		i;
	int		j;
	int		blen;
	int		tblen;

	i = 0;
	j = 0;
	blen = buffer_length(buffer);
	tblen = buffer_length(temp_buffer);
	temp = malloc((blen + tblen) + 1);
	*(temp + (blen + tblen)) = '\0';
	while (*(buffer + i))
	{
		*(temp + i) = *(buffer + i);
		i++;
	}
	free(buffer);
	while (*(temp_buffer + j))
	{
		*(temp + (i + j)) = *(temp_buffer + j);
		j++;
	}
	return (temp);
}

void	line_remove(char *persbuff)
{
	char	*temp;
	int		new_line_pos;
	int		i;

	i = 0;
	temp = NULL;
	new_line_pos = check_new_line(persbuff);
	temp = buffer_to_buffer((persbuff + new_line_pos));
	while (i < 21)
	{
		*(persbuff + i) = '\0';
		i++;
	}
	i = 0;
	while (*(temp + i) != '\0')
	{
		*(persbuff + i) = *(temp + i);
		i++;
	}
	free(temp);
}

char	*buffer_to_buffer(char *buffer)
{
	char	*temp;
	int		i;
	int		blen;

	i = 0;
	blen = buffer_length(buffer);
	temp = malloc(blen + 1);
	*(temp + blen) = '\0';
	while (*(buffer + i))
	{
		*(temp + i) = *(buffer + i);
		i++;
	}
	return (temp);
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
		if (((*(buffer + i) == '\n') || (*(buffer + i) == '\0'))
			&& !new_line_pos)
			new_line_pos = i + 1;
		i++;
	}
	return (new_line_pos);
}
