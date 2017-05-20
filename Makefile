# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avanhoeg <avanhoeg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/19 19:12:36 by avanhoeg          #+#    #+#              #
#    Updated: 2015/03/21 21:45:43 by avanhoeg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	main.c get_next_line.c exec_cmd_fork.c tools.c env.c cd.c \
		error.c chdir.c final_setenv.c tab_to_sp.c
OBJ =	$(SRC:.c=.o)
FLG =	-Wall -Werror -Wextra
NAME =	ft_minishell1

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc $(FLG) -o $(NAME) $(OBJ) libft/libft.a -I libft -I .

$(OBJ):		$(SRC)
		@make -C ./libft/
		gcc $(FLG) -c $(SRC) -I libft -I .

clean:
		@make clean -C libft/
		rm -f $(OBJ)

fclean: clean
		@make fclean -C libft/
		rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re
