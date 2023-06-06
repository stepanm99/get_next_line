#include "get_next_line.h"

void	check_leaks();
//*
int	main(void)
{
	int		fd;
	char	*buffer;
	int		i;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	printf("File descriptor : %d\n\n", fd);
	printf("BUFFER_SIZE : %d\n\n", BUFFER_SIZE);
	while (i < 3)
	{
		buffer = get_next_line(fd);
		if (buffer == NULL)
		{
			free(buffer);
			break ;
		}
		printf("%s", buffer);
		free(buffer);
		i++;
	}
	close(fd);
	check_leaks();
	return (0);
}
//*/
/*
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
		printf("return of the function: %d\n", fcn());
		n++;
		data->last_link = add_link(data->last_link, n);
	}
	data->link = data->first_link;
	while(data->link->next)
	{
		printf("From list: %d\n", data->link->fd);
		data->link = data->link->next;
	}
	printf("\nbefore deleting list\n");
	delete_list(data->first_link);
	free(data);
	check_leaks();
	return (0);
}//*/
