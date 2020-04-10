/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 16:24:08 by lorenuar          #+#    #+#             */
/*   Updated: 2020/04/10 20:17:54 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "morsec.h"

size_t	str_len(char *s)
{
	size_t len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

size_t	str_lento(char *s, char *t)
{
	size_t	lento;

	lento = 0;
	while (s && s[lento] && is_only(s[lento], t))
		lento++;
	return (lento);
}

size_t	str_revlento(char *s, char *t)
{
	size_t	lento;
	size_t	slen;

	slen = str_lento(s, '\0');
	lento = slen;
	while (s && s[lento] && !is_only(s[lento], t))
		lento--;
	return (lento);
}

char	*str_dupto(char *s, char *t)
{
	char	*new;
	size_t	lento;
	size_t	i;

	i = 0;
	lento = str_lento(s, t);
	if (!(new = malloc(lento + 1 * sizeof(char))))
		return (NULL);
	while (s && *s && i <= lento)
		new[i++] = *s++;
	new[i] = '\0';
	return (new);
}

char	*str_revdupto(char *s, char *t)
{
	char	*new;
	size_t	lento;
	size_t	i;

	lento = str_revlento(s, t);
	i = 0;
	if (!(new = malloc(lento + 1 * sizeof(char))))
		return (NULL);
	while (s && *s && !is_not(*s, t))
		s++;
	while (s && *s && is_only(*s, t))
		s++;
	s++;
	while (s && *s && i < lento && !is_only(*s, t))
	{
		printf("s : %s\n", s);
		new[i++] = *s++;
	}
	new[i] = '\0';
	return (new);
}

int		is_only(char c, char *t)
{
	while (t && *t)
	{
		if (*t != c)
		{
			return (0);
		}
		t++;
	}
	return (1);
}

int		is_not(char c, char *t)
{
	while (t && *t)
	{
		if (*t == c)
		{
			return (1);
		}
		t++;
	}
	return (0);
}

size_t	has_to(char *s, char *t)
{
	size_t	i;

	while (t && *t)
	{
		i = 0;
		while (s && s[i])
		{
			if (*t != s[i])
				return (i);
			i++;
		}
		t++;
	}
	return (0);
}

size_t	revhas_to(char *s, char *t)
{
	size_t	i;

	while (t && *t)
	{
		i = str_lento(s, '\0');
		while (s && s[i])
		{
			if (*t != s[i])
				return (i);
			i--;
		}
		t++;
	}
	return (0);
}

void	putstr_fd(int fd, char *s)
{
	puts(s);
	write(fd, s, str_len(s));
}

int		err(char *s)
{
	putstr_fd(2, s);
	return (1);
}
void	*err_ptr(char *s)
{
	putstr_fd(2, s);
	return (NULL);
}
