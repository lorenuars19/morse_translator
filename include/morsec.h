/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   morsec.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 13:36:53 by lorenuar          #+#    #+#             */
/*   Updated: 2020/04/10 20:17:29 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	_MORSLATOR_H
# define _MORSLATOR_H

# define BR getchar();
# define D printf("%d %s\n",__LINE__, __FUNCTION__); getchar();

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

# define BLANK "\t\v\f "
# define MORSE "\t\v\f /.-"

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

size_t		str_lento(char *s, char *t);
size_t		str_revlento(char *s, char *t);
char		*str_dupto(char *s, char *t);
char		*str_revdupto(char *s, char *t);
int			is_only(char c, char *t);
int			is_not(char c, char *t);
size_t		has_to(char *s, char *t);
size_t		revhas_to(char *s, char *t);
void	putstr_fd(int fd, char *s);
int			err(char *s);
void		*err_ptr(char *s);

t_dict		*new_node(char *word, char *symb);
void		append_node(t_dict **chain, t_dict *node);
size_t		dict_size(t_dict *chain);
void		del_node(t_dict *node);
void		clear_dict(t_dict **chain);
void		print_dict(t_dict *chain);

t_dict		*get_dict(char *filename);

#endif
