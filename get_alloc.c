/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_alloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkocaman <mkocaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:51:08 by mkocaman          #+#    #+#             */
/*   Updated: 2024/03/22 22:51:08 by mkocaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alloc.h"
#include <stdlib.h>

t_alloc	*get_alloc(void)
{
	static t_alloc	alloc = {NULL, NULL};

	return (&alloc);
}

int	set_garbage(void *ptr)
{
	t_alloc	*alloc;

	alloc = get_alloc();
	if (alloc->ptr == NULL)
	{
		alloc->ptr = ptr;
		alloc->next = NULL;
	}
	else
	{
		while (alloc->next != NULL)
			alloc = alloc->next;
		alloc->next = malloc(sizeof(t_alloc));
		if (alloc->next == NULL)
			return (0);
		alloc->next->ptr = ptr;
		alloc->next->next = NULL;
	}
	return (1);
}

void	*automem(int size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		free_garbage();
		exit(1);
	}
	else if (!set_garbage(ptr))
	{
		free(ptr);
		free_garbage();
		exit(1);
	}
	return (ptr);
}

void automem_free(void *ptr)
{
	t_alloc	*alloc;
	t_alloc	*tmp;

	alloc = get_alloc();
	if (alloc->ptr == ptr)
	{
		tmp = alloc;
		alloc = alloc->next;
		free(tmp->ptr);
	}
	else
	{
		while (alloc->next != NULL)
		{
			if (alloc->next->ptr == ptr)
			{
				tmp = alloc->next;
				alloc->next = alloc->next->next;
				free(tmp->ptr);
				free(tmp);
				break ;
			}
			alloc = alloc->next;
		}
	}
}
