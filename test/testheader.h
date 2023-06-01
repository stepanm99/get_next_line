#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

#ifndef TEST_HEADER_H
# define TEST_HEADER_H

typedef struct	s_fdlist
{
	int				fd;
//	s_fdlist	*prev;
	struct s_fdlist	*next;
}				t_fdlist;

typedef struct	s_data
{
	t_fdlist	*first_link;
	t_fdlist	*last_link;
	t_fdlist	*link;
}				t_data;

int	fcn(void);
t_fdlist *new_list(int value);
t_fdlist *add_link(t_fdlist *current, int value);
void delete_list(t_fdlist *first_link);

#endif