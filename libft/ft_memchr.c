/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:52:18 by smelicha          #+#    #+#             */
/*   Updated: 2023/04/10 22:23:26 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (NULL);
	n--;
	while (*(char *)(s + i) != (char) c && i < n)
		i++;
	if (*(char *)(s + i) == (char) c)
		return ((void *)(s + i));
	else
		return (NULL);
}
