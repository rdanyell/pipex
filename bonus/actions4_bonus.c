/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions4_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:27:06 by rdanyell          #+#    #+#             */
/*   Updated: 2022/02/21 16:49:33 by rdanyell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	del_top_stack(t_list **stack)
{
	t_list	*tmp;

	tmp = NULL;
	if (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
	}
	free(tmp);
}

void	add_top_stack(t_list **stack, int number)
{
	t_list	*tmp;

	tmp = malloc(sizeof(t_list));
	if (!tmp)
		exit(0);
	tmp->num = number;
	tmp->next = *stack;
	*stack = tmp;
}

void	ft_pa(t_list **stack_a, t_list **stack_b, t_info *info, int flag)
{
	int	temp;

	if (!(*stack_b))
		return ;
	else
	{
		temp = (*stack_b)->num;
		del_top_stack(stack_b);
		add_top_stack(stack_a, temp);
		info->len_b -= 1;
		info->len_a += 1;
		if (flag == 1)
			write(1, "pa\n", 3);
	}
}

void	ft_pb(t_list **stack_a, t_list **stack_b, t_info *info, int flag)
{
	int	temp;

	if (!(*stack_a))
		return ;
	if (stack_a)
	{
		temp = (*stack_a)->num;
		del_top_stack(stack_a);
		add_top_stack(stack_b, temp);
	}
	info->len_b += 1;
	info->len_a -= 1;
	if (flag == 1)
		write(1, "pb\n", 3);
}
