/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:47:46 by rdanyell          #+#    #+#             */
/*   Updated: 2022/02/21 15:50:27 by rdanyell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_stack(t_list *stack)
{
	t_list	*tmp;

	tmp = NULL;
	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

int	ft_is_sort(t_list *first, int len)
{
	t_list	*temp;

	temp = first;
	while (len - 1 > 0)
	{
		if (temp->num > temp->next->num)
			return (-1);
		len--;
		temp = temp->next;
	}
	return (0);
}

void	find_minmax(int *number, int len, t_info *info)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < len - 1)
	{
		j = len - 1;
		while (j > i)
		{
			if (number[j - 1] > number[j])
			{
				temp = number[j - 1];
				number[j - 1] = number[j];
				number[j] = temp;
			}
			j--;
		}
		i++;
	}
	i = 0;
	info->max = number[len - 1];
	info->min = number[0];
	info->med = number[len / 2];
	info->len_a = len;
}

t_list	*int_to_list(int *number, int len)
{
	int		i;
	t_list	*first;
	t_list	*tmp;

	ft_check_dup(number, len);
	i = len - 1;
	first = NULL;
	while (i >= 0)
	{
		tmp = malloc(sizeof(t_list));
		if (!tmp)
			exit(1);
		tmp->num = number[i];
		tmp->next = first;
		first = tmp;
		i--;
	}
	return (first);
}

t_list	*create_list(int argc, char **argv, t_info *info)
{
	t_list	*list;
	int		*number;
	int		len;

	list = NULL;
	if (argc == 2)
	{
		number = ft_parse_onearg(argv[1]);
		len = count_args(argv[1]);
	}
	if (argc > 2)
	{
		number = ft_parse_multiarg(argv, argc);
		len = argc - 1;
	}
	list = int_to_list(number, len);
	find_minmax(number, len, info);
	info->len_b = 0;
	free(number);
	if (ft_is_sort(list, len) == 0)
	{
		clear_stack(list);
		exit(1);
	}
	return (list);
}
