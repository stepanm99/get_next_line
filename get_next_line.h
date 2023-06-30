/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:22:26 by smelicha          #+#    #+#             */
/*   Updated: 2023/06/30 19:18:52 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

int		check_new_line(char *buffer);
void	line_remove(char *buffer);
char	*line_from_buffer(char *buffer);
int		buffer_length(char *buffer);
char	*get_next_line(int fd);
char	*read_fd(char *static_buffer, int fd);
char	*read_fd_helper(char *ret_buff, char *stat_buff, int rdr, int flag);
char	*buffer_add_resize(char *buffer, char *temp_buffer);
int		buffer_to_buffer(char *buffer1, char *buffer2);
char	*ft_calloc(int size);

#endif