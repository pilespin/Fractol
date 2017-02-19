# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/23 14:06:14 by pilespin          #+#    #+#              #
#    Updated: 2015/10/16 14:19:59 by pilespin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean all

NAME	=	fractol

SDIR	=	src/
HDIR	=	includes/
ODIR	=	object/
FOLDER	=	-I $(HDIR) -I ./minilibx_macos/

SRCA	=	project.c \
			draw.c \
			draw_img.c \
			key_hook.c \

SRCH	=	project.h \
			struct.h \

SRCO	=	$(SRCA:.c=.o)

CC		=	gcc
LIB		=	-L ./libft/ -lft -L ./minilibx_macos/ -lmlx
FLAGS	=	-Wall -Wextra -Werror
MLX 	= 	-lmlx -framework OpenGL -framework AppKit

SRC 	=	$(patsubst %.c, $(SDIR)%.c, $(SRCA))
HDR		=	$(patsubst %.h, $(HDIR)%.h, $(SRCH))
OBJ		=	$(patsubst %.c, $(ODIR)%.o, $(SRCA))

all: $(NAME)

$(NAME): $(OBJ) $(SRC)
	@echo "\033[32m compiling minilibX >>> \033[0m" ; make -C ./minilibx_macos
	@echo "\033[32m compiling libft >>> \c \033[0m" ; make -C ./libft
	@$(CC) -o $(NAME) $(OBJ) $(LIB) $(MLX)
	@echo "\033[37m END $(NAME)\033[0m"

$(ODIR)%.o: $(SDIR)%.c $(HDR)
	@mkdir -p $(ODIR)
	@$(CC) -c $< -o $@ $(FLAGS) $(FOLDER) 
	@echo "\033[32m ok \033[33m $@\033[0m"

clean:
	@make -C ./libft clean
	@make -C ./minilibx_macos clean
	@rm -rf $(ODIR)

fclean: clean
	@make -C ./libft fclean
	@rm -f $(NAME)

re: fclean all
