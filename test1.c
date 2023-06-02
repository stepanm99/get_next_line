#include "get_next_line.h"

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
}

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