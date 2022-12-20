# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfaria-d <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 10:49:47 by pfaria-d          #+#    #+#              #
#    Updated: 2022/12/20 12:25:08 by pfaria-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = sets/mandelbrot-set.c sets/mlxutils.c

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

