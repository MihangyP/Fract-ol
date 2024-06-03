#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 10:52:04 by pmihangy          #+#    #+#              #
#    Updated: 2024/06/01 17:33:42 by pmihangy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#ARGS

NAME = fractol
NAME_BONUS = fractol_bonus
SRCS = main.c errors.c errors_2.c  init.c generate_fractol.c operations.c events.c atod.c
SRCS_BONUS = main_bonus.c errors_bonus.c errors_2_bonus.c init_bonus.c generate_fractol_bonus.c \
			 operations_bonus.c events_bonus.c atod_bonus.c
SRCS_FILES = $(addprefix srcs/madatory/, $(SRCS))
SRCS_BONUS_FILES = $(addprefix srcs/bonus/, $(SRCS_BONUS))
MLX_PATH = ./includes/minilibx
FT_PRINTF_PATH = ./includes/ft_printf
CC = cc
CFLAGS = -Wall -Wextra -Werror -lm
MAKE_LIB = make -C
MLX_ARCHIVES = -lmlx_Linux -lX11 -lXext

#RULES

all : $(NAME)

$(NAME) : $(SCRS_FILES)
	@echo "\033[0;35m\033[1mGENERATE MLX_LIB\033[0m"
	$(MAKE_LIB) $(MLX_PATH)
	@echo "\033[0;35m\033[1mEND OF MLX_LIB GENERATION\033[0m"
	@echo "\033[0;33mGENERATE FT_PRINTF_LIB\033[0m"
	$(MAKE_LIB) $(FT_PRINTF_PATH)
	@echo "\033[0;33mEND OF FT_PRINTF_LIB GENERATION\033[0m"
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS_FILES) -Lincludes/ft_printf -lftprintf -Lincludes/minilibx $(MLX_ARCHIVES)
	@echo "\033[0;32mCOMPILATION SUCCESS :)\033[0m"

bonus : $(NAME_BONUS) 

$(NAME_BONUS) : $(SRCS_BONUS_FILES)
	@echo "\033[0;35m\033[1mGENERATE MLX_LIB\033[0m"
	$(MAKE_LIB) $(MLX_PATH)
	@echo "\033[0;35m\033[1mEND OF MLX_LIB GENERATION\033[0m"
	@echo "\033[0;33mGENERATE FT_PRINTF_LIB\033[0m"
	$(MAKE_LIB) $(FT_PRINTF_PATH)
	@echo "\033[0;33mEND OF FT_PRINTF_LIB GENERATION\033[0m"
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(SRCS_BONUS_FILES) -Lincludes/ft_printf -lftprintf -Lincludes/minilibx $(MLX_ARCHIVES)
	@echo "\033[0;32mCOMPILATION SUCCESS :)\033[0m"

clean :
	@echo "\033[0;34mDELETE OBJECTS FILES\033[0m"
	$(MAKE_LIB) $(MLX_PATH) clean
	$(MAKE_LIB) $(FT_PRINTF_PATH) clean
	@echo "\033[0;34mEND OF OBJECTS FILES DELETION\033[0m"

fclean : clean
	@echo "\033[0;36mDELETE ARCHIVES FILES\033[0m"
	$(MAKE_LIB) $(FT_PRINTF_PATH) fclean
	rm -rf $(MLX_PATH)/*.a
	rm -rf $(NAME)
	rm -rf $(NAME)_bonus
	@echo "\033[0;36mEND OF ARCHIVES FILES DELETION\033[0m"

re : fclean all

.PHONY: all bonus clean fclean re 
