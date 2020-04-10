/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 13:36:58 by lorenuar          #+#    #+#             */
/*   Updated: 2020/04/10 19:59:50 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "morsec.h"

int		check_line(char *s)
{
	while (s && *s && is_not(*s, BLANK))
		s++;
	s++;
	if (s && *s && is_not(*s, BLANK))
		return (0);
	while (s && *s && is_only(*s, BLANK))
		s++;
	s++;
	if (s && *s && !is_only(*s, MORSE))
		return (0);
	while (s && *s && is_only(*s, MORSE))
		s++;
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
		printf("word : %s | symb : %s\n", curr.word, curr.symb);
		append_node(&dict, new_node(curr.word, curr.symb));
	}

	print_dict(dict);
	return (NULL);
}
