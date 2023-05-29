/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 18:33:43 by smelicha          #+#    #+#             */
/*   Updated: 2023/04/17 17:49:49 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p1;

	p1 = *lst;
	while (ft_lstsize(*lst))
	{
		*lst = p1->next;
		ft_lstdelone(p1, del);
		p1 = *lst;
	}
}
