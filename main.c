/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 23:24:46 by smelicha          #+#    #+#             */
/*   Updated: 2023/06/26 01:41:31 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*buffer;
	int		i;

	i = 0;
	buffer = NULL;
	fd = open("test.txt", O_RDONLY);
//	printf("File descriptor : %d\n\n", fd);
//	printf("BUFFER_SIZE : %d\n\n", BUFFER_SIZE);
	while (i < 10)
	{
		buffer = get_next_line(fd);
//		if (buffer == NULL)
//			break ;
		write(1, buffer, buffer_length(buffer));
//		printf("%s", buffer);
		free(buffer);
		i++;
	}
	close(fd);
//	check_leaks();
	return (0);


	/*char	buffer[BUFFER_SIZE + 1];
	char	*result;
	int		i;

	i = 0;
	while (i < 4)
	{
		*(buffer + i) = i + '0';
		i++;
	}
	*(buffer + i) = '\n';
	i++;
	while (i < BUFFER_SIZE)
	{
		*(buffer + i) = i + '0';
		i++;
	}
	*(buffer + 8) = '\n';
	printf("\n%s\n", buffer);
	result = line_from_buffer(buffer);
	printf("\nline from buffer: |%s|\n", result);
	free(result);
	line_remove(buffer);
	printf("\n%s\n", buffer);
	result = line_from_buffer(buffer);
	printf("\nline from buffer: |%s|\n", result);
	free(result);
	line_remove(buffer);
	printf("\n%s\n", buffer);
	result = line_from_buffer(buffer);
	printf("\nline from buffer: |%s|\n", result);
	free(result);
	line_remove(buffer);
	printf("\n%s\n", buffer);
	result = line_from_buffer(buffer);
	printf("\nline from buffer: |%s|\n", result);
	free(result);
	line_remove(buffer);
	printf("\n%s\n", buffer);
	return (0);*/
}