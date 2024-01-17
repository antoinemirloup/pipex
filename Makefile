# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 16:49:50 by amirloup          #+#    #+#              #
#    Updated: 2024/01/17 17:12:28 by amirloup         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = @cc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
SRCS = pipex.c

INCLUDE = pipex.h

OBJS =	$(SRCS:.c=.o)

RM = @rm -rf

RED = \e[1;91m
GREEN = \e[1;92m
YELLOW = \e[1;93m
		
all:	$(NAME)
	@echo "$(RED)o---------------o"
	@echo "$(RED)| $(GREEN)   ./pipex    $(RED)|"
	@echo "$(RED)o---------------o"

$(NAME):	$(OBJS)
	@make --no-print-directory -C libft
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)

clean :
	$(RM) $(OBJS)
	@make --no-print-directory -C libft clean
		
fclean:
	$(RM) $(OBJS)
	$(RM) $(NAME)
	@make --no-print-directory -C libft fclean
				
re:		fclean all

ex:		re clean