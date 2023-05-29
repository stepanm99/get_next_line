/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:41:46 by smelicha          #+#    #+#             */
/*   Updated: 2023/04/03 19:18:00 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	slen;
	size_t	dlen;

	i = 0;
	dlen = (size_t)ft_strlen(dest);
	slen = (size_t)ft_strlen(src);
	if (dlen >= size)
		return (size + slen);
	while (((size - 1) > (i + dlen)) && src[i] != '\0')
	{
		dest[i + dlen] = src[i];
		i++;
	}
	dest[i + dlen] = '\0';
	return (dlen + slen);
}
