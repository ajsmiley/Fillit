# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dromansk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/26 18:19:14 by dromansk          #+#    #+#              #
#    Updated: 2018/12/11 16:45:29 by dromansk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = ./srcs/*.c

O = *.o

INCLUDES = -I ./libft/includes -I ./includes

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/
	gcc -Wall -Werror -Wextra $(INCLUDES) $(SRCS) -c
	gcc -Wall -Werror -Wextra -o $(NAME) $(O) -L libft/ -lft
	rm -rf libft/*.o libft/*.a
	
clean:
	rm -rf $(O)

fclean: clean
	rm -rf $(NAME)

re: fclean all

reclean: fclean all
	rm -rf $(O)
