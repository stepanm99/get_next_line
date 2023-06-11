#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void	check_leaks();
char	*buffer_add_resize(char *buffer, char *temp_buffer);
int		check_new_line(char *buffer);
int		buffer_length(char *buffer);
char	*buffer_to_buffer(char *buffer);
void	line_remove(char *persbuff);

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
		if (((*(buffer + i) == '\n') || (*(buffer + i) == '\0'))
			&& !new_line_pos)
			new_line_pos = i + 1;
		i++;
	}
	return (new_line_pos);
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

char	*buffer_to_buffer(char *buffer)
{
	char	*temp;
	int		i;
	int		blen;

	i = 0;
	blen = buffer_length(buffer);
	temp = malloc(blen + 1);
	*(temp + blen) = '\0';
	while (*(buffer + i))
	{
		*(temp + i) = *(buffer + i);
		i++;
	}
	return (temp);
}

void	line_remove(char *persbuff)
{
	char	*temp;
	int		new_line_pos;
	int		i;

	i = 0;
	temp = NULL;
	new_line_pos = check_new_line(persbuff);
	temp = buffer_to_buffer((persbuff + new_line_pos));
	while (i < 21)
	{
		*(persbuff + i) = '\0';
		i++;
	}
	i = 0;
	while (*(temp + i) != '\0')
	{
		*(persbuff + i) = *(temp + i);
		i++;
	}
	free(temp);
}

char	*buffer_add_resize(char *buffer, char *temp_buffer)
{
	char	*temp;
	int		i;
	int		j;
	int		blen;
	int		tblen;

	i = 0;
	j = 0;
	blen = buffer_length(buffer);
	tblen = buffer_length(temp_buffer);
	temp = malloc((blen + tblen) + 1);
	*(temp + (blen + tblen)) = '\0';
	while (*(buffer + i))
	{
		*(temp + i) = *(buffer + i);
		i++;
	}
	while (*(temp_buffer + j))
	{
		*(temp + (i + j)) = *(temp_buffer + j);
		j++;
	}
	return (temp);
}

int	main(void)
{
	char	test[] = "test\ntesttest\ntest";
	char	test1[] = "secondtext test\n\n";
	char	*temp;

	temp = NULL;
	printf("\n|%s|\n", test);
	line_remove(test);
	printf("\n|%s|\n", test);
	temp = buffer_add_resize(test, test1);
	printf("\n|%s|\n", temp);
	free(temp);
	check_leaks();
	return (0);
}






/*#include "get_next_line.h"

int	fcn(void)
{
	static int	i;
	
	i++;
	return (i);
}

t_fdlist *new_flist(int value)
{
	t_fdlist	*new_list;

	new_list = malloc(sizeof(t_fdlist));
	new_list->fd = value;
	new_list->next = NULL;
	return (new_list);
}

t_fdlist *add_flink(t_fdlist *current, int value)
{
	t_fdlist	*new_link;

	new_link = malloc(sizeof(t_fdlist));
	new_link->fd = value;
	new_link->next = NULL;
	current->next = new_link;
	return (new_link);
}
void delete_flist(t_fdlist *first_link)
{
	t_fdlist	*next;
	t_fdlist	*current;

	current = NULL;
	if (first_link && first_link->next)
		current = first_link->next;
	while (current)
	{
		printf("Pointer to free: %p\n", current);
		next = current->next;
		free(current);
		current = next;
	}
	free(first_link);
}
t_fdlist *new_list(int value)
{
	t_fdlist	*new_list;

	new_list = malloc(sizeof(t_fdlist));
	new_list->fd = value;
	new_list->next = NULL;
	return (new_list);
}

t_fdlist *add_link(t_fdlist *current, int value)
{
	t_fdlist	*new_link;

	new_link = malloc(sizeof(t_fdlist));
	new_link->fd = value;
	new_link->next = NULL;
	current->next = new_link;
	return (new_link);
}
void delete_list(t_fdlist *first_link)
{
	t_fdlist	*next;
	t_fdlist	*current;

	current = NULL;
	if (first_link && first_link->next)
		current = first_link->next;
	while (current)
	{
		printf("Pointer to free: %p\n", current);
		next = current->next;
		free(current);
		current = next;
	}
	free(first_link);
}*/

/*void	free_stack(t_stack *stack)
{
	t_node	*curr;
	t_node	*last;

	curr = NULL;
	if (stack && stack->tail)
		curr = stack->tail;
	while (curr)
	{
		last = curr->next;
		free(curr);
		curr = last;
	}
	free(stack);
}*/