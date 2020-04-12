/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   morsec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:16:28 by lorenuar          #+#    #+#             */
/*   Updated: 2020/04/12 13:47:11 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "morsec.h"

int		morsec(int direction, char *input)
{
	t_chain *dict;
	char	*resl;

	dict = NULL;
	resl = NULL;
	if (!(dict = get_dict("dictionary.txt")))
	{
		clear_dict(&dict);
		return (err("DICT ERROR"));
	}
	if (DEBUG)
	{
		//print_chain_dict(dict);
	}
	if (direction == 1)
	{
		if ((resl = rev_translator(dict, input)) == NULL)
		{
			clear_dict(&dict);
			return (err("REV TRANSLATOR ERROR"));
		}
		puts(resl);
		str_del(&resl);
	}

	if (direction == 0)
	{
		if ((resl = translator(dict, input)) == NULL)
		{
			clear_dict(&dict);
			return (err("TRANSLATOR ERROR"));
		}
		puts(resl);
		str_del(&resl);
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
			print_leaks();
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
	print_leaks();
	return (0);
}
