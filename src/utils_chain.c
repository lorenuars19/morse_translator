/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_chain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 17:50:47 by lorenuar          #+#    #+#             */
/*   Updated: 2020/04/12 13:08:55 by lorenuar         ###   ########.fr       */
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
	{
		return (err_ptr("APPEND NULL NODE"));
	}
	if (*chain)
	{
		tmp = *chain;
		while (node && tmp && tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = node;
	}
	else if (chain)
	{
		*chain = node;
	}
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
	//print_node(node);
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

void print_node(t_chain *node)
{
	if (!node)
	{
		puts("NULL NODe");
		return ;
	}
	printf("Node : <%p> | data %p | data \"%s\" | > next %p\n", \
	node, node->data, (char *)node->data, node->next);
}
