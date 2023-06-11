/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:54:53 by smelicha          #+#    #+#             */
/*   Updated: 2023/06/11 21:53:38 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**/
char	*get_next_line(int fd)
{
	static char	persbuff[BUFFER_SIZE + 1];
	char		*resbuff;

	if (check_new_line(persbuff))
	{
		buffer_to_buffer(resbuff, persbuff);
		line_remove(persbuff);
		return (resbuff);
	}
}

void	line_remove(char *persbuff)
{
	char	*temp;
	int		new_line_pos;
	int		i;

	i = 0;
	new_line_pos = check_new_line(persbuff);
	buffer_to_buffer(temp, (persbuff + new_line_pos));
	while ((persbuff + i))
	{
		*(persbuff + i) = '\0';
		i++;
	}
	i = 0;
	while ((temp + i))
	{
		*(persbuff + i) = *(temp + i);
	}
}

int	buffer_to_buffer(char *buffer1, char *buffer2)
{
	int	i;
	int	b2len;

	i = 0;
	b2len = buffer_length(buffer2);
	free(buffer1);
	buffer1 = malloc(b2len + 1);
	*(buffer1 + b2len) = '\0';
	while (*(buffer2 + i))
	{
		*(buffer1 + i) = *(buffer2 + i);
		i++;
	}
	return (i);
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
