/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 13:36:58 by lorenuar          #+#    #+#             */
/*   Updated: 2020/04/10 22:08:58 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "morsec.h"

int		check_line(char *s)
{
	while (s && *s && !is_any(*s, BLANK))
		s++;
	if (s && *s && !is_any(*s, BLANK))
		return (0);
	while (s && *s && is_any(*s, BLANK))
		s++;
	if (s && *s && is_only(*s, MORSE_DICT))
		return (0);
	while (s && *s && is_only(*s, MORSE_DICT))
		s++;
	if (s && *s && !is_any(*s, MORSE_DICT))
		return (0);
	return (1);
}

t_dict	*get_dict(char *filename)
{
	t_dict	curr;
	t_dict	*dict;
	char	*line;
	int		fd;

	curr = (t_dict){NULL,NULL,NULL};
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (err_ptr("INVALID DICT FILE"));

	while (get_next_line(fd, &line))
	{
		if (!check_line(line))
			return (err_ptr("DICT LINE INVALID"));
		curr.word = str_dupto(line, BLANK);
		curr.symb = str_revdupto(line, BLANK);
		//printf("word : %s | symb : %s\n", curr.word, curr.symb);
		append_node(&dict, new_node(curr.word, curr.symb));
	}
	return (dict);
}
