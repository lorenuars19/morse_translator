/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_wrapper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 16:45:43 by lorenuar          #+#    #+#             */
/*   Updated: 2020/04/11 16:52:30 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "morsec.h"

/*
** Undefine macros otherwise it references itself
*/

#undef malloc
#undef free

void	*my_malloc(size_t size)
{
	void	*ptr;
	//printf("malloc override > %lu\n", size);
	g_num_alloc++;
	ptr = malloc(size);
	return (ptr);
}

void	my_free(void *ptr)
{
	g_num_free++;
	free(ptr);
	ptr = NULL;
}

void	num_alloc(char *s)
{
	g_num_alloc++;
	printf("%s > Alloc %lu\n", s, g_num_alloc);
	(void)s;
}

void	num_free(char *s)
{
	g_num_free++;
	printf("%s > Free %lu\n", s, g_num_free);
	(void)s;
}
