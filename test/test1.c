#include "testheader.h"

int	fcn(void)
{
	static int	i;
	
	i++;
	return (i);
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

	current = first_link;
	next = first_link->next;
	free(first_link);
	current = current->next;
	while (current->next != NULL)
	{
		printf("pointer to free: %p\n", current);
		next = current->next;
		if (current != NULL)
		{
			free(current);
		}
		current = next;
	}
}