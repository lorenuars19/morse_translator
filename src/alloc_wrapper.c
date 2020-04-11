/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_wrapper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 16:45:43 by lorenuar          #+#    #+#             */
/*   Updated: 2020/04/11 19:24:50 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "morsec.h"

/*
** Undefine macros otherwise it references itself
*/
#ifdef malloc
#undef malloc
#endif

#ifdef free
#undef free
#endif

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

void	print_leaks(void)
{
	if (WRAP)
	{
		if (g_num_free != g_num_alloc)
		{
			printf("\n\033[31;1m/!\\ Leak /!\\ %lu Alloc / %lu Free\033[0m\n\n", g_num_alloc, g_num_free);
		}
		else
		{
			printf("\n\033[32;1m(: No Leak :) %lu Alloc / %lu Free\033[0m\n\n", g_num_alloc, g_num_free);
		}
	}
}
