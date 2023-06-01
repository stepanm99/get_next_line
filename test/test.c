#include "testheader.h"

int main(void)
{
	int	n;
	t_data	*data;

	n = 0;
	data = malloc(sizeof(t_data));
	data->first_link = new_list(n);
	data->last_link = data->first_link;
	while (n < 10)
	{
		data->last_link = add_link(data->last_link, n);
		printf("return of the function: %d\n", fcn());
		n++;
	}
	data->link = data->first_link;
	while(data->link->next != NULL)
	{
		printf("From list: %d\n", data->link->fd);
		data->link = data->link->next;
	}
	printf("\nbefore deleting list\n");
	delete_list(data->first_link);
	return (0);
}
