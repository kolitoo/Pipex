# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 14:56:11 by abourdon          #+#    #+#              #
#    Updated: 2023/03/01 11:26:09 by abourdon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -rf
SRC =		ft_memcpy.c \
	ft_isalpha.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strrchr.c \
	ft_atoi.c \
	ft_isascii.c \
	ft_memchr.c \
	ft_memset.c \
	ft_strlen.c \
	ft_tolower.c \
	ft_bzero.c \
	ft_isdigit.c \
	ft_memcmp.c \
	ft_strchr.c \
	ft_strncmp.c \
	ft_toupper.c \
	ft_isalnum.c \
	ft_isprint.c \
	ft_memcpy.c \
	ft_strlcat.c \
	ft_strnstr.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_itoa.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_split.c \
	ft_putnbr_fd.c \
	ft_strmapi.c \
	ft_striteri.c \
	printf/ft_printf.c \
	printf/ft_putchar.c \
	printf/ft_putnb_base.c \
	printf/ft_putnbr_unsi.c \
	printf/ft_putnbr.c \
	printf/ft_putstr.c \
	printf/ft_putvoid.c \
	get_next_line/get_next_line_utils.c \
	get_next_line/get_next_line.c \

OBJ = $(SRC:.c=.o)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@ 
	
$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)

all: $(NAME)

bonus: $(OBJ) $(BONUSOBJ)
	@$(AR) $(NAME) $(OBJ)

clean:
	@$(RM) $(OBJ)
fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: bonus all clean fclean re