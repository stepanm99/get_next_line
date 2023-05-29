/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:38:18 by smelicha          #+#    #+#             */
/*   Updated: 2023/04/17 23:54:08 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	initc(unsigned long *c)
{
	c[0] = 0;
	c[1] = 0;
	c[2] = 0;
}

static void	search(const char *str1, const char *str2,
	unsigned long n, unsigned long *c)
{
	while (str1[c[0]] != '\0' && c[0] < n)
	{
		while (str2[c[1]] != '\0')
		{
			if (str1[c[0] + c[1]] == str2[c[1]] && str1[c[0] + c[1]] != '\0')
			{
				c[1]++;
				c[2]++;
			}
			else
				c[1]++;
		}
		if (c[1] == c[2])
		{
			return ;
		}
		c[1] = 0;
		c[2] = 0;
		c[0]++;
	}
}

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	unsigned long	c[3];
	size_t			i;

	i = 0;
	if (str2[0] == '\0')
		return ((char *)str1);
	if (str1[0] == '\0' || n == 0)
		return (NULL);
	initc(c);
	search(str1, str2, n, c);
	while (str1[c[0] + i] == str2[i] && str2[i] != '\0')
		i++;
	if (str1[c[0] + i - 1] == str2[i - 1] && (c[0] + i - 1) < n)
	{
		return ((char *)&str1[c[0]]);
	}
	else
		return (NULL);
}
