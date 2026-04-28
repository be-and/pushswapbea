/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrade <bandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 12:11:50 by pride-ol          #+#    #+#             */
/*   Updated: 2026/04/28 15:13:46 by bandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// initialize list a and b to size 0 and top/bottom to NULL
void	init_list(t_list *list)
{
	list->top = NULL;
	list->bottom = NULL;
	list->size = 0;
}

void	free_list(t_list *s)
{
	t_node	*current;
	t_node	*next;

	if (!s || !s->top)
		return ;
	current = s->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	s->top = NULL;
	s->bottom = NULL;
	s->size = 0;
}

void	error_exit(t_list *a, t_list *b)
{
	if (a)
		free_list(a);
	if (b)
		free_list(b);
	write(2, "Error\n", 6);
	exit(1);
}
