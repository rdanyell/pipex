/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:25:59 by rdanyell          #+#    #+#             */
/*   Updated: 2022/02/07 11:41:07 by rdanyell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_list **stack_a, int flag)
{
	t_list	*current;
	t_list	*previous;

	current = *stack_a;
	while (current->next)
	{	
		previous = current;
		current = current->next;
	}
	previous->next = NULL;
	current->next = (*stack_a);
	*stack_a = current;
	if (flag == 1)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_list **stack_b, int flag)
{
	t_list	*current;
	t_list	*previous;

	current = *stack_b;
	while (current->next)
	{
		previous = current;
		current = current->next;
	}
	previous->next = NULL;
	current->next = (*stack_b);
	*stack_b = current;
	if (flag == 1)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_list **stack_a, t_list **stack_b, int flag)
{
	ft_rra(stack_a, 0);
	ft_rrb(stack_b, 0);
	if (flag == 1)
		write(1, "rrr\n", 4);
}
