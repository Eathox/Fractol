# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/07 20:00:45 by pholster       #+#    #+#                 #
#    Updated: 2019/05/01 15:01:35 by pholster      ########   odam.nl          #
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

INCLUDES = ../includes/
NAME = libftprintf.a

SRCS = getinfo infosetdefualt formatpad formatbackpad addchar iszeropad addstr \
	isunsignint issignint setvar_type setvar_base infonew format formatnum \
	formatunum overflowsigned overflowunsigned addnstr addtobuff addnum \
	formatchar formatcolor addwchar formatstr addwcharstr getprecision \
	getwidth getflag getlength gettype ispositiveint isstr formatdouble \
	distribute setrgbcolorbg setrgbcolor commands setcolorbg setcolor addunum

SRCS := $(sort ft_strformat.c ft_strformat_len.c ft_dprintf.c ft_printf.c \
	$(SRCS:%=pf_%.c))
OBJS = $(SRCS:.c=.o)

CCFLAGS = -Wall -Werror -Wextra -I$(INCLUDES)

all: $(NAME)

$(NAME): $(SRCS) $(INCLUDES)ft_printf.h
	@printf '$(PRINT_PLUS) compiling $(NAME)\n'
	@gcc $(CCFLAGS) -c $(SRCS)
	@printf '$(PRINT_PLUS) creating and indexing $(NAME)\n'
	@ar rcs $(NAME) $(OBJS)

clean:
ifneq ($(wildcard $(OBJS) $(SRCS:.c=.c~)),)
	@printf '$(PRINT_MIN) cleaning $(NAME)\n'
	@rm -f $(OBJS) $(SRCS:.c=.c~)
endif

fclean: clean
ifneq ($(wildcard $(NAME)),)
	@printf '$(PRINT_MIN) fcleaning $(NAME)\n'
	@rm -f $(NAME)
endif

re: fclean $(NAME)