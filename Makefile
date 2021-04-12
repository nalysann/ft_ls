# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgilwood <bgilwood@student.21-school.ru>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/09 19:00:32 by nalysann          #+#    #+#              #
#    Updated: 2021/04/12 21:17:40 by bgilwood         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ft_ls

# **************************************************************************** #

SRC_DIR := src

SRC := cmp.c \
       error.c \
       init.c \
       main.c \
       parse.c \
       process.c \
	   process_files_utils.c \
	   process_dir_recursive.c \
	   sort_files.c

OBJ := $(SRC:.c=.o)
DEP := $(SRC:.c=.d)

# **************************************************************************** #

FT_DIR := libft
FT := libft.a

# **************************************************************************** #

INC_DIRS := include \
            $(FT_DIR)/include \

# **************************************************************************** #

OBJ_DIR := obj

OBJ := $(addprefix $(OBJ_DIR)/, $(OBJ))
DEP := $(addprefix $(OBJ_DIR)/, $(DEP))

# **************************************************************************** #

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Darwin)
    CC := clang
endif

ifeq ($(UNAME_S), Linux)
    CC := gcc
endif

# **************************************************************************** #

CFLAGS += -Wall -Wextra -Werror -g \
          $(addprefix -I , $(INC_DIRS)) \
          -MD \
          -march=native -O2 -pipe

LDFLAGS += -L $(FT_DIR)

LDLIBS += -lft

# **************************************************************************** #

RESET   := \033[0;0m
RED     := \033[0;31m
GREEN   := \033[0;32m
YELLOW  := \033[0;33m
BLUE    := \033[0;34m
MAGENTA := \033[0;35m
CYAN    := \033[0;36m
WHITE   := \033[0;37m

# **************************************************************************** #

.PHONY: all clean fclean re

# **************************************************************************** #

all:
	@printf "$(CYAN)>>> Making $(FT_DIR) <<<\n$(RESET)"
	@$(MAKE) -C $(FT_DIR)
	@printf "$(CYAN)>>> Making $(NAME) <<<\n$(RESET)"
	@$(MAKE) $(NAME)

$(FT_DIR)/$(FT):
	@$(MAKE) -C $(FT_DIR)

$(NAME): $(OBJ) $(FT_DIR)/$(FT)
	@printf "$(GREEN)"
	$(CC) $(LDFLAGS) $(LDLIBS) $(OBJ) -o $@
	@printf "$(RESET)"

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@printf "$(MAGENTA)"
	$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(RESET)"

-include $(DEP)

clean:
	@printf "$(CYAN)>>> Cleaning $(FT_DIR) <<<\n$(RESET)"
	@$(MAKE) -C $(FT_DIR) clean
	@printf "$(CYAN)>>> Cleaning $(NAME) <<<\n$(RESET)"
	@printf "$(RED)"
	rm -rf $(OBJ_DIR)
	@printf "$(RESET)"

fclean: clean
	@printf "$(CYAN)>>> Purging $(FT_DIR) <<<\n$(RESET)"
	@$(MAKE) -C $(FT_DIR) fclean
	@printf "$(CYAN)>>> Purging $(NAME) <<<\n$(RESET)"
	@printf "$(RED)"
	rm -f $(NAME)
	@printf "$(RESET)"

re: fclean all
