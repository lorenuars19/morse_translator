/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 15:53:06 by lorenuar          #+#    #+#             */
/*   Updated: 2020/04/10 18:42:05 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "morsec.h"

t_dict	*new_node(char *word, char *symb)
{
	t_dict	*new;

	new = NULL;
	if (!(new = (t_dict*)malloc(sizeof(t_dict))))
		return (NULL);
	new->word = word;
	new->symb = symb;
	new->next = NULL;
	return (new);
}

void		append_node(t_dict **chain, t_dict *node)
{
	t_dict *tmp;

	tmp = NULL;
	if (chain && *chain && node)
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
}

size_t		dict_size(t_dict *chain)
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

void		del_node(t_dict *node)
{
	if (node)
	{
		free(node->word);
		node->word = NULL;
		free(node->symb);
		node->symb = NULL;
		free(node->next);
		node->next = NULL;
		free(node);
		node = NULL;
	}
}

void		clear_dict(t_dict **chain)
{
	t_dict *tmp;

	while (chain && *chain)
	{
		tmp = (*chain)->next;
		del_node(*chain);
		*chain = tmp;
	}
}

void		print_dict(t_dict *chain)
{
	t_dict	*tmp;
	size_t		i;

	tmp = chain;
	i = 0;
	if (!tmp)
	{
		puts("NULL");
		return ;
	}
	puts("\nChain :");
	while (tmp)
	{
		printf("<%lu> \t [node * %p | word \"%s\" | symbol \"%s\" "\
		"next *> %p]\n", \
		i, tmp, tmp->word, tmp->symb, tmp->next);
		i++;
		tmp = tmp->next;
	}
	printf(">> Chain of %lu node(s) <<\n", dict_size(chain));
}
