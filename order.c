/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerchi <mcerchi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:56:05 by mcerchi           #+#    #+#             */
/*   Updated: 2022/02/17 16:14:04 by mcerchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	*ft_copy_cont(t_list *stack_a, int size)
{
	printf("controllo in copy_cont:\t"); lst_display(stack_a);
	int	*arr;
	int	i;

	i = 0;
	arr = (int *) malloc (sizeof(int) * size + 1);
	if (!arr)
		ft_display_exit();
	while(stack_a->next != NULL)
	{
		arr[i++] = (stack_a)->content;
		stack_a = (stack_a)->next;
	}
	printf("controllo dopo copy_cont:\t"); lst_display(stack_a);
	printf("*dst é pieno? controlliamo:\t%d %d %d", arr[0], arr[1], arr[2]);
	return (arr);
}

int	ft_min_nbr(int a, int b)
{
	int a1;
	int b1;

	a1 = a;
	b1 = b;
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	if (a == b)
		return (a1);
	if (a < b)
		return (a1);
	return (b1);
}

int ft_the_needed(int min, int max, int size)
{
	int i;

	if (min > (size / 2))
		min = min - size;
	if (max > (size / 2))
		max = max - size;
	i = ft_min_nbr(max, min);
	return (i);
}

int	ft_choose_best_nbr_a(t_list **stack_a, int size, int sep_one, int sep_two)
{
	int	pos_first;
	int	pos_last;
	int	pos;

	pos_first = -1;
	pos_last = 0;
	pos = 0;
	while (*stack_a != NULL)
	{
		if ((*stack_a)->content >= sep_one && (*stack_a)->content < sep_two)
		{
			if (pos_first == -1)
				pos_first = pos;
			pos_last = pos;
		}
		*stack_a = (*stack_a)->next;
		pos++;
	}
	if (pos_first == -1)
		return (size + 1);
	return (ft_the_needed(pos_first, pos_last, size));
}

int	ft_choose_best_nbr_b(t_list **stack_b, int size)
{
	int	max;
	int	pos_max;
	int	min;
	int	pos_min;
	int	pos;

	max = (*stack_b)->content;
	min = (*stack_b)->content;
	pos_max = 0;
	pos_min = 0;
	pos = 0;
	while (*stack_b != NULL)
	{
		*stack_b = (*stack_b)->next;
		if ((*stack_b)->content > max)
		{
			max = (*stack_b)->content;
			pos_max = pos;
		}
		else if ((*stack_b)->content < min)
		{
			min = (*stack_b)->content;
			pos_min = pos;
		}
		pos++;
	}
	return (ft_the_needed(pos_min, pos_max, size));
}
