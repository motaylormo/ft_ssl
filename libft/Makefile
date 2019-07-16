# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/23 19:57:40 by mtaylor           #+#    #+#              #
#    Updated: 2019/04/15 12:30:41 by mtaylor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes/

NUM_TYPE = ft_atoi.c ft_atoibase.c \
		   ft_itoa.c ft_itoabase.c \
		   ft_dtoa.c \
		   ft_atolbase.c \
		   ft_intmaxlen.c

PUT_PRINT = ft_putchar.c ft_putchar_fd.c \
			ft_putnbr.c	ft_putnbr_fd.c \
			ft_putstr.c	ft_putstr_fd.c \
			ft_putendl.c ft_putendl_fd.c

ASCII_ISTYPE = ft_isalpha.c \
			   ft_isdigit.c \
			   ft_isalnum.c \
			   ft_isascii.c \
			   ft_isprint.c \
			   ft_iswhitespace.c

MEMORY = ft_memalloc.c \
		 ft_memdel.c \
		 ft_memset.c ft_bzero.c \
		 ft_memdup.c \
		 ft_memcpy.c ft_memccpy.c \
		 ft_memchr.c \
		 ft_memmove.c \
		 ft_memcmp.c

STR_EDIT = ft_strtrim.c \
		   ft_strsub.c \
		   ft_strdup.c \
		   ft_strcpy.c ft_strncpy.c \
		   ft_strcat.c ft_strncat.c ft_strlcat.c \
		   ft_strjoin.c \
		   ft_strnew.c \
		   ft_strdel.c \
		   ft_strclr.c \
		   ft_tolower.c ft_toupper.c \
		   ft_striter.c ft_striteri.c \
		   ft_strmap.c ft_strmapi.c \
		   ft_cpycat_path.c

STR_INFO = ft_strlen.c \
		   ft_strcmp.c ft_strncmp.c \
		   ft_strequ.c ft_strnequ.c \
		   ft_strstr.c ft_strnstr.c \
		   ft_strchr.c ft_strrchr.c ft_strchrindex.c

MATRIX = ft_str_in_arr.c \
		 ft_matrixdel.c \
		 ft_matrixlen.c \
		 ft_matrixdup.c \
		 ft_strsplit.c \
		 ft_str_to_argv.c

OTHER = ft_getopt.c

GETNEXTLINE = get_next_line.c

FT_PRINTF = ft_printf.c \
			fwplt.c padding.c \
			print_string.c print_char.c \
			print_integer.c print_floating_point.c \
			print_address.c print_percent_sign.c

CFILES = $(addprefix ./num_type_conversions/, $(NUM_TYPE)) \
		 $(addprefix ./put_print/, $(PUT_PRINT)) \
		 $(addprefix ./ascii_istype/, $(ASCII_ISTYPE)) \
		 $(addprefix ./memory/, $(MEMORY)) \
		 $(addprefix ./str_edit/, $(STR_EDIT)) \
		 $(addprefix ./str_investigate/, $(STR_INFO)) \
		 $(addprefix ./matrix/, $(MATRIX)) \
		 $(addprefix ./other/, $(OTHER)) \
		 $(addprefix ./get_next_line/, $(GETNEXTLINE)) \
		 $(addprefix ./printf/, $(FT_PRINTF))

OFILES = $(NUM_TYPE:.c=.o) $(PUT_PRINT:.c=.o) $(ASCII_ISTYPE:.c=.o) \
		 $(MEMORY:.c=.o) $(STR_EDIT:.c=.o) $(STR_INFO:.c=.o) \
		 $(MATRIX:.c=.o) $(OTHER:.c=.o) \
		 $(GETNEXTLINE:.c=.o) $(FT_PRINTF:.c=.o)

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(CFILES) $(INCLUDES)
	ar rc $(NAME) $(OFILES)
	ranlib $(NAME)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
