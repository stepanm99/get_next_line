/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:21:17 by smelicha          #+#    #+#             */
/*   Updated: 2023/06/26 21:52:34 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int	buffer_to_buffer(char *buffer1, char *buffer2)
{
	int	i;

	i = 0;
	while (*(buffer2 + i))
	{
		*(buffer1 + i) = *(buffer2 + i);
		i++;
	}
	*(buffer1 + i) = '\0';
	return (i);
}

char	*ft_calloc(int size)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	while (size > 0)
	{
		*(ptr + i) = '\0';
		i++;
		size--;
	}
	return (ptr);
}
