SRC_DIR = ./sources/
OBJ_DIR = ./objects/
INCLUDE = includes
PATH_MLX = ./minilibx-linux
CC = gcc
CFLAGS = -g3 -Wall -Wextra -Werror -fPIC
RM = rm -f
NAME = so_long
LIBFT = ./Libft
FLAGS = -ldl -Imlx -L ./minilibx-linux/ -lm -lbsd -lXext -lX11 -Wl,-rpath=./bass/,-rpath=./mlx/,-rpath=./delay/
SMAKE		= make --no-print-directory

# Colors

END			=	\033[0m
BOLD		=	\033[1m
UNDER		=	\033[4m
REV			=	\033[7m
DEF_COLOR	=	\033[0;39m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
LIGHT_RED	=	\033[0;31m
GREEN		=	\033[0;92m
YELLOW		=	\033[0;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m

SRC_FILES = so_long hook map/map sprite1 map/check player_position player_movement map/check2 player_movement2 path_valid

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(SRC_FILES:=.o))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

libft:
	@$(MAKE) -C $(LIBFT)
	@echo "$(GREEN)Libft compiled successfully!$(END)"

$(NAME): libft  $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT) -lft -L$(PATH_MLX) -lmlx -lXext -lX11 -pie -o $(NAME)

all: ${NAME}
	@echo "$(GREEN)Compilation réussie !$(END)"

.c.o:
	@${CC} ${CFLAGS} -Imlx -Ibass -c $< -o ${<:.c=.o}


$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

bonus: ${OBJS} ${OBJS_B}
	@make -C $(PATH_MLX)
	@${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L$(PATH_MLX) -lmlx $(FLAGS)

clean:
	@$(RM) -r $(OBJ_DIR)
	@echo "$(BLUE)$(NAME) object files cleaned!$(DEF_COLOR)"
	@$(MAKE) -C $(LIBFT) clean

fclean:		clean
	@$(RM) $(NAME)
	@$(RM) $(NAME_B)
	@$(SMAKE) -C $(LIBFT) fclean
	@echo "$(CYAN)$(NAME) executable files cleaned!$(DEF_COLOR)"
	@$(MAKE) -C $(LIBFT) fclean


forbidden :
	nm -gu $(NAME)

norm:
			@norminette $(SRC) $(INCLUDE) | grep -v Norme | awk '{\
			if ($$NF == "OK!") { \
				print "$(GREEN)"$$0"$(END)" \
			} else if ($$NF == "Error!") { \
				print "$(RED)$(BOLD)"$$0"$(END)" \
			} else if ($$1 == "Error:") { \
				print "$(LIGHT_RED)"$$0"$(END)" \
			} else { print }}'

re: fclean all

.PHONY: bonus all clean fclean re
