/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   morsec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:16:28 by lorenuar          #+#    #+#             */
/*   Updated: 2020/04/10 22:35:40 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "morsec.h"

int		morsec(int direction, char *input)
{
	t_dict *dict;

	if (!(dict = get_dict("dictionary.txt")))
	{
		clear_dict(&dict);
		return (err("DICT ERROR"));
	}
	if (DEBUG)
		print_dict(dict);
	if (direction == 1)
	{
	 	puts("Reverse");
		puts(input);
	}

	if (direction == 0)
	{
		puts("Morse -- ");
		puts(input);
	}
	clear_dict(&dict);
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
