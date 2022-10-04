# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 12:33:05 by rdanyell          #+#    #+#              #
#    Updated: 2022/03/22 12:18:16 by rdanyell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_P		= pipex

NAME_PB	= pipex

INCLUDES_P	= includes/

HEADER_P	= includes/pipex.h

HEADER_PB	= includes/pipex_bonus.h

DIR_P		= srcs/

DIR_UTILS	= utils/

DIR_UTILSB	= utils_bonus/

DIR_PB		= bonus/

FILES_P		= main.c children.c free.c

FILES_UTILS	= ft_split.c ft_strlen.c ft_strncmp.c ft_strrchr.c ft_substr.c ft_strjoin.c \
				ft_printf.c ft_printf_utils.c get_next_line.c get_next_line_utils.c \
				ft_strlcpy.c ft_strdup.c

FILES_PB	= main_bonus.c error_bonus.c parse_bonus.c free_bonus.c file_bonus.c

SRCS_P		= $(addprefix $(DIR_P), $(FILES_P)) $(addprefix $(DIR_UTILS), $(FILES_UTILS))

SRCS_PB	= $(addprefix $(DIR_PB), $(FILES_PB)) $(addprefix $(DIR_UTILSB), $(FILES_UTILS))

OBJS_P		= $(SRCS_P:%.c=%.o)  

OBJS_PB	= $(SRCS_PB:%.c=%.o)

CC 			= cc

CFLAGS		= -Wall -Wextra -Werror

.PHONY: 	all clean fclean re bonus

all:		$(NAME_P)

bonus:
			@make NAME_P="$(NAME_PB)" \
			OBJS_P="$(OBJS_PB)" \
			HEADER_P="$(HEADER_PB)" all

$(NAME_P):	$(OBJS_P)
			$(CC) $(OBJS_P) -o $@

%.o:		%.c $(HEADER_P) Makefile
			$(CC) $(CFLAGS) -I $(INCLUDES_P) -c $< -o $@

clean	:
			$(RM) $(OBJS_P) $(OBJS_PB)
							
fclean	:	clean
			rm -r $(NAME_P) 
			
re		:	fclean all
	
