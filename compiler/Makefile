#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ollevche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/23 17:49:31 by ollevche          #+#    #+#              #
#    Updated: 2018/04/23 17:49:32 by ollevche         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	asm

FLAGS	=	-Wall -Werror -Wextra -I./headers -I$(LIBDIR)/headers -g # DEL

SRCDIR	=	sources/

OBJDIR	=	objects/

LIBDIR	=	../libft/

SRC		=	main.c compile.c read_sfile.c syntactically_valid.c \
			struct_funcs.c util.c

OBJ		=	$(addprefix $(OBJDIR), $(SRC:.c=.o))

LIB		=	libftprintf.a

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ) $(LIBDIR)$(LIB)
	@echo "creating $(NAME) binary"
	@cp $(LIBDIR)$(LIB) ./
	@gcc -o $(NAME) $(OBJ) $(LIB) $(FLAGS)

$(OBJ): $(OBJDIR)%.o : $(SRCDIR)%.c
	@echo "creating $(NAME) object files"
	@gcc -o $@ -c $< $(FLAGS)

$(LIBDIR)$(LIB):
	@make -C $(LIBDIR)

$(OBJDIR):
	@mkdir $(OBJDIR)

clean:
	@make -C $(LIBDIR) clean
	@echo "removing $(NAME) object files"
	@rm -rf $(OBJ) $(OBJDIR)

fclean:
	@make -C $(LIBDIR) fclean
	@echo "removing $(NAME) object files"
	@rm -rf $(OBJ) $(OBJDIR)
	@echo "removing $(NAME) binary"
	@rm -rf $(NAME) $(LIB)

re: fclean $(NAME)
	