/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klebon <klebon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 20:18:36 by klebon            #+#    #+#             */
/*   Updated: 2018/04/08 12:18:11 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*templst;
	t_list	*lststart;

	if (!lst)
		return (NULL);
	if (!(newlst = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	newlst = f(lst);
	lststart = newlst;
	lst = lst->next;
	while (lst)
	{
		if (!(templst = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		templst = f(lst);
		newlst->next = templst;
		newlst = newlst->next;
		lst = lst->next;
	}
	newlst->next = NULL;
	return (lststart);
}
