/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 13:36:47 by lorenuar          #+#    #+#             */
/*   Updated: 2020/04/11 23:27:15 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "morsec.h"

char		*translator(t_chain *dict, char *input)
{
	t_chain	*trsl;
	char	*temp;
	char	*Bword;
	char	*word;


	trsl = NULL;
	temp = NULL;
	Bword = NULL;
	word = NULL;
	while (input && *input)
	{
		while (is_space(*input))
		{
			input++;
		}
		temp = str_dupto(input, BLANK);
		Bword = (char *)get_by_symbol(dict, temp);
		word = str_low(Bword);
		printf("temp '%s' | Bword '%s' *%p | word '%s'\n", temp, Bword, Bword, word);

		append_node(&trsl, new_node(word));

		while (!is_space(*input))
		{
			input++;
		}
		str_del(&temp);
		BR;
	}
	(void)dict;
	print_chain_trsl(trsl);
	clear_trsl(&trsl);
	return ("Hello");
}
