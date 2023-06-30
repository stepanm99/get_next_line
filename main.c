/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 23:24:46 by smelicha          #+#    #+#             */
/*   Updated: 2023/06/27 21:36:47 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*buffer1;
	char	*buffer2;
	int		i;

	i = 0;
	buffer1 = NULL;
	buffer2 = NULL;
	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test1.txt", O_RDONLY);

	while (i < 10)
	{
		buffer1 = get_next_line(fd1);
		buffer2 = get_next_line(fd2);
		printf("%s", buffer1);
		printf("%s", buffer2);
		if (buffer1 != NULL)
			free(buffer1);
		if (buffer2 != NULL)
			free(buffer2);
		i++;
	}
	close(fd1);
	close(fd2);
	return (0);
}