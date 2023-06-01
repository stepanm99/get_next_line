#include <stdio.h>
#include "testheader.h"

int main(void)
{
	int	n;

	n = 0;
	while (n < 10)
	{
		printf("return of the function: %d\n", fcn());
		n++;
	}
	return (0);
}