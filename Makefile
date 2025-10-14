# **************************************************************************** #
#                                   CONFIG                                     #
# **************************************************************************** #

NAME        = philo

CC          = cc
RM          = rm -rf
CFLAGS      = -Wall -Wextra -Werror -Iinclude -g -gdwarf-4

SRCS_DIR    = srcs
OBJS_DIR    = objs

# Trova tutti i file .c nella cartella srcs
SRCS        = $(wildcard $(SRCS_DIR)/*.c)
OBJS        = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

# **************************************************************************** #
#                                   COLORS                                     #
# **************************************************************************** #

BROWN       = \033[1;38;2;101;67;33m
GREEN       = \033[1;92m
RED         = \033[1;91m
LIGHT_CYAN  = \033[1;96m
RESET       = \033[0m

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $(OBJS)
	@printf "$(GREEN)$(NAME) compiled successfully!$(RESET)\n"

# Regola per compilare ogni .c in un .o dentro objs/
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS_DIR)
	@printf "$(RED)Object files cleaned!$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(LIGHT_CYAN)Full cleanup done!$(RESET)\n"

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus