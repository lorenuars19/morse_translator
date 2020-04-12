/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 13:36:47 by lorenuar          #+#    #+#             */
/*   Updated: 2020/04/12 15:18:59 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "morsec.h"

char	*to_str(t_chain *trsl)
{
	char	*new;
	char	*iter;
	t_chain	*tmp;
	size_t 	len;
	size_t	i;

	new = NULL;
	len = 0;
	tmp = trsl;
	while (tmp)
	{
		len += str_len((char *)tmp->data);
		tmp = tmp->next;
	}
	if (!(new = malloc(len + 1 * sizeof(char))))
	{
		return (err_ptr("TO_STR MALLOC ERROR"));
	}
	tmp = trsl;
	i = 0;
	while (tmp)
	{
		iter = (char *)tmp->data;
		while (iter && *iter && i < len)
		{
			new[i++] = *iter++;
		}
		tmp = tmp->next;
	}
	new[i] = '\0';
	clear_trsl(&trsl);
	return (new);
}

int		check_input(char *s, char *t)
{
	while (s && *s)
	{
		if (!is_only(*s, t))
		{
			return (0);
		}
		s++;
	}
	return (1);
}

char	*translator(t_chain *dict, char *input)
{
	t_chain	*trsl;
	char 	*temp;

	trsl = NULL;
	temp = NULL;
	if (!check_input(input, MORSE))
	{
		return (err_ptr("INVALID INPUT"));
	}
	while (input && *input)
	{
		while (*input && is_space(*input))
		{
			input++;
		}
	 	temp = str_dupto(input, BLANK);
		append_node(&trsl, new_node(get_by_symbol(dict, temp)));
		str_del(&temp);
		while (*input && !is_space(*input))
		{
			input++;
		}
	}
	if (DEBUG)
	{
		print_chain_trsl(trsl);
	}
	return (to_str(trsl));
}

char	*rev_translator(t_chain *dict, char *input)
{
	t_chain	*trsl;
	char 	*temp;
	char	*word;

	trsl = NULL;
	temp = NULL;
	while (input && *input)
	{
	 	temp = str_upp(str_ndup(input, 1));
		if ((word = get_by_word(dict, temp)) == NULL)
		{
			return (err_ptr("NOT IN DICTIONNARY"));
		}
		append_node(&trsl, new_node(word));
		str_del(&temp);
		input++;
		if (*input)
		{
			append_node(&trsl, new_node(str_dup(" ")));
		}
	}
	if (DEBUG)
	{
		print_chain_trsl(trsl);
	}
	return (to_str(trsl));
}
