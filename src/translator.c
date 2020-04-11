/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 13:36:47 by lorenuar          #+#    #+#             */
/*   Updated: 2020/04/11 18:49:34 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "morsec.h"

char		*translator(t_chain *dict, char *input)
{
	t_chain	*trsl;
	char	*temp;
	char	*word;

	trsl = NULL;
	temp = NULL;
	word = NULL;
	while (input && *input)
	{
		temp = str_dupto(input, BLANK);
		word = get_by_symbol(dict, temp);
		printf("Tmp : '%s' | Word : '%s'\n", temp, word);
		//append_node(&trsl, new_node(word));
		while (!is_any(*input, BLANK))
		{
			input++;
		}
		while (is_any(*input, BLANK))
		{
			input++;
		}
		str_del(&temp);
		return (NULL);
	}
	(void)dict;
	print_chain_trsl(trsl);
	return ("Hello");
}
