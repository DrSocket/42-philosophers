NAME		=	philo

BLACK	=	\e[30m
RED		=	\e[31m
GREEN	=	\e[32m
YELLOW	=	\e[33m
BLUE	=	\e[34m
PURPLE	=	\e[35m
CYAN	=	\e[36m
RESET	=	\033[0m

CC			=	clang
FLAGS		=	#-Wall -Wextra -Werror #-fsanitize=address -g

SRC_DIR		=	srcs/
INC_DIR		=	-I./includes/
OBJ_DIR 	=	objs/

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJS		=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))
DIR			=	$(sort $(dir $(OBJS)))

SRC_BASE 	= \
main.c\
utils.c\
ft_pthread.c

all:	$(NAME)

$(NAME): 	$(OBJS)
	@$(CC) $(INC_DIR) $(FLAGS) -o $@ $(OBJS) $(LIB)
	@printf "\t$(PURPLE)$(NAME) created\n$(END)"

$(DIR):
	@mkdir -p $@

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(DIR)
	@printf "\t$(GREEN)Compiling [$(END)";
	@$(CC) -c $(FLAGS) $< -o $@ $(INC_DIR)
	@printf "$(CYAN)$(notdir $^)$(GREEN)]$(END)\n";

clean:
	@if [ -d $(OBJ_DIR) ]; \
		then \
		printf "\t$(YELLOW)Object files successfully deleted\n$(END)"; \
		rm -rf $(OBJ_DIR); \
		fi;

fclean:		clean
	@if [ -e $(NAME) ]; \
		then \
		printf "\t$(RED)$(NAME) successfully deleted\n$(END)"; \
		rm -rf $(NAME); \
		fi;

re:			fclean all

.PHONY:		all clean fclean re
