/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 13:36:58 by lorenuar          #+#    #+#             */
/*   Updated: 2020/04/10 18:42:33 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "morsec.h"

int		check_line(char *s)
{
	D;
	while (s && *s && is_only(*s, BLANK))
		s++;
	D;
	if (s && *++s && !is_only(*s, BLANK))
		return (0);
	D;
	while (s && *s && is_only(*s, BLANK))
		s++;
	D;
	if (s && *++s && !is_only(*s, MORSE))
		return (0);
	D;
	while (s && *s && is_only(*s, MORSE))
		s++;
	D;
	return (1);
}

t_dict	*get_dict(char *filename)
{
	t_dict	curr;
	t_dict	*dict;
	char	*line;
	int		fd;

	curr = (t_dict){NULL,NULL,NULL};
	if (!(fd = open(filename, O_RDONLY)))
		return (NULL);
	while (get_next_line(fd, &line))
	{
		if (!check_line(line))
			return (NULL);
		curr.word = str_dupto(line, BLANK);
		curr.symb = str_revdupto(line, BLANK);
		if (has_to(curr.word, BLANK) && has_to(curr.symb, MORSE))
			append_node(&dict, new_node(curr.word, curr.symb));
	}

	print_dict(dict);
	return (NULL);
}
