# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/07 20:00:45 by pholster       #+#    #+#                 #
#    Updated: 2019/04/30 18:31:45 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

COLOR_DEFUALT = $(shell echo '\e[39m')
COLOR_BLACK = $(shell echo '\e[38;5;0m')
COLOR_RED = $(shell echo '\e[38;5;1m')
COLOR_GREEN = $(shell echo '\e[38;5;2m')
COLOR_YELLOW = $(shell echo '\e[38;5;3m')
COLOR_BLUE = $(shell echo '\e[38;5;4m')
COLOR_MAGENTA = $(shell echo '\e[38;5;5m')
COLOR_CYAN = $(shell echo '\e[38;5;6m')
COLOR_WHITE = $(shell echo '\e[38;5;7m')
COLOR_BRIGHT_BLACK = $(shell echo '\e[38;5;8m')
COLOR_BRIGHT_RED = $(shell echo '\e[38;5;9m')
COLOR_BRIGHT_GREEN = $(shell echo '\e[38;5;10m')
COLOR_BRIGHT_YELLOW = $(shell echo '\e[38;5;11m')
COLOR_BRIGHT_BLUE = $(shell echo '\e[38;5;12m')
COLOR_BRIGHT_MAGENTA = $(shell echo '\e[38;5;13m')
COLOR_BRIGHT_CYAN = $(shell echo '\e[38;5;14m')
COLOR_BRIGHT_WHITE = $(shell echo '\e[38;5;15m')
PRINT_MIN = $(shell printf '$(COLOR_RED)[ - ]$(COLOR_DEFUALT)')
PRINT_PLUS = $(shell printf '$(COLOR_GREEN)[ + ]$(COLOR_DEFUALT)')

LIBFTPATH = ./libft
LIBFT = $(LIBFTPATH)/libft.a

INCLUDES = $(LIBFTPATH)/includes/
NAME = fractol

SRCS = getfractols addfractol
SRCS := $(NAME).c $(SRCS:%=ft_%.c)

SRCS := $(sort $(SRCS))
OBJS = $(srcs:.c=.o)

CCFLAGS = -Wall -Werror -Wextra -I$(INCLUDES)

all: $(NAME)

$(NAME): $(LIBFT) $(SRCS) $(NAME).h
	@printf '$(PRINT_PLUS) compiling $(NAME)\n'
	@gcc $(CCFLAGS) -o $(NAME) $(SRCS) $(LIBFT)

$(LIBFT): FORCE
	@$(MAKE) -s -C $(LIBFTPATH)

clean:
	@printf '$(PRINT_MIN) cleaning $(NAME)\n'
	@rm -f $(SRCS:.c=.c~)
	@$(MAKE) -s -C $(LIBFTPATH) clean

fclean: clean
	@printf '$(PRINT_MIN) fcleaning $(NAME)\n'
	@rm -f $(NAME)
	@$(MAKE) -s -C $(LIBFTPATH) fclean

re: fclean $(NAME)

FORCE: ;