/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadenegr <cadenegr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:16:28 by cadenegr          #+#    #+#             */
/*   Updated: 2023/10/26 18:44:40 by cadenegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MAX_SIZE 500
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>

struct s_stack 
{
	int	items[MAX_SIZE];
	int	top;
};
void	initialize_stack(struct s_stack *stack);
bool	is_full(struct s_stack *stack);
bool	is_empty(struct s_stack *stack);
void	push(struct s_stack *stack, int value);
int		pop(struct s_stack *stack);
void	swap(struct s_stack *stack);
void	rotate_right(struct s_stack *stack);
void	reverse_rotate(struct s_stack *stack);

#endif 