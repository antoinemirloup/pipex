# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 16:49:50 by amirloup          #+#    #+#              #
#    Updated: 2024/01/15 16:51:38 by amirloup         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 
CC = @cc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
SRCS = 

INCLUDE = 

OBJS =	$(SRCS:.c=.o)

RM = @rm -rf

RED = \e[1;91m
GREEN = \e[1;92m
YELLOW = \e[1;93m

all:	$(NAME) 
	@echo "$(RED)|---------------|$(RESET)"
	@echo "$(RED)|$(RESET) $(GREEN)  $(RESET) $(RED)| $(RESET)"
	@echo "$(RED)|---------------|$(RESET)"


$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
		$(RM) $(OBJS) $(OBJS_BONUS)
		
fclean:
		$(RM) $(OBJS)
		$(RM) $(NAME)
				
re:		fclean all

ex:		re clean

.PHONY:	all clean fclean re ex% 