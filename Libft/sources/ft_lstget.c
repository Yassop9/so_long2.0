/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yben-yag <yben-yag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:24:34 by yben-yag          #+#    #+#             */
/*   Updated: 2024/02/16 13:04:20 by yben-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/includes/libft.h"

t_list	*ft_lstget(t_list *lst, int index)
{
	t_list	*n;
	int		i;

	i = 0;
	n = lst;
	if (n == NULL)
		return (NULL);
	if (n->next == NULL)
		return (n);
	while (n != NULL)
	{
		if (i >= index)
			return (n);
		n = n->next;
		i++;
	}
	return (NULL);
}
