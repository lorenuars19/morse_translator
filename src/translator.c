/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 13:36:47 by lorenuar          #+#    #+#             */
/*   Updated: 2020/04/12 13:19:20 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "morsec.h"

int		check_input(char *s)
{
	while (s && *s)
	{
		if (!is_only(*s, MORSE))
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
	(void)dict;
	if (!check_input(input))
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
	(void)dict;
	print_chain_trsl(trsl);



	clear_trsl(&trsl);
	return ("Hello");
}
