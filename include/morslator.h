/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   morslator.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 13:36:53 by lorenuar          #+#    #+#             */
/*   Updated: 2020/04/10 16:44:14 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	_MORSLATOR_H
# define _MORSLATOR_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>

struct s_dict
{
	char			*word;
	char			*symb;
	struct s_dict	*next;
};
typedef struct s_dict t_dict;

int			get_next_line(int fd, char **line);
size_t		hasto(char *s, char c);
char		*jointo(char *s1, char *s2, char **tofree);

t_dict		*get_dict(char *filename);

#endif
