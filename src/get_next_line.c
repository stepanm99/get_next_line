/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:24:58 by smelicha          #+#    #+#             */
/*   Updated: 2023/05/30 21:25:27 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*buffer_start;

	buffer = malloc(1024);
	if (buffer == NULL)
		return (0);
	buffer_start = buffer;
	while (*(buffer - 1) != '\n')
	{
		read(fd, buffer, 1);
		*(buffer + 1) = '\0';
		buffer++;
	}
	return (buffer_start);
}