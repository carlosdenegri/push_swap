/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadenegr <cadenegr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:16:14 by cadenegr          #+#    #+#             */
/*   Updated: 2023/10/27 13:26:35 by cadenegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(struct s_stack *stack)
{
	int	temp;

	if (stack->top >= 1)
	{
		temp = stack->items[stack->top];
		stack->items[stack->top] = stack->items[stack->top - 1];
		stack->items[stack->top - 1] = temp;
	}
	else
		return ;
}

void	rotate_right(struct s_stack *stack)
{
	int	top_element;
	int	i;

	if (stack->top < 1)
		return ;

	i = stack->top;
	top_element = stack->items[stack->top];
	while (i > 0)
	{
		stack->items[i] = stack->items[i - 1];
		i--;
	}
	stack->items[0] = top_element;
}

void	reverse_rotate(struct s_stack *stack)
{
	int	bottom_element;
	int	i;

	if (stack->top < 1)
		return ;

	i = 0;
	bottom_element = stack->items[0];
	while (i < stack->top)
	{
		stack->items[i] = stack->items[i + 1];
		i++;
	}
	stack->items[stack->top] = bottom_element;
}
