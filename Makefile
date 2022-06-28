# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabdenna <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/27 22:53:14 by mabdenna          #+#    #+#              #
#    Updated: 2022/06/27 22:53:16 by mabdenna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = solong
CC = cc
SRC = main.c ft_split.c get_next_line_utils.c get_next_line.c ft_parsing.c ft_moves.c ft_move.c ft_heromove.c so_long_utils.c ft_parsing2.c error_hndler.c
FLAGS = -Wall -Wextra -Werror
FLA = -lmlx -framework OpenGL -framework AppKit -g
ARG = -o

all : $(NAME)

$(NAME): $(SRC)
	$(CC)  $(FLA) $(SRC) $(ARG) solong

clean : 
	rm -f $(NAME)

fclean : clean

re: fclean all
