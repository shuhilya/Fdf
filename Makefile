# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/21 20:01:04 by amerlon-          #+#    #+#              #
#    Updated: 2019/06/11 15:37:23 by htorp            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAGS = -Wall -Werror -Wextra
SRCS = srcs/*.c
OBJS = *.o
INCLUDES = includes
LIBFT = libft.a

all: $(NAME)

$(OBJS):
	@gcc -c $(SRCS) $(FLAGS) -I$(INCLUDES) -I./minilibx_macos

$(NAME): $(OBJS)
	make -C minilibx_macos
	@gcc $(OBJS) -o $(NAME) $(LIBFT) -lmlx -framework OpenGL -framework AppKit

clean:
	@rm -f $(OBJS)
	make -C minilibx_macos clean

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re norm
