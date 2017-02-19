# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/09 11:34:04 by pilespin          #+#    #+#              #
#    Updated: 2015/10/26 16:28:57 by pilespin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean all

NAME = libft.a
TITLE = libft

SRCA = ft_strlen.c \
	ft_strlen_char.c \
	ft_intlen.c ft_tablen.c \
	ft_strdup.c ft_strndup.c ft_strdupf.c ft_strrev.c \
	ft_strcpy.c ft_strncpy.c \
	ft_strcat.c	ft_strncat.c \
	ft_strchr.c ft_strrchr.c \
	ft_strstr.c ft_strnstr.c \
	ft_strcmp.c ft_strncmp.c \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_toupper.c ft_tolower.c \
	ft_memalloc.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c \
	ft_memcmp.c \
	ft_strlcat.c \
	ft_memdel.c \
	ft_strclr.c \
	ft_strequ.c \
	ft_strnequ.c \
	ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
	ft_dprintf.c ft_printf.c \
	ft_putnchar.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_puttab.c ft_puttab3.c ft_puttabint.c ft_tabdup.c \
	ft_itoa.c ft_itoabig.c ft_itoaf.c ft_atoi.c ft_atoibig.c ft_atof.c \
	ft_strnew.c ft_strdel.c \
	ft_strsub.c \
	ft_strjoin.c ft_strjoinf.c ft_strjoin_max.c \
	ft_strtrim.c \
	ft_strsplit.c ft_strsplit_start.c ft_implode.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_sorttab.c ft_swapchar.c \
	ft_get_next_line.c \
	ft_freetabchar.c \
	ft_make_tabchar.c \
	ft_pow.c ft_sqrt.c ft_absint.c \
	ft_utime.c \
	ft_random.c \
	ft_putstrc.c ft_putcharc.c \
	ft_strdup_add_space.c ft_strdup_whitout_space.c \

SRCO = $(SRCA:.c=.o)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@gcc -g $(FLAGS) -c $(SRCA)
	@ar rc $(NAME) $(SRCO)
	@ranlib $(NAME)

clean:
	@rm -f $(SRCO)

fclean: clean
	@rm -f $(NAME)

re: fclean all
