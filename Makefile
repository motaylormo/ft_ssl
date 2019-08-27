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

MISC = endian.c \
		error.c \
		env_struct.c

SSL_SH = main.c \
		commands.c \
		flags.c

HASH = block.c \
		print_checksum.c \
			algorithms/md5.c \
			algorithms/sha1.c \
			algorithms/sha256_sha224.c \
			algorithms/sha512_sha384.c

ENCRYPT = modes_of_operation.c \
			des/cipher.c \
			des/key_schedule.c \
			des/en_de_crypt.c \
			pbkdf/pbkdf.c \
			pbkdf/salt.c \
			util/bitfield_util.c \
			util/read_write.c \

B64 = base64.c \
		read.c \
		write.c

FILES = $(addprefix miscellaneous/, $(MISC)) \
		$(addprefix ssl_shell/, $(SSL_SH)) \
		$(addprefix hash/, $(HASH)) \
		$(addprefix encrypt/, $(ENCRYPT)) \
		$(addprefix base64/, $(B64))

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
