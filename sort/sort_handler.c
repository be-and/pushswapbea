/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrade <bandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:02:25 by pride-ol          #+#    #+#             */
/*   Updated: 2026/04/28 14:04:08 by bandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_handler(t_list *a, t_list *b)
{
	if (a->size == 2)
		sa(a);
	else if (a->size == 3)
		sort_3(a);
	else if (a->size <= 5)
		sort_5(a, b);
	else
		simple_sort(a, b);
}
