/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_chain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 17:50:47 by lorenuar          #+#    #+#             */
/*   Updated: 2020/04/11 17:59:20 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "morsec.h"

t_chain	*new_node(void *data)
{
	t_chain	*new;

	new = NULL;
	if (!(new = (t_chain*)malloc(sizeof(t_chain))))
	{
		return (err_ptr("MALLOC NODE ERROR"));
	}
	new->data = data;
	new->next = NULL;
	return (new);
}

void		*append_node(t_chain **chain, t_chain *node)
{
	t_chain *tmp;

	tmp = NULL;
	if (!node)
		return (err_ptr("APPEND NULL NODE"));
	if (*chain)
	{
		tmp = *chain;
		while (
			node &&
			tmp &&
			tmp->next
		)
		{
			tmp = tmp->next;
		}
		tmp->next = node;
	}
	else if (chain)
		*chain = node;
	return (node);
}

size_t		chain_size(t_chain *chain)
{
	size_t	size;

	size = 0;
	while (chain)
	{
		chain = chain->next;
		size++;
	}
	return (size);
}

void	del_node(t_chain *node)
{
	del_dict(node->data);
	if (node->data)
	{
		free(node->data);
		node->data = NULL;
	}
	if (node)
	{
		free(node);
		node = NULL;
	}
}
