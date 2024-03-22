/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_garbage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkocaman <mkocaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 23:02:09 by mkocaman          #+#    #+#             */
/*   Updated: 2024/03/22 23:02:09 by mkocaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alloc.h"
#include <stdlib.h>

void	free_garbage(void)
{
	t_alloc	*alloc;
	t_alloc	*tmp;

	alloc = get_alloc();
	while (alloc != NULL)
	{
		tmp = alloc;
		alloc = alloc->next;
		free(tmp->ptr);
	}
	free(tmp);
}
