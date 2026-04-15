/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrade <bandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 15:34:55 by bandrade          #+#    #+#             */
/*   Updated: 2026/04/15 17:39:20 by bandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// print da stack (debug)
void	print_stack(t_stack *s, char name)
{
	t_node	*tmp;

	tmp = s->top;
	printf("Stack %c: ", name);
	while (tmp)
	{
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
}

int	main(void)
{
	t_stack a;
	t_stack b;

	// criando nodes manualmente
	t_node n1 = {1, NULL, NULL};
	t_node n2 = {2, NULL, NULL};
	t_node n3 = {3, NULL, NULL};

	// montando stack A: 1 -> 2 -> 3
	a.top = &n1;
	n1.next = &n2;
	n2.prev = &n1;
	n2.next = &n3;
	n3.prev = &n2;
	a.bottom = &n3;
	a.size = 3;

	// stack B vazia
	b.top = NULL;
	b.bottom = NULL;
	b.size = 0;

	// ================= TESTES =================

	printf("Inicial:\n");
	print_stack(&a, 'A');
	print_stack(&b, 'B');

	printf("\n--- RA ---\n");
	ra(&a);
	print_stack(&a, 'A');

	printf("\n--- PB ---\n");
	pb(&a, &b);
	print_stack(&a, 'A');
	print_stack(&b, 'B');

	printf("\n--- PA ---\n");
	pa(&a, &b);
	print_stack(&a, 'A');
	print_stack(&b, 'B');

	printf("\n--- MULTIPLE RA ---\n");
	ra(&a);
	ra(&a);
	ra(&a);
	print_stack(&a, 'A');

	return (0);
}
