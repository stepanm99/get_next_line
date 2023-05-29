/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:33:16 by smelicha          #+#    #+#             */
/*   Updated: 2023/04/13 21:04:04 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	dsts(char *dest, const char *src, size_t l)
{
	size_t	i;

	i = 0;
	while (l > 0)
	{
		dest[i] = src[i];
		l--;
		i++;
	}
}

static void	sstd(char *dest, const char *src, size_t l)
{
	size_t	i;

	i = l - 1;
	while (l > 0)
	{
		dest[i] = src[i];
		l--;
		i--;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t l)
{
	if (dest == src)
		return (dest);
	if (dest < src)
	{
		dsts((char *)dest, (const char *)src, l);
		return (dest);
	}
	if (dest > src)
	{
		sstd((char *)dest, (const char *)src, l);
		return (dest);
	}
	return (NULL);
}
