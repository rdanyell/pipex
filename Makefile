# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 12:33:05 by rdanyell          #+#    #+#              #
#    Updated: 2022/02/21 16:30:04 by rdanyell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PS		= push_swap

NAME_PSB	= checker

LIB_DIR		= libft/

LIBFT		= $(LIB_DIR)/libft.a

INCLUDES_PS	= includes/

HEADER_PS	= includes/push_swap.h

HEADER_PSB	= includes/push_swap_bonus.h

DIR_PS		= srcs/

DIR_PSB		= bonus/

FILES_PS	= main.c create_list.c atoi_ps.c ft_parse.c actions.c actions2.c \
			actions3.c actions4.c solve.c sort.c scores.c scripts.c		

FILES_PSB	= checker_bonus.c create_list_bonus.c atoi_ps_bonus.c ft_parse_bonus.c \
			actions_bonus.c actions2_bonus.c actions3_bonus.c actions4_bonus.c \
			solve_bonus.c sort_bonus.c scripts_bonus.c scores_bonus.c

SRCS_PS		= $(addprefix $(DIR_PS), $(FILES_PS))

SRCS_PSB	= $(addprefix $(DIR_PSB), $(FILES_PSB))

OBJS_PS		= $(SRCS_PS:%.c=%.o)

OBJS_PSB	= $(SRCS_PSB:%.c=%.o)

CC 			= cc

CFLAGS		= -Wall -Wextra -Werror

.PHONY: 	all libft clean fclean re bonus

all:		libft $(NAME_PS)

libft:
			make -C $(LIB_DIR)

bonus:
			@make NAME_PS="$(NAME_PSB)" \
			OBJS_PS="$(OBJS_PSB)" \
			HEADER_PS="$(HEADER_PSB)" all

$(NAME_PS):	$(OBJS_PS)
			$(CC) $(CFLAGS) $(OBJS_PS) $(LIBFT) -o $@

%.o:		%.c $(LIBFT) $(HEADER_PS) 
			$(CC) $(CFLAGS) -I $(INCLUDES_PS) -c $< -o $@

clean	:
			$(RM) $(OBJS_PS) $(OBJS_PSB)
			make -C $(LIB_DIR) clean
				
fclean	:	clean
			rm -r $(NAME_PS) $(NAME_PSB)
			make -C $(LIB_DIR) fclean

re		:	fclean all
	
