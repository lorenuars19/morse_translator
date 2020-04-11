/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_trsl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 17:45:45 by lorenuar          #+#    #+#             */
/*   Updated: 2020/04/11 17:57:57 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "morsec.h"



void		print_chain_trsl(t_chain *chain)
{
	t_chain	*tmp;
	size_t		i;

	tmp = chain;
	i = 0;
	if (!tmp)
	{
		puts("NULL CHAIN");
		return ;
	}
	puts("\nChain :");
	while (tmp)
	{
		printf("<%lu> \t [node * %p | trsl \"%s\" next *> %p]\n", \
		i, tmp, (char *)tmp->data, tmp->next);
		i++;
		tmp = tmp->next;
	}
	printf(">> Chain of %lu node(s) <<\n", chain_size(chain));
}

void		print_node_trsl(t_chain *chain)
{
	t_chain	*tmp;

	tmp = chain;
	if (!tmp)
	{
		puts("NULL NODE");
		return ;
	}
	puts("\nNode :");
		printf("[node * %p | trsl  \"%s\" next *> %p]\n", \
		tmp, (char *)tmp->data, tmp->next);
}
