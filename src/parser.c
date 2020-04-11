/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 13:36:58 by lorenuar          #+#    #+#             */
/*   Updated: 2020/04/11 10:21:47 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "morsec.h"

int		check_line(char *s)
{
	while (s && *s && !is_any(*s, BLANK))
	{
		s++;
	}
	if (s && *s && !is_any(*s, BLANK))
	{
		return (0);
	}
	while (s && *s && is_any(*s, BLANK))
	{
		s++;
	}
	if (s && *s && is_only(*s, MORSE_DICT))
	{
		return (0);
	}
	while (s && *s && is_only(*s, MORSE_DICT))
	{
		s++;
	}
	if (s && *s && !is_any(*s, MORSE_DICT))
	{
		return (0);
	}
	return (1);
}

t_chain	*get_chain(char *filename)
{
	t_chain	*curr;
	t_chain	*dict;
	t_dict	*node;
	char	*line;
	int		fd;


	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		return (err_ptr("INVALID DICT FILE"));
	}
	node = NULL;
	while (get_next_line(fd, &line))
	{
		if (!check_line(line))
		{
			return (err_ptr("DICT LINE INVALID"));
		}
		node->word = str_dupto(line, BLANK);
		node->symb = str_revdupto(line, BLANK);
		curr = new_node((void *)node);
		if ((append_node(&dict, curr)) == NULL)
		{
			del_node(curr);
			str_del(&line);
			return (err_ptr("DICT APPEND ERROR"));
		}
		str_del(&line);
	}
	str_del(&line);
	return (dict);
}
