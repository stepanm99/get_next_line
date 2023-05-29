/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:22:26 by smelicha          #+#    #+#             */
/*   Updated: 2023/04/05 19:32:04 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	slen;
	size_t	i;
	char	*ptr;

	if (!s || !f)
		return (NULL);
	i = 0;
	slen = ft_strlen(s);
	ptr = (char *)ft_calloc(slen + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	while (i < slen)
	{
		ptr[i] = (*f)(i, (char)s[i]);
		i++;
	}
	ptr[i] = '\0';
	return ((char *)ptr);
}
