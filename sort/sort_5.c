/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrade <bandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 14:03:55 by bandrade          #+#    #+#             */
/*   Updated: 2026/04/28 17:25:01 by bandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static t_node	*find_smallest(t_list *a)
{
	t_node	*curr;
	t_node	*min;

	curr = a->top;
	min = curr;
	while (curr)
	{
		if (curr->value < min->value)
			min = curr;
		curr = curr->next;
	}
	return (min);
}

static int	distance_top(t_list *a, t_node *target)
{
	int		i;
	t_node	*curr;

	i = 0;
	curr = a->top;
	while (curr && curr != target)
	{
		curr = curr->next;
		i++;
	}
	return (i);
}

static int	distance_bottom(t_list *a, t_node *target)
{
	int		i;
	t_node	*curr;

	i = 0;
	curr = a->bottom;
	while (curr && curr != target)
	{
		curr = curr->prev;
		i++;
	}
	return (i);
}

static void	rotate_to_node(t_list *a, t_node *target)
{
	int	top;
	int	bottom;

	while (a->top != target)
	{
		top = distance_top(a, target);
		bottom = distance_bottom(a, target);
		if (top <= bottom)
			ra(a);
		else
			rra(a);
	}
}

static void	push_smallest_to_b(t_list *a, t_list *b)
{
	t_node	*min;

	min = find_smallest(a);
	rotate_to_node(a, min);
	pb(a, b);
}

void	sort_5(t_list *a, t_list *b)
{
	while (a->size > 3)
		push_smallest_to_b(a, b);
	sort_3(a);
	while (b->size > 0)
		pa(a, b);
}
