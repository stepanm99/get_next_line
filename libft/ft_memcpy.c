/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:13:04 by smelicha          #+#    #+#             */
/*   Updated: 2023/04/09 19:08:32 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t l)
{
	char		*destination;
	const char	*source;
	size_t		i;

	i = 0;
	source = src;
	destination = dest;
	if (destination == NULL && source == NULL)
		return (NULL);
	while (l > 0)
	{
		destination[i] = source[i];
		l--;
		i++;
	}
	return (dest);
}
