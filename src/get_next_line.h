/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:22:26 by smelicha          #+#    #+#             */
/*   Updated: 2023/05/30 22:04:10 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct s_fdlist
{
	int				*fd;
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

char	*get_next_line(int fd);

#endif