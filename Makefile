# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/07 13:01:35 by mtaylor           #+#    #+#              #
#    Updated: 2019/03/14 16:51:04 by mtaylor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl
FLAGS = -Wall -Wextra -Werror -g

LIB = -I libft/ ./libft/libft.a
INC = -I ./inc

MISC = error.c \
		endian.c \
		env_struct.c

SSL_SH = main.c \
		commands.c \
		flags.c \
		print_bitfield.c

HASH = block.c \
		md5.c \
		sha1.c \
		sha256_sha224.c \
		sha512_sha384.c

DES = des_inner.c \
		modes_of_operation.c \
		pbkdf.c \
		key_schedule.c \
		des_util.c

BASE64 = base64.c

FILES = $(addprefix miscellaneous/, $(MISC)) \
		$(addprefix ssl_shell/, $(SSL_SH)) \
		$(addprefix hashing/, $(HASH)) \
		$(addprefix des/, $(DES)) \
		$(addprefix base64/, $(BASE64))

SRC = $(addprefix ./src/, $(FILES))

# **************************************************************************** #

GOLD = \033[38;5;214m
GREEN = \033[38;5;70m
UNDERLINE = \033[38;5;70;4m
WHITE = \033[0m

# **************************************************************************** #

all: $(NAME)

$(NAME): $(OFILES)
	@echo "$(GOLD)make libft$(WHITE)"
	@make -s -C ./libft
	@echo "$(GREEN)make $(NAME) [flags: $(UNDERLINE)-Wall -Wextra]$(WHITE)"
	@gcc -Wall -Wextra $(LIB) $(INC) $(SRC) -o $(NAME)

debug:
	@echo "$(GOLD)make libft$(WHITE)"
	@make -s -C ./libft
	@echo "$(GREEN)make $(NAME) [flags: $(UNDERLINE)$(FLAGS)]$(WHITE)"
	@gcc $(FLAGS) $(LIB) $(INC) $(SRC) -o $(NAME)

fsan:
	@echo "$(GOLD)make libft$(WHITE)"
	@make -s -C ./libft
	@echo "$(GREEN)make $(NAME) [flags: $(UNDERLINE)$(FLAGS) -fsanitize=address]$(WHITE)"
	@gcc $(FLAGS) -fsanitize=address $(LIB) $(INC) $(SRC) -o $(NAME)

clean:
	@echo "$(GOLD)clean libft$(WHITE)"
	@make -s -C ./libft clean

fclean: clean
	@echo "$(GOLD)fclean libft$(WHITE)"
	@make -s -C ./libft fclean
	@echo "$(GREEN)rm $(NAME) $(NAME).dSYM$(WHITE)"
	@rm -rf $(NAME) $(addsuffix .dSYM, $(NAME))

re: fclean all
