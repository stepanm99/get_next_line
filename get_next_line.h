/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:22:26 by smelicha          #+#    #+#             */
/*   Updated: 2023/06/03 01:01:11 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_fdlist
{
	int				fd;
	struct s_fdlist	*next;
}					t_fdlist;

typedef struct s_bufflist
{
	char				*character;
	struct s_bufflist	*next;
}					t_bufflist;

typedef struct s_gnldata
{
	int		test;
}	t_gnldata;

typedef struct	s_data
{
	char	*remains;
	int		big_buffer_small_file;
	int		iter;
	int		callnr;
}				t_data;


int	fcn(void);
t_fdlist *new_list(int value);
t_fdlist *add_link(t_fdlist *current, int value);
void delete_list(t_fdlist *first_link);


char	*get_next_line(int fd);
#endif