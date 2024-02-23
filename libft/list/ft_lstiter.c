/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 22:44:18 by tsishika          #+#    #+#             */
/*   Updated: 2023/11/23 20:55:33 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp_list;

	if (lst == NULL || f == NULL)
		return ;
	while (lst != NULL)
	{
		tmp_list = lst;
		f(tmp_list->content);
		lst = lst->next;
	}
}
