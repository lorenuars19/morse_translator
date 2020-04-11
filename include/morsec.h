/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   morsec.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 13:36:53 by lorenuar          #+#    #+#             */
/*   Updated: 2020/04/11 10:33:57 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	_MORSLATOR_H
# define _MORSLATOR_H

# define BR printf("%d %s\n",__LINE__, __FUNCTION__);getchar();
# define D printf("%d %s\n",__LINE__, __FUNCTION__);

# ifndef DEBUG
#  define DEBUG 0
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

# define BLANK "\t\v\f\r "
# define MORSE_DICT ".-"
# define MORSE "\t\v\f\r /.-"

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>

struct s_dict
{
	char				*word;
	char				*symb;
};
typedef struct s_dict 	t_dict;
struct s_chain
{
	void				*data;
	struct s_chain 		*next;
};
typedef struct s_chain 	t_chain;

t_chain	*new_node(void *data);
void		*append_node(t_chain **chain, t_chain *node);
size_t		chain_size(t_chain *chain);
void		del_node(t_chain *node);
void		clear_chain(t_chain **chain);
void		print_chain(t_chain *chain);
void		print_node(t_chain *chain);

int			get_next_line(int fd, char **line);
size_t		hasto(char *s, char c);
char		*jointo(char *s1, char *s2, char **tofree);

size_t		str_lento(char *s, char *t);
size_t		str_revlento(char *s, char *t);
char		*str_dupto(char *s, char *t);
char		*str_revdupto(char *s, char *t);
int			is_only(char c, char *t);
int			is_any(char c, char *t);
void		putstr_fd(int fd, char *s);
int			err(char *s);
void		*err_ptr(char *s);
void		str_del(char **tofree);

char		*translator(t_chain *dict);



t_chain		*get_chain(char *filename);

#endif
