/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:15:58 by rdanyell          #+#    #+#             */
/*   Updated: 2022/02/21 15:01:46 by rdanyell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_sort(t_list **stack_a, t_info *info)
{
	t_list	*head_a;

	head_a = *stack_a;
	info->ra = 1;
	info->rra = 0;
	while (head_a->num < head_a->next->num)
	{
		head_a = head_a->next;
		info->ra++;
	}
	info->rra = info->len_a - info->ra;
	finish_sort(stack_a, info);
}

void	fill_stack_a(t_list **stack_a, t_list **stack_b, t_info *info)
{
	t_list	*the_element;
	t_list	*head_b;
	int		size_b;

	size_b = info->len_b;
	the_element = info->best_elem;
	head_b = *stack_b;
	while (head_b-> num != the_element->num)
	{
		size_b--;
		head_b = head_b->next;
	}
	ft_count_score(*stack_a, the_element, info, size_b);
	best_script(the_element, info);
	if (info->script_number == 1)
		do_script1(stack_a, stack_b, info);
	else if (info->script_number == 2)
		do_script2(stack_a, stack_b, info);
	else if (info->script_number == 3)
		do_script3(stack_a, stack_b, info);
	else if (info->script_number == 4)
		do_script4(stack_a, stack_b, info);
	ft_pa(stack_a, stack_b, info, 1);
}

void	fill_stack_b_med(t_list **stack_a, t_list **stack_b, t_info *info)
{
	int	len;

	len = info->len_a;
	while (len > 0)
	{
		if ((*stack_a)->num == info->max || (*stack_a)->num == info->med || \
			(*stack_a)->num == info->min)
			ft_ra(stack_a, 1);
		else
		{
			if ((*stack_a)->num < info->med)
				ft_pb(stack_a, stack_b, info, 1);
			else
			{
				ft_pb(stack_a, stack_b, info, 1);
				ft_rb(stack_b, 1);
			}
		}
	len--;
	}
}

void	fill_stack_b(t_list **stack_a, t_list **stack_b, t_info *info)
{
	if (info->len_a < 10)
	{
		while (info->len_a > 3)
		{
			if ((*stack_a)->num == info->max || (*stack_a)->num == info->min)
				ft_ra(stack_a, 1);
			else
				ft_pb(stack_a, stack_b, info, 1);
		}
	}
	else
		fill_stack_b_med(stack_a, stack_b, info);
}

void	sort(t_list **stack_a, t_list **stack_b, t_info *info)
{
	int	size_b;

	fill_stack_b(stack_a, stack_b, info);
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
