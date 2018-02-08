# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrobin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/11 19:28:47 by jrobin            #+#    #+#              #
#    Updated: 2018/02/08 20:20:24 by jrobin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= filler

NAME_LIB= libft.a
PATH_LIB= libft/

CC=		gcc
FLAGS=	-Wall -Wextra -Werror

DIR_SRC:= filler_src/
DIR_OBJ:= obj/

SRC_BASE=	filler.c \
			parse_map.c \
			piece.c

PATH_INC=	inc/
PATH_INC_LIB= libft/inc/


OBJS= $(addprefix $(DIR_OBJ), $(SRC_BASE:.c=.o))

all: $(DIR_OBJ) $(OBJS)
	make -C libft
	$(CC) $(FLAGS) $(OBJS) $(PATH_LIB)$(NAME_LIB) -o $(NAME)

DEBUG: 
	@echo $(PATH_INC)

$(DIR_OBJ):
		mkdir -p $(DIR_OBJ)
		mkdir -p $(dir $(OBJS))

$(DIR_OBJ)%.o: $(DIR_SRC)%.c
	@$(CC) $(FLAGS) -I $(PATH_INC) -I $(PATH_INC_LIB) -MMD -c $< -o $@

clean:
																				#	clean -C libft
	@rm -rf $(DIR_OBJ)

fclean: clean 
																				#	make fclean -C libft
	@rm -f $(NAME)

re: fclean all

.PHONY :	clean fclean re DEBUG
