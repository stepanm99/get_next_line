/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 20:56:38 by smelicha          #+#    #+#             */
/*   Updated: 2023/04/17 22:43:09 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	negative_extreme(int fd)
{
	write(fd, "-2147483648", 11);
}

static void	print_number(int *a, int i, int fd)
{
	char	c;

	i--;
	while (i >= 0)
	{
		c = a[i] + '0';
		i--;
		write(fd, &c, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	int		a[11];

	i = 0;
	if (n == 0)
		write(fd, "0", 1);
	else if (n == -2147483648)
	{
		negative_extreme(fd);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * (-1);
	}
	while (n != 0)
	{
		a[i] = n % 10;
		n = n / 10;
		i++;
	}
	print_number(a, i, fd);
}
