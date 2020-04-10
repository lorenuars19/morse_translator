/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 16:24:08 by lorenuar          #+#    #+#             */
/*   Updated: 2020/04/10 16:53:47 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "morslator.h"

size_t	abs(ssize_t	num)
{
	return ((num > 0) ? num : -num);
}

size_t	str_lento(char *s, char c)
{
	size_t	lento;

	lento = 0;
	while (s && s[lento] && s[lento] != c)
		lento++;
	return (lento);
}
size_t	str_revlento(char *s, char c)
{
	size_t	lento;
	size_t	slen;

	slen = str_lento(s, '\0');
	lento = slen
	while (s && s[lento] && s[lento] != c)
		lento--;
	return (abs(lento - slen));
}

char	*str_dupto()
{
	char()
}

char	*str_revdupto()
{
	char()
}
