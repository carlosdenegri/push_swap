/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadenegr <cadenegr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:17:47 by cadenegr          #+#    #+#             */
/*   Updated: 2023/10/26 18:17:50 by cadenegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_stack(struct s_stack *stack)
{
	stack->top = -1;
}

bool	is_full(struct s_stack *stack)
{
	return (stack->top == MAX_SIZE - 1);
}

bool	is_empty(struct s_stack *stack)
{
	return (stack->top == -1);
}

void	push(struct s_stack *stack, int value)
{
	if (is_full(stack))
	{
		printf("Stack is full. Cannot push %d.\n", value);
		return ;
	}
	stack->items[++stack->top] = value;
}

int	pop(struct s_stack *stack)
{
	if (is_empty(stack))
	{
		printf("Stack is empty. Cannot pop.\n");
		return (-1);
	}
	return (stack->items[stack->top--]);
}
