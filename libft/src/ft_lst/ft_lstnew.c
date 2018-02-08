/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 06:54:26 by jrobin            #+#    #+#             */
/*   Updated: 2018/01/30 02:22:44 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_lst.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*new;

	if (!(new = (t_list *)ft_memalloc(sizeof(t_list))))
		exit(1);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
		new->next = NULL;
	}
	else
	{
		new->content_size = content_size;
		if (!(new->content = ft_memalloc((ft_strlen((char *)content) + 1)
						* sizeof(char))))
			exit(1);
		ft_memcpy(new->content, content, content_size);
		new->next = NULL;
	}
	return (new);
}
