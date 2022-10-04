/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:07:33 by rdanyell          #+#    #+#             */
/*   Updated: 2022/02/21 16:28:04 by rdanyell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_list
{
	int				num;
	int				elem_score;
	struct s_list	*next;
}	t_list;

typedef struct s_info
{
	int		min;
	int		max;
	int		med;
	int		len_a;
	int		len_b;	
	int		rb;
	int		ra;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		script1;
	int		script2;
	int		script3;
	int		script4;
	int		script_number;
	t_list	*best_elem;
}	t_info;

t_list	*create_list(int argc, char **argv, t_info *info);
t_list	*int_to_list(int *number, int len);
int		ft_atoi_ps(const char *str);
int		ft_is_sort(t_list *first, int len);
int		*ft_parse_onearg(char *argv);
int		count_args(char *argv);
int		*ft_parse_multiarg(char **argv, int argc);
void	ft_check_dup(int *number, int len);
void	ft_check_sorted(int	*number, int len);
void	find_minmax(int *number, int len, t_info *info);
void	fill_stack_a(t_list **stack_a, t_list **stack_b, t_info *info);
void	fill_stack_b(t_list **stack_a, t_list **stack_b, t_info *info);
void	do_script1(t_list **stack_a, t_list **stack_b, t_info *info);
void	do_script2(t_list **stack_a, t_list **stack_b, t_info *info);
void	do_script3(t_list **stack_a, t_list **stack_b, t_info *info);
void	do_script4(t_list **stack_a, t_list **stack_b, t_info *info);

void	select_element(t_list **stack_a, t_list **stack_b, t_info *info);
void	ft_count_score(t_list *stack_a, t_list *current, t_info *info,
			int size_b);
void	count_rotations_a(t_list *head_a, t_list *current, t_info *info);
void	count_double_rotations(t_info *info);
void	count_rotations(t_list *head_a, t_list *current, t_info *info,
			int size_b);
void	best_script(t_list *current, t_info *info);
void	solve(t_list **stack_a, t_list **stack_b, t_info *info);
int		ft_presort(t_list *stack, t_info *info);
void	sort(t_list **stack_a, t_list **stack_b, t_info *info);
void	sort_two(t_list **stack_a);
void	sort_three(t_list **stack_a, t_info *info);
void	sort_five(t_list **stack_a, t_list **stack_b, t_info *info);
void	final_sort(t_list **stack_a, t_info *info);
void	finish_sort(t_list **stack_a, t_info *info);
void	clear_stack(t_list *stack);

void	ft_sa(t_list *stack_a, int flag);
void	ft_sb(t_list *stack_b, int flag);
void	ft_ss(t_list *stack_a, t_list *stack_b, int flag);
void	ft_ra(t_list **stack_a, int flag);
void	ft_rb(t_list **stack_b, int flag);
void	ft_rr(t_list **stack_a, t_list **stack_b, int flag);
void	ft_rra(t_list **stack_a, int flag);
void	ft_rrb(t_list **stack_b, int flag);
void	ft_rrr(t_list **stack_a, t_list **stack_b, int flag);
void	ft_pa(t_list **stack_a, t_list **stack_b, t_info *info, int flag);
void	ft_pb(t_list **stack_a, t_list **stack_b, t_info *info, int flag);
void	add_top_stack(t_list **stack, int number);
void	del_top_stack(t_list **stack);
void	ft_error(void);

#endif