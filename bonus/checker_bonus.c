/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:52:02 by rdanyell          #+#    #+#             */
/*   Updated: 2022/02/21 16:37:10 by rdanyell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_error(void)
{
	write (1, "Error\n", 6);
	exit(1);
}

void	do_actions(char *line, t_list **stack_a, t_list **stack_b, t_info *info)
{
	if (ft_strncmp(line, "sa", 3) == 0)
		ft_sa(*stack_a, 0);
	else if (ft_strncmp(line, "sb", 3) == 0)
		ft_sb(*stack_b, 0);
	else if (ft_strncmp(line, "ss", 3) == 0)
		ft_ss(*stack_a, *stack_b, 0);
	else if (ft_strncmp(line, "pa", 3) == 0)
		ft_pa(stack_a, stack_b, info, 0);
	else if (ft_strncmp(line, "pb", 3) == 0)
		ft_pb(stack_a, stack_b, info, 0);
	else if (ft_strncmp(line, "ra", 3) == 0)
		ft_ra(stack_a, 0);
	else if (ft_strncmp(line, "rb", 3) == 0)
		ft_rb(stack_b, 0);
	else if (ft_strncmp(line, "rra", 4) == 0)
		ft_rra(stack_a, 0);
	else if (ft_strncmp(line, "rrb", 4) == 0)
		ft_rrb(stack_b, 0);
	else if (ft_strncmp(line, "rrr", 4) == 0)
		ft_rrr(stack_a, stack_b, 0);
	else if (ft_strncmp(line, "rr", 3) == 0)
		ft_rr(stack_a, stack_b, 0);
	else
		ft_error();
}

void	read_actions_checker(t_list **stack_a, t_list **stack_b, t_info *info)
{
	char	*line;

	line = NULL;
	while (get_next_line(&line))
	{
		do_actions(line, stack_a, stack_b, info);
		free(line);
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
}

t_list	*create_list_checker(int argc, char **argv, t_info *info)
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
	ft_check_dup(number, len);
	list = int_to_list(number, len);
	find_minmax(number, len, info);
	info->len_b = 0;
	free(number);
	return (list);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_info	info;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	stack_a = create_list_checker(argc, argv, &info);
	read_actions_checker(&stack_a, &stack_b, &info);
	if (ft_is_sort(stack_a, info.len_a) == 0 && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	clear_stack(stack_a);
	clear_stack(stack_b);
	return (0);
}
