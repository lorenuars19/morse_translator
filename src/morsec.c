/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   morsec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:16:28 by lorenuar          #+#    #+#             */
/*   Updated: 2020/04/11 10:35:45 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "morsec.h"

int		morsec(int direction, char *input)
{
	t_chain *dict;
	char	*resl;

	dict = NULL;
	resl = NULL;
	if (!(dict = get_chain("dictionary.txt")))
	{
		clear_chain(&dict);
		return (err("DICT ERROR"));
	}
	if (DEBUG)
		print_chain(dict);
	if (direction == 1)
	{
		if ((resl = translator(dict)) == NULL)
		{
			return (err("TRANSLATOR ERROR"));
		}
	}

	if (direction == 0)
	{
		puts("Morse -- ");
		puts(input);
	}
	clear_chain(&dict);
	return (0);
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
	{
		if (morsec(0, argv[1]))
			return (1);
	}
	else if (argc == 3 && strncmp(argv[1], "-r", 3) == 0)
	{
		if (morsec(1, argv[2]))
			return (1);
	}
	else
	{
		err("ARGS ERROR");
		return (1);
	}
	return (0);
}
