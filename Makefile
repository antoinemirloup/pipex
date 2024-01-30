# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 16:49:50 by amirloup          #+#    #+#              #
#    Updated: 2024/01/30 14:07:46 by amirloup         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_BONUS = pipex_bonus
CC = @cc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
SRCS = pipex.c pipex_utils.c pipex_utils2.c
SRCS_BONUS = pipex_bonus.c pipex_utils_bonus.c pipex_utils_bonus2.c pipex_utils_bonus3.c

INCLUDE = pipex.h
INCLUDE_BONUS = pipex_bonus.h

OBJS =	$(SRCS:.c=.o)
OBJS_BONUS =	$(SRCS_BONUS:.c=.o)

RM = @rm -rf

RED = \e[1;91m
GREEN = \e[1;92m
YELLOW = \e[1;93m
		
all:	$(NAME)
	@echo "$(RED)o---------------o"
	@echo "$(RED)| $(GREEN)   ./pipex    $(RED)|"
	@echo "$(RED)o---------------o"

bonus:	$(NAME_BONUS)
	@echo "$(RED)o---------------o"
	@echo "$(RED)| $(YELLOW)    BONUS    $(RED) |"
	@echo "$(RED)| $(GREEN)   ./pipex    $(RED)|"
	@echo "$(RED)o---------------o"
	
$(NAME): $(OBJS)
	@make --no-print-directory -C libft
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	@make --no-print-directory -C libft
	$(CC) $(CFLAGS) $(OBJS_BONUS) libft/libft.a -o $(NAME_BONUS)

clean :
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)
	@make --no-print-directory -C libft clean
		
fclean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)
	@make --no-print-directory -C libft fclean
				
re:		fclean all

ex:		re clean