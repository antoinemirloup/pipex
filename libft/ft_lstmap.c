/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:31:47 by amirloup          #+#    #+#             */
/*   Updated: 2023/10/26 14:54:41 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*duplicate;
	void	*temp;

	duplicate = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		temp = f(lst->content);
		new_list = ft_lstnew(temp);
		if (!new_list)
		{
			ft_lstclear(&duplicate, del);
			del (temp);
			return (NULL);
		}
		ft_lstadd_back(&duplicate, new_list);
		lst = lst->next;
	}
	return (duplicate);
}
