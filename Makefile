# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 12:30:38 by abourdon          #+#    #+#              #
#    Updated: 2023/03/01 17:30:13 by abourdon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
BONUSNAME = pipex_bonus
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT_PATH = ./libft/
LIBFT = libft/libft.a
RM = rm -rf

YELLOW=\033[0;33m
BLUE=\033[0;34m
BOLD=\033[1m
RESET=\033[0m

SRC = mandatory/pipex.c \
      mandatory/path.c \
      mandatory/free.c \
      mandatory/child.c \
      mandatory/error.c \

SRCBONUS = bonus/pipex_bonus.c \
           bonus/path_bonus.c \
           bonus/child_bonus.c \
           bonus/free_bonus.c \
           bonus/error_bonus.c \

OBJ = $(SRC:.c=.o)

BONUSOBJ = $(SRCBONUS:.c=.o)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME): $(OBJ) $(LIBFT) include/pipex.h
	@echo "$(BLUE)$(BOLD)Compiling $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$(YELLOW)$(BOLD)$(NAME) compiled!$(RESET)"

$(BONUSNAME): $(BONUSOBJ) $(LIBFT) include/pipex_bonus.h
	@echo "$(BLUE)$(BOLD)Compiling $(BONUSNAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(BONUSOBJ) $(LIBFT) -o $(BONUSNAME)
	@echo "$(YELLOW)$(BOLD)$(BONUSNAME) compiled!$(RESET)"

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(CLEANLIBFT):
	@make clean -C $(LIBFT_PATH)
	
all: $(NAME)

clean:
	@echo "$(BLUE)$(BOLD)Cleaning object files...$(RESET)"
	@$(RM) $(OBJ) $(BONUSOBJ)
	@$(CLEANLIBFT)

fclean: clean
	@echo "$(BLUE)$(BOLD)Cleaning $(NAME) and $(BONUSNAME)...$(RESET)"
	@$(RM) $(NAME) $(BONUSNAME)

bonus: $(BONUSNAME)

re: fclean all

.PHONY: init all clean fclean re