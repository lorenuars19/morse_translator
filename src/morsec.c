/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   morsec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:16:28 by lorenuar          #+#    #+#             */
/*   Updated: 2020/04/10 20:16:26 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "morsec.h"

int		morslator(int direction, char *input)
{
	t_dict *dict;

	if ((dict = get_dict("dictionary_nope.txt")))
		return (err("DICT ERROR"));

	if (direction == 1)
	{
	 	puts("Reverse");
		puts(input);
	}

	if (direction == 0)
	{
		puts("Morse");
		puts(input);
	}
	return (0);
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
	{
		if (morslator(0, argv[1]))
			return (1);
	}
	else if (argc == 3 && strncmp(argv[1], "-r", 3) == 0)
	{
		if (morslator(1, argv[2]))
			return (1);
	}
	return (0);
}