/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 13:36:47 by lorenuar          #+#    #+#             */
/*   Updated: 2020/04/11 18:03:12 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "morsec.h"

char		*translator(t_chain *dict, char *input)
{
	t_chain	*trsl;
	char	*tmp;

	while (input && *input)
	{
		tmp = str_dupto(input, BLANK);
		printf("Tmp : '%s'\n", tmp);
		append_node(&trsl, new_node(tmp));
		while (!is_any(*input, BLANK))
		{
			input++;
			printf("input : ''%s''\n", input);
		}
	}
	(void)dict;
	print_chain_trsl(trsl);
	return ("Hello");
}
