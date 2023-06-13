/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:54:53 by smelicha          #+#    #+#             */
/*   Updated: 2023/06/13 21:07:36 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**/
char	*get_next_line(int fd)
{
	static char	persbuff[BUFFER_SIZE + 1];
	static int	eoflag;
	char		*resbuff;
	int			rdreturn;

	rdreturn = 0;
	resbuff = NULL;
	if (eoflag)
		return (NULL);
	
	return (NULL);
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