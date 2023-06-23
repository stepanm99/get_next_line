#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

int		check_new_line(char *buffer)
{
	int	i;
	int	new_line_pos;

	i = 0;
	new_line_pos = 0;
	if (!buffer)
		return (0);
	while (*(buffer + i) && !new_line_pos)
	{
		if (((*(buffer + i) == '\n') && !new_line_pos))
			new_line_pos = i + 1;
		if ((((*(buffer + i) == '\0')) && !new_line_pos) && (i < BUFFER_SIZE))
			new_line_pos = i + 1;
		i++;
	}
	return (new_line_pos);
}

int 	main(void)
{
	char buffer[] = "tes\nst of \n new line";
	char buffer1[] = "buffer without new line";

	printf("\nreturn: %i\n", check_new_line(buffer));
	printf("\nreturn: %i\n", check_new_line(buffer1));
	return (0);
}