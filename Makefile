# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrobin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/11 19:28:47 by jrobin            #+#    #+#              #
#    Updated: 2018/05/31 15:49:54 by jrobin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=	jrobin.filler

NAME_LIB= libft.a
PATH_LIB= libft/
LIB = $(PATH_LIB)$(NAME_LIB)

PATH_INC= includes/

CC=		gcc
FLAGS=	-Wall -Wextra -Werror

DIR_SRC:= sources/
DIR_OBJ:= objets/

SRC_BASE= filler.c \
		  piece.c \
		  parse_map.c \
		  place_piece.c

OBJS= $(addprefix $(DIR_OBJ), $(SRC_BASE:.c=.o))

all: $(LIB)
	@make -j $(NAME)

$(LIB):
	@make -C libft

$(NAME): $(LIB) $(DIR_OBJ) $(OBJS) Makefile
	@$(CC) $(FLAGS) $(OBJS) $(PATH_LIB)$(NAME_LIB) -o players/$(NAME)
	@echo "\033[32mjrobin.filler ok\033[0m"

DEBUG: 
	@echo $(OBJS)


$(DIR_OBJ):
		@mkdir -p $(DIR_OBJ)
		@mkdir -p $(dir $(OBJS))

$(DIR_OBJ)%.o: $(DIR_SRC)%.c Makefile
	@$(CC) $(FLAGS) -I $(PATH_INC) -I $(PATH_LIB)$(PATH_INC) -MMD -c $< -o $@  

clean:
	@make clean -C $(PATH_LIB)
	@rm -rf $(DIR_OBJ)

fclean: clean
	@rm -f $(LIB)
	@rm -f players/$(NAME)

re: fclean all

.PHONY :	clean fclean re DEBUG LIB
