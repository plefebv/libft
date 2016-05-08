# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/21 10:45:45 by plefebvr          #+#    #+#              #
#    Updated: 2016/04/29 00:20:01 by plefebvr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC =	ft_isprint.c \
		ft_memalloc.c \
		ft_putchar.c \
		ft_square.c \
		ft_strequ.c \
		ft_strncat.c \
		ft_strstr.c \
		ft_itoa.c \
		ft_memccpy.c \
		ft_putchar_fd.c \
		ft_strcat.c \
		ft_striter.c \
		ft_strncmp.c \
		ft_strsub.c \
		ft_atoi.c \
		ft_lstadd.c \
		ft_memchr.c \
		ft_putendl.c \
		ft_strchr.c \
		ft_striteri.c \
		ft_strncpy.c \
		ft_strtrim.c \
		ft_bzero.c \
		ft_lstdel.c \
		ft_memcmp.c \
		ft_putendl_fd.c \
		ft_strclr.c \
		ft_strjoin.c \
		ft_strnequ.c \
		ft_tolower.c \
		ft_isalnum.c \
		ft_lstdelone.c \
		ft_memcpy.c \
		ft_putnbr.c \
		ft_strcmp.c \
		ft_strlcat.c \
		ft_strnew.c \
		ft_toupper.c \
		ft_isalpha.c \
		ft_lstiter.c \
		ft_memdel.c \
		ft_putnbr_fd.c \
		ft_strcpy.c \
		ft_strlen.c \
		ft_strnstr.c \
		ft_wordcount.c \
		ft_isascii.c \
		ft_lstmap.c \
		ft_memmove.c \
		ft_putstr.c \
		ft_strdel.c \
		ft_strmap.c \
		ft_strrchr.c \
		ft_isdigit.c \
		ft_lstnew.c \
		ft_memset.c \
		ft_putstr_fd.c \
		ft_strdup.c \
		ft_strmapi.c \
		ft_strsplit.c \
		ft_nbrendl.c \
		ft_strndup.c \
		ft_checkchar.c
OBJ =	$(SRC:.c=.o)
HEADER = includes/libft.h
FLAG = -Wall -Wextra -Werror
all: $(NAME)

$(NAME) :
	/usr/bin/gcc $(FLAG) -c $(SRC) -I $(HEADER)
	/usr/bin/ar rc libft.a $(OBJ)
	/usr/bin/ranlib libft.a

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)


re: fclean 
	make
