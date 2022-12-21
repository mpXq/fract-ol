# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfaria-d <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 10:49:47 by pfaria-d          #+#    #+#              #
#    Updated: 2022/12/21 09:59:53 by pfaria-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = fract-ol.c sets/mandelbrot-set.c sets/mlxutils.c utils/ft_printf.c utils/ft_printf_nbrb.c utils/ft_printf_utils1.c utils/ft_strncmp.c utils/ft_atoi.c sets/julia-set.c sets/hooks.c

OBJS = $(SRC:.c=.o)

GCC = gcc -Wall -Werror -Wextra

RM  = rm -f

HFILE = fractol.h

NAME = fract-ol

all: $(NAME) 

.c.o :
	$(GCC) -Imlx -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus:
			@make MAKEBONUS=1 all

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) fract-ol

re:			fclean $(NAME) 
			
.PHONY: all clean fclean re bonus

