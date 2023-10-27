/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadenegr <cadenegr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:45:18 by cadenegr          #+#    #+#             */
/*   Updated: 2023/10/27 11:40:15 by cadenegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	counter(int a, int b)
{
	static int	low_count = 0;
	static int	high_count = 0;

	if (a)
		low_count++;
	if (b)
		high_count++;
	// printf("low_count is: %d\n", low_count);
	// printf("high_count is: %d\n", high_count);
}

int	partition(int arr[], int low, int high)
{
	int			pivot;
	int			i;
	int			j;

	j = low;
	i = (low - 1);
	pivot = arr[high];
	counter(1, 0);
	while (j <= (high - 1))
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
		j++;
	}
	swap(&arr[i + 1], &arr[high]);
	counter(0, 1);
	return (i + 1);
}

void	quicksort(int arr[], int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		quicksort(arr, low, (pi - 1));
		quicksort(arr, (pi + 1), high);
	}
}

int	middle_index(int len)
{
	int	middle;

	if (len <= 0)
		return (-1);
	middle = (len / 2) - 1;
	return (middle);
}

int main() {
    int arr[] = {2000, 5, 2, 3, 99, 1001, 7, 2011};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    quicksort(arr, 0, n - 1);
	int length = sizeof(arr) / sizeof(arr[0]);
	int middle = middle_index(length);
	printf("Middle number: %d\n", arr[middle]);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
