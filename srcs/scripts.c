/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scripts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:14:30 by rdanyell          #+#    #+#             */
/*   Updated: 2022/02/07 15:52:23 by rdanyell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	best_script(t_list *current, t_info *info)
{
	int	min_score;

	if (info->script1 <= info->script2)
	{
		min_score = info->script1;
		info->script_number = 1;
	}
	else
	{
		min_score = info->script2;
		info->script_number = 2;
	}
	if (info->script3 < min_score)
	{
		min_score = info->script3;
		info->script_number = 3;
	}
	if (info->script4 < min_score)
	{
		min_score = info->script4;
		info->script_number = 4;
	}
	current->elem_score = min_score;
}

void	do_script1(t_list **stack_a, t_list **stack_b, t_info *info)
{
	int	rra;
	int	rrb;

	rra = info->rra - info->rrr;
	rrb = info->rrb - info->rrr;
	while (info->rrr > 0)
	{
		ft_rrr(stack_a, stack_b, 1);
		info->rrr--;
	}
	while (rra > 0)
	{
		ft_rra(stack_a, 1);
		rra--;
	}
	while (rrb > 0)
	{
		ft_rrb(stack_b, 1);
		rrb--;
	}
}

void	do_script2(t_list **stack_a, t_list **stack_b, t_info *info)
{
	int	ra;
	int	rb;

	ra = info->ra - info->rr;
	rb = info->rb - info->rr;
	while (info->rr > 0)
	{
		ft_rr(stack_a, stack_b, 1);
		info->rr--;
	}
	while (ra > 0)
	{
		ft_ra(stack_a, 1);
		ra--;
	}
	while (rb > 0)
	{
		ft_rb(stack_b, 1);
		rb--;
	}
}

void	do_script3(t_list **stack_a, t_list **stack_b, t_info *info)
{
	while (info->ra > 0)
	{
		ft_ra(stack_a, 1);
		info->ra--;
	}
	while (info->rrb > 0)
	{
		ft_rrb(stack_b, 1);
		info->rrb--;
	}
}

void	do_script4(t_list **stack_a, t_list **stack_b, t_info *info)
{
	while (info->rra > 0)
	{
		ft_rra(stack_a, 1);
		info->rra--;
	}
	while (info->rb > 0)
	{
		ft_rb(stack_b, 1);
		info->rb--;
	}
}
