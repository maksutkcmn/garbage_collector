/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkocaman <mkocaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:51:34 by mkocaman          #+#    #+#             */
/*   Updated: 2024/03/22 22:51:34 by mkocaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOC_H
# define ALLOC_H

typedef struct s_alloc
{
	void *ptr;
	struct s_alloc *next;
}			t_alloc;
 
void	free_garbage(void);
void	*automem(int size);
void	automem_free(void *ptr);
t_alloc	*get_alloc(void);

#endif