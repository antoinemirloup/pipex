# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 09:38:40 by amirloup          #+#    #+#              #
#    Updated: 2024/02/01 10:21:23 by amirloup         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a

SRCS = 	ft_isalpha.c ft_isdigit.c ft_isalnum.c\
		ft_isascii.c ft_isprint.c ft_strlen.c\
		ft_memset.c ft_bzero.c ft_memcpy.c\
		ft_memmove.c ft_strlcpy.c ft_strlcat.c\
		ft_toupper.c ft_tolower.c ft_strchr.c\
		ft_strrchr.c ft_strncmp.c ft_memchr.c\
		ft_memcmp.c ft_strnstr.c ft_atoi.c\
		ft_calloc.c ft_strdup.c ft_substr.c\
		ft_strjoin.c ft_strtrim.c ft_split.c\
		ft_itoa.c ft_strmapi.c ft_striteri.c\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
		ft_putnbr_fd.c get_next_line.c
		
BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c\
		ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c\
		ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS =	${SRCS:.c=.o}

OBJS_B = ${BONUS:.c=.o}

CC =	@cc
CFLAGS = -Wall -Werror -Wextra
RM =	@rm -f

${NAME}:	${OBJS} ${OBJS_B}
		@ar rcs ${NAME} ${OBJS} ${OBJS_B}

all:	${NAME}
		
clean :
		${RM} ${OBJS} ${OBJS_B}
		
fclean: clean
		${RM} ${NAME}
		
re:		fclean ${NAME}			