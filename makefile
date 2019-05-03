# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/07 20:00:45 by pholster       #+#    #+#                 #
#    Updated: 2019/05/03 15:12:22 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

COLOR_DEFUALT = $(shell printf "\e[39m")
COLOR_BLACK = $(shell printf "\e[38;5;0m")
COLOR_RED = $(shell printf "\e[38;5;1m")
COLOR_GREEN = $(shell printf "\e[38;5;2m")
COLOR_YELLOW = $(shell printf "\e[38;5;3m")
COLOR_BLUE = $(shell printf "\e[38;5;4m")
COLOR_MAGENTA = $(shell printf "\e[38;5;5m")
COLOR_CYAN = $(shell printf "\e[38;5;6m")
COLOR_WHITE = $(shell printf "\e[38;5;7m")
COLOR_BRIGHT_BLACK = $(shell printf "\e[38;5;8m")
COLOR_BRIGHT_RED = $(shell printf "\e[38;5;9m")
COLOR_BRIGHT_GREEN = $(shell printf "\e[38;5;10m")
COLOR_BRIGHT_YELLOW = $(shell printf "\e[38;5;11m")
COLOR_BRIGHT_BLUE = $(shell printf "\e[38;5;12m")
COLOR_BRIGHT_MAGENTA = $(shell printf "\e[38;5;13m")
COLOR_BRIGHT_CYAN = $(shell printf "\e[38;5;14m")
COLOR_BRIGHT_WHITE = $(shell printf "\e[38;5;15m")
PRINT_MIN = $(shell printf '$(COLOR_RED)[ - ]$(COLOR_DEFUALT)')
PRINT_PLUS = $(shell printf '$(COLOR_GREEN)[ + ]$(COLOR_DEFUALT)')

LIBFTPATH = ./libft
LIBFT = $(LIBFTPATH)/libft.a

MINILIBPATH = ./minilibx_macos
MINILIB = $(MINILIBPATH)/libmlx.a

INCLUDES = $(LIBFTPATH)/includes/
NAME = fractol

SRCS = getfractols addfractol ftldel ftlnew
SRCS := $(NAME).c $(SRCS:%=ft_%.c)

SRCS := $(sort $(SRCS))
OBJS = $(srcs:.c=.o)

CCFLAGS = -Wall -Werror -Wextra -I$(INCLUDES)

# This checks if your on linux and then compiles with pthread
ifeq ($(shell uname -s), Linux)
CCFLAGS += -pthread
endif

all: $(NAME)

$(NAME): $(MINILIB) $(LIBFT) $(SRCS) $(NAME).h
	@printf '$(PRINT_PLUS) compiling $(NAME)\n'
	@gcc $(CCFLAGS) -o $(NAME) $(SRCS) $(LIBFT) $(MINILIB) \
		-framework OpenGL -framework AppKit

$(LIBFT): FORCE
	@$(MAKE) -s -C $(LIBFTPATH)

$(MINILIB): FORCE
	@$(MAKE) -s -C $(MINILIBPATH)

clean:
	@printf '$(PRINT_MIN) cleaning $(NAME)\n'
	@rm -f $(SRCS:.c=.c~)
	@$(MAKE) -s -C $(LIBFTPATH) clean
	@$(MAKE) -s -C $(MINILIBPATH) clean

fclean: clean
	@printf '$(PRINT_MIN) fcleaning $(NAME)\n'
	@rm -f $(NAME)
	@$(MAKE) -s -C $(LIBFTPATH) fclean
	@$(MAKE) -s -C $(MINILIBPATH) fclean

re: fclean $(NAME)

FORCE: ;