/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrade <bandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 15:34:55 by bandrade          #+#    #+#             */
/*   Updated: 2026/05/04 16:34:42 by bandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list		a;
	t_list		b;
	t_config	config;

	if (argc < 2)
		return (0);
	ft_memset(&config, 0, sizeof(t_config));
	init_list(&a);
	init_list(&b);
	if (!fill_list(&a, argc, argv, &config))
		error_exit(&a, &b);
	index_list(&a);
	sort_handler(&a, &b, &config);
	if (config.bench_mode)
		print_benchmark_report(&config);
	free_list(&a);
	free_list(&b);
	return (0);
}
