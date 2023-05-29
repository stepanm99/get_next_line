/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:06:55 by smelicha          #+#    #+#             */
/*   Updated: 2023/04/08 17:27:26 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t		i;
	char		*ptr;

	i = 0;
	ptr = NULL;
	if ((char) c == '\0')
		return ((char *)str + ft_strlen((char *)str));
	if (str[i] == (char) c)
		ptr = (char *) str;
	while (str[i])
	{
		if (str[i] == (char) c)
			ptr = ((char *) str + i);
		i++;
	}
	return ((char *)ptr);
}
