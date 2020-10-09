# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/09 19:00:32 by nalysann          #+#    #+#              #
#    Updated: 2020/10/09 19:00:58 by nalysann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LS = ft_ls

SRC_DIR = src

SRC =

INC_DIR = include \
          $(FT_DIR)/include

OBJ_DIR = obj

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

DEP = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.d))

FT_DIR = libft

FT = libft.a

UNAME_S = $(shell uname -s)

ifeq ($(UNAME_S), Darwin)
	CC = clang
endif

ifeq ($(UNAME_S), Linux)
	CC = gcc
endif

CFLAGS += -Wall -Wextra -Werror \
          $(addprefix -I , $(INC_DIR)) \
          -MD \
          -march=native -O2 -pipe

LDFLAGS += -L $(FT_DIR)

LDLIBS += -lft

RESET = \033[0;0m
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m

.PHONY: all clean fclean re

all:
	@printf "$(CYAN)>>> Making $(FT_DIR) <<<\n$(RESET)"
	@$(MAKE) -C $(FT_DIR)
	@printf "$(CYAN)>>> Making $(LS) <<<\n$(RESET)"
	@$(MAKE) $(LS)


$(LS): $(OBJ) $(FT_DIR)/$(FT)
	@printf "$(GREEN)"
	$(CC) $(LDFLAGS) $(LDLIBS) $(OBJ) -o $@
	@printf "$(RESET)"

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@printf "$(MAGENTA)"
	$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(RESET)"

include $(wildcard $(DEP))

clean:
	@printf "$(CYAN)>>> Cleaning $(FT_DIR) <<<\n$(RESET)"
	@$(MAKE) -C $(FT_DIR) clean
	@printf "$(CYAN)>>> Cleaning $(LS) <<<\n$(RESET)"
	@printf "$(RED)"
	rm -rf $(OBJ_DIR)
	@printf "$(RESET)"

fclean: clean
	@printf "$(CYAN)>>> Purging $(FT_DIR) <<<\n$(RESET)"
	@$(MAKE) -C $(FT_DIR) fclean
	@printf "$(CYAN)>>> Purging $(LS) <<<\n$(RESET)"
	@printf "$(RED)"
	rm -f $(LS)
	@printf "$(RESET)"

re: fclean all
