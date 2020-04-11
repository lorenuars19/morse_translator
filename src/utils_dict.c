/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 15:53:06 by lorenuar          #+#    #+#             */
/*   Updated: 2020/04/11 16:11:42 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "morsec.h"

t_dict	*new_dict(char *word, char *symb)
{
	t_dict	*new;

	new = NULL;
	if (!(new = (t_dict *)malloc(sizeof(t_dict))))
	{
		return (err_ptr("MALLOC DICT ERROR"));
	}
	num_alloc("dict");
	new->word = word;
	new->symb = symb;
	return (new);
}

t_chain	*new_node(void *data)
{
	t_chain	*new;

	new = NULL;
	if (!(new = (t_chain*)malloc(sizeof(t_chain))))
	{
		return (err_ptr("MALLOC NODE ERROR"));
	}
	num_alloc("node");
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
		while (node && tmp && tmp->next)
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

void		del_dict(t_dict *dict)
{
	printf("Dict : <%p> \"%s\" | \"%s\"\n", dict, dict->word, dict->symb);

		free(dict->word);
		num_free("del_dict_word");
		dict->word = NULL;


		free(dict->symb);
		num_free("del_dict_symb");
		dict->symb = NULL;

}

void	del_node(t_chain *node)
{
	del_dict(node->data);

		free(node->data);
		num_free("del_node_data");
		node->data = NULL;

		free(node);
		num_free("del_node");
		node = NULL;

}

void		clear_dict(t_chain **chain)
{
	t_chain *tmp;

	if (chain && *chain)
	{
		tmp = (*chain)->next;
		del_dict((*chain)->data);
		del_node(*chain);
		*chain = tmp;
	}
}

void		print_node_dict(t_chain *chain)
{
	t_chain	*tmp;
	t_dict	*node;

	tmp = chain;
	if (!tmp)
	{
		puts("NULL NODE");
		return ;
	}
	node = (t_dict *)tmp->data;
	puts("\nNode :");
		printf("[node * %p | word \"%s\" | symbol \"%s\" "\
		"next *> %p]\n", \
		tmp, node->word, node->symb, tmp->next);
}

void		print_chain_dict(t_chain *chain)
{
	t_chain	*tmp;
	t_dict	*node;
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
		node = (t_dict *)tmp->data;
		printf("<%lu> \t [node * %p | word \"%s\" | symbol \"%s\" "\
		"next *> %p]\n", \
		i, tmp,node->word, node->symb, tmp->next);
		i++;
		tmp = tmp->next;
	}
	printf(">> Chain of %lu node(s) <<\n", chain_size(chain));
}
