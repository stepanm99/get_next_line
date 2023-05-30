#include "src/get_next_line.h"

int	main(void)
{
	int		fd;
	char	*buffer;
	int		i;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	printf("File descriptor : %d\n\n", fd);
	while (i < 200)
	{
		buffer = get_next_line(fd);
		if (buffer == NULL)
		{
			free(buffer);
		}
		printf("%s", buffer);
		free(buffer);
		i++;
	}
	close(fd);
	return (0);
}
