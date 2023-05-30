/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:24:58 by smelicha          #+#    #+#             */
/*   Updated: 2023/05/30 22:18:15 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*buffer_start;
	int		eoflag;

	eoflag = 1;
	buffer = malloc(1024);
	if (buffer == NULL)
		return (0);
	buffer_start = buffer;
	while (*(buffer - 1) != '\n' && eoflag)
	{
		eoflag = read(fd, buffer, 1);
		*(buffer + 1) = '\0';
		buffer++;
	}
	return (buffer_start);
}

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
