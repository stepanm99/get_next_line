/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:54:53 by smelicha          #+#    #+#             */
/*   Updated: 2023/06/11 21:18:10 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**/
char	*get_next_line(int fd)
{
	static char	persbuffer[BUFFER_SIZE + 1];
	char		*resbuffer;
	int 		i;

	i = 0;
	
	resbuffer = malloc(buffer_length(persbuffer) + 1);
	buffer_to_buffer(buffer, persbuffer);
	return (buffer);
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
	i++;
	*(buffer1 + i) = '\0';
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
		if (((*(buffer + i) == '\n') || (*(buffer + i) == '\0')) && !new_line_pos)
			new_line_pos = i + 1;
		i++;
	}
	return (new_line_pos);
}