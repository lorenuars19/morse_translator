/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 16:24:08 by lorenuar          #+#    #+#             */
/*   Updated: 2020/04/10 18:42:21 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "morsec.h"


size_t	str_lento(char *s, char *t)
{
	size_t	lento;

	lento = 0;
	while (s && s[lento] && !is_only(s[lento], t))
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
	while (s && *s && i <= lento && !is_only(*s, t))
		new[i++] = *s++;
	new[i] = '\0';
	return (new);
}

char	*str_revdupto(char *s, char *t)
{
	char	*new;
	size_t	lento;
	size_t	i;

	i = 0;
	lento = str_lento(s, t);
	if (!(new = malloc(lento + 1 * sizeof(char))))
		return (NULL);
	while (s && *s && i <= lento && !is_only(*s, t))
		new[i++] = *s++;
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
