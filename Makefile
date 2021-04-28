NAME := ft_ls

# **************************************************************************** #

SRC_DIR := src

SRC := cmp.c \
       error.c \
       init.c \
       main.c \
       parse.c \
       print_files.c \
       process_absent.c \
       process_files.c

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

CFLAGS += -Wall -Wextra -Werror \
          $(addprefix -I , $(INC_DIRS)) \
          -MMD \
          -O0 -g3  # TODO
#          -O2 -march=native -ftree-vectorize -pipe

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
