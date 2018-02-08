/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_insert_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 14:06:18 by jrobin            #+#    #+#             */
/*   Updated: 2018/01/30 01:23:29 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_lst.h"

int		lst_insert_sort(t_list *insert, t_list **lst, int (*f)())
{
	if (!f || !insert || !lst || !*lst)
		return (1);
	while (*lst && (*lst)->content)
	{
		if (*lst && f(insert->content, (*lst)->content) <= 0)
		{
			insert->next = *lst;
			*lst = insert;
			return (0);
		}
		lst = &((*lst)->next);
	}
	*lst = insert;
	return (0);
}
