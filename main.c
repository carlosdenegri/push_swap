/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadenegr <cadenegr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:22:05 by cadenegr          #+#    #+#             */
/*   Updated: 2023/10/27 16:38:07 by cadenegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*argument(const char *s);

int	main (int argc, char *argv[])
{
	int				i;
	int				*arr;
	struct s_stack	stack1;
	struct s_stack	stack2;

	if (argc < 2)
		return (0);
	initialize_stack(&stack1);
	initialize_stack(&stack2);
	i = 0;
	if (argc < 3)
	{
		arr = argument(argv[1]);
		if (arr == NULL)
			return (1);
		while (arr[i])
		{
			printf("%d ", arr[i]);
			i++;
		}
		free (arr);
	}
	else
	{
		i = 1;
		while (i <= argc - 1)
		{
			printf("%d ", atoi(argv[i]));
			i++;
		}
	}
	// i = 1;
	// while (i < argc)
	// {
	// 	value = divided_argument(argv[i]);
	// 	push(&stack1, value);
	// 	i++;
	// }

	// rotate_right(&stack1);
	// swap(&stack1);
	// rotate_right(&stack1);
	// rotate_right(&stack1);
	// swap(&stack1);
	// rotate_right(&stack1);
	// swap(&stack1);
	// reverse_rotate(&stack1);
	// swap(&stack1);
	// reverse_rotate(&stack1);
	// reverse_rotate(&stack1);
	// reverse_rotate(&stack1);
	// reverse_rotate(&stack1);
	// swap(&stack1);
	// rotate_right(&stack1);
	// swap(&stack1);
	// rotate_right(&stack1);
	// swap(&stack1);
	// reverse_rotate(&stack1);

	// printf("Stack 1: ");
	// while (!is_empty(&stack1))
	// {
	// 	printf("%d ", pop(&stack1));
	// }
	// printf("\nStack 2: ");
	// while (!is_empty(&stack2))
	// {
	// 	printf("%d ", pop(&stack2));
	// }
	return (0);
}
