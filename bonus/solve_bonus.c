/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:14:50 by rdanyell          #+#    #+#             */
/*   Updated: 2022/02/21 16:27:30 by rdanyell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_presort(t_list *stack, t_info *info)
{
	t_list	*temp;
	int		count;
	int		len;

	temp = stack;
	len = info->len_a;
	count = 0;
	while (len - 1 > 0)
	{
		if (temp->num > temp->next->num)
			count++;
		len--;
		temp = temp->next;
	}
	if (count == 1 && stack->num > temp->num)
		return (0);
	return (1);
}

void	sort_two(t_list **stack_a)
{
	ft_sa(*stack_a, 1);
}

void	sort_three(t_list **stack_a, t_info *info)
{
	if ((ft_presort(*stack_a, info) == 0) && ((*stack_a)->num == info->max))
		ft_ra(stack_a, 1);
	else if (ft_presort(*stack_a, info) == 0)
		ft_rra(stack_a, 1);
	else if ((*stack_a)->num == info->max)
	{
		ft_sa(*stack_a, 1);
		ft_rra(stack_a, 1);
	}
	else
	{
		ft_sa(*stack_a, 1);
		if (ft_is_sort(*stack_a, info->len_a) != 0)
			ft_ra(stack_a, 1);
	}
}

void	sort_five(t_list **stack_a, t_list **stack_b, t_info *info)
{
	int	size_b;

	while (info->len_a > 3)
	{
		if ((*stack_a)->num == info->max || (*stack_a)->num == info->min)
			ft_ra(stack_a, 1);
		else
			ft_pb(stack_a, stack_b, info, 1);
	}
	if (ft_is_sort(*stack_a, info->len_a) != 0 && \
			ft_presort(*stack_a, info) != 0)
		sort_three(stack_a, info);
	select_element(stack_a, stack_b, info);
	size_b = info->len_b;
	while (size_b > 0)
	{
		select_element(stack_a, stack_b, info);
		fill_stack_a(stack_a, stack_b, info);
		size_b--;
	}
	if ((!(*stack_b)) && ft_is_sort(*stack_a, info->len_a) != 0)
		final_sort(stack_a, info);
}

void	solve(t_list **stack_a, t_list **stack_b, t_info *info)
{
	if (info->len_a == 2)
		sort_two(stack_a);
	else if (info->len_a == 3)
		sort_three(stack_a, info);
	else
		sort(stack_a, stack_b, info);
}
