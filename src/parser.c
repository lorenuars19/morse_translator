/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 13:36:58 by lorenuar          #+#    #+#             */
/*   Updated: 2020/04/10 16:41:32 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "morslator.h"

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
		curr.word = jointo(line)
	}

	return (NULL);
}
