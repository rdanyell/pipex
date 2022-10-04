/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scores.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:09:33 by rdanyell          #+#    #+#             */
/*   Updated: 2022/02/07 15:27:01 by rdanyell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_rotations_a(t_list *stack_a, t_list *current, t_info *info)
{
	int		len_a;
	int		ra_max;
	int		flag;
	t_list	*head_a;

	head_a = stack_a;
	len_a = info->len_a;
	ra_max = info->len_a;
	flag = 0;
	while (ra_max--)
	{
		if (head_a->num < current->num)
			flag = 1;
		if ((head_a->num > current->num) && flag == 1)
			break ;
		info->ra++;
		head_a = head_a->next;
	}
	if (info->ra == len_a)
		info->ra = 0;
	info->rra = len_a - info->ra;
}	

void	count_double_rotations(t_info *info)
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;

	ra = info->ra;
	rb = info->rb;
	rra = info->rra;
	rrb = info->rrb;
	while (ra > 0 && rb > 0)
	{
		info->rr++;
		ra--;
		rb--;
	}
	while ((rra > 0) && (rrb > 0))
	{
		info->rrr++;
		rra--;
		rrb--;
	}
}

void	count_rotations(t_list *head_a, t_list *current, t_info *info,
			int size_b)
{
	int	len_b;

	len_b = info->len_b;
	info->rrb = size_b;
	if (info->len_b == 1)
		info->rrb = 0;
	info->rb = len_b - size_b;
	info->ra = 0;
	info->rr = 0;
	info->rra = 0;
	info->rrr = 0;
	count_rotations_a(head_a, current, info);
	count_double_rotations(info);
}

void	ft_count_score(t_list *head_a, t_list *current, t_info *info,
			int size_b)
{
	count_rotations(head_a, current, info, size_b);
	info->script1 = info->rrr + info->rra + info->rrb - info->rrr - info->rrr;
	info->script2 = info->rr + info->ra + info->rb - info->rr - info->rr;
	info->script3 = info->ra + info->rrb;
	info->script4 = info->rb + info->rra;
	best_script(current, info);
}

void	select_element(t_list **stack_a, t_list **stack_b, t_info *info)
{
	t_list	*current;
	t_list	*head_a;
	t_list	*head_b;
	int		size_b;

	size_b = info->len_b;
	current = *stack_b;
	while (size_b > 0)
	{
		head_a = *stack_a;
		ft_count_score(head_a, current, info, size_b);
		current = current->next;
		size_b--;
	}
	info->best_elem = *stack_b;
	head_b = *stack_b;
	while (head_b)
	{
		if (info->best_elem->elem_score > head_b->elem_score)
			info->best_elem = head_b;
		head_b = head_b->next;
	}
}
