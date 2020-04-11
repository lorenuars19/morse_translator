/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   morsec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:16:28 by lorenuar          #+#    #+#             */
/*   Updated: 2020/04/11 17:41:52 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "morsec.h"

int		morsec(int direction, char *input)
{
	t_chain *dict;
	char	*resl;

	dict = NULL;
	resl = NULL;
	// if (!(dict = get_dict("dictionary.txt")))
	// {
	// 	clear_dict(&dict);
	// 	return (err("DICT ERROR"));
	// }
	if (DEBUG)
	{
		//print_chain_dict(dict);
	}
	if (direction == 1)
	{
		// if ((resl = rev_translator(dict)) == NULL)
		// {
		// 	return (err("TRANSLATOR ERROR"));
		// }
	}

	if (direction == 0)
	{
		if ((resl = translator(dict, input)) == NULL)
		{
			return (err("TRANSLATOR ERROR"));
		}
		puts(resl);
		puts(input);
	}
	clear_dict(&dict);
	return (0);
}

int		main(int argc, char *argv[])
{
	g_num_alloc = 1;
	g_num_free = 1;

	if (argc == 2)
	{
		if (morsec(0, argv[1]))
		{
			printf("SUMMARY : %lu A / %lu F\n", g_num_alloc, g_num_free);
			return (1);
		}
	}
	else if (argc == 3 && strncmp(argv[1], "-r", 3) == 0)
	{
		if (morsec(1, argv[2]))
		{
			return (1);
		}
	}
	else
	{
		err("ARGS ERROR");
		return (1);
	}
	printf("SUMMARY : %lu A / %lu F\n\n", g_num_alloc, g_num_free);
	return (0);
}
