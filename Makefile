# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfaria-d <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 10:49:47 by pfaria-d          #+#    #+#              #
#    Updated: 2022/12/19 15:44:54 by pfaria-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = fract-ol.c extra/ft_atoi.c

OBJS = $(SRC:.c=.o)

GCC = gcc -Wall -Werror -Wextra

RM  = rm -f

HFILE = fractol.h

NAME = fract-ol

all: $(NAME) 

.c.o :
	$(GCC) -Imlx -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus:
			@make MAKEBONUS=1 all

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) fract-ol

re:			fclean $(NAME) 
			
.PHONY: all clean fclean re bonus

