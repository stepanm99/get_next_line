/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:22:26 by smelicha          #+#    #+#             */
/*   Updated: 2023/06/12 21:14:58 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
void	line_remove(char *persbuff);
char	*line_from_buffer(char *buffer);
char	*buffer_to_buffer(char *buffer);
int		buffer_length(char *buffer);
int		check_new_line(char *buffer);
char	*buffer_add_resize(char *buffer, char *temp_buffer);
char	*read_fd(int fd, char *buffer, int *eoflagp);

#endif