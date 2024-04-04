# Colors
GREEN=\033[0;32m
YELLOW=\033[0;33m
NC=\033[0m

# Target and Compiler Settings
NAME        := push_swap
CC          := cc
CFLAGS      := -Wextra -Wall -Werror
# Source Files
SRCS        := srcs/list_utils.c srcs/main.c srcs/swap_moves.c srcs/push_moves.c srcs/rotate_moves.c\
				srcs/reverse_moves.c srcs/input.c srcs/validations.c srcs/sort_algorithm.c srcs/sort_three.c\
				srcs/final_rank.c srcs/costs.c srcs/utils.c srcs/find_cheapest.c
SRCS_BONUS  := srcs_bonus/checker.c srcs_bonus/swap_moves.c srcs_bonus/push_moves.c srcs_bonus/rotate_moves.c\
				srcs_bonus/reverse_moves.c srcs_bonus/input.c srcs_bonus/list_utils.c srcs_bonus/validations.c\
				srcs_bonus/utils.c
OBJS_PATH   := ./objs
OBJS_PATH_BONUS := ./objs_bonus
OBJS        := $(patsubst srcs/%.c,$(OBJS_PATH)/%.o,$(SRCS))
OBJS_BONUS  := $(patsubst srcs_bonus/%.c,$(OBJS_PATH_BONUS)/%.o,$(SRCS_BONUS))
INCLUDE := include

# libs #
INCLUDES = -I$(INCLUDE)/ -Ilib/libft/include/
LINCLUDES = -L$(LIBFT_PATH) -lft

LIBFT = lib/libft/libft.a
LIBFT_PATH = lib/libft

# Targets
all: $(OBJS_PATH) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LINCLUDES) -o $@
	@echo "${GREEN}Compilation completed.${NC}"

$(OBJS_PATH)/%.o: ./srcs/%.c $(INCLUDE)/push_swap.h | $(OBJS_PATH)
	@echo "${YELLOW}Compiling $<.${NC}"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_PATH_BONUS)/%.o: ./srcs_bonus/%.c $(INCLUDE)/push_swap_bonus.h | $(OBJS_PATH_BONUS)
	@echo "${YELLOW}Compiling bonus $<.${NC}"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_PATH):
	@mkdir -p $(OBJS_PATH)

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_PATH)
	@echo "${YELLOW}Libft Compiled.${NC}"

clean:
	@rm -rf $(OBJS_PATH) $(OBJS_PATH_BONUS)
	@$(MAKE) -C $(LIBFT_PATH) clean
	@echo "${YELLOW}Cleaning objects.${NC}"

fclean: clean
	@rm -f $(NAME)
	@rm -f checker
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@echo "${YELLOW}Cleaning executables.${NC}"

bonus: $(OBJS_PATH_BONUS) $(OBJS_BONUS) $(LIBFT)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS_BONUS) $(LINCLUDES) -o checker
	@echo "${GREEN}Compilation bonus completed.${NC}"

$(OBJS_PATH_BONUS)/%.o: ./srcs_bonus/%.c $(INCLUDE)/push_swap_bonus.h | $(OBJS_PATH_BONUS)
	@echo "${YELLOW}Compiling bonus $<.${NC}"
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)

$(OBJS_PATH_BONUS):
	@mkdir -p $(OBJS_PATH_BONUS)

re: fclean all

.PHONY: all clean fclean re
