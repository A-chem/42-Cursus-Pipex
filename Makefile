NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror 
SRC = ./Mandatory/src/pipex.c  ./Mandatory/src/check_exec_cmd.c ./Mandatory/src/handle_error1.c ./Mandatory/src/handle_error2.c \
		./Mandatory/utils/ft_strjoin.c ./Mandatory/utils/ft_strlen.c ./Mandatory/utils/ft_strncmp.c  \
		./Mandatory/utils/fonction_utils.c ./Mandatory/utils/ft_split.c ./Mandatory/utils/ft_putstr.c \
		./Mandatory/utils/ft_strchr.c ./Mandatory/utils/ft_strtrim.c
		
OBJS = $(SRC:.c=.o)
SRCS_BONUS =  ./Bonus/src/pipex_bonus.c ./Bonus/src/handle_error1_bonus.c  ./Bonus/src/check_exec_cmd_bonus.c \
			./Bonus/src/here_doc_bonus.c ./Bonus/src/process_bonus.c \
			./Bonus/utils/fonction_utils_bonus.c ./Bonus/utils/ft_strcmp_bonus.c ./Bonus/utils/ft_split_bonus.c  \
			./Bonus/utils/ft_putstr_bonus.c ./Bonus/utils/ft_strncmp_bonus.c ./Bonus/utils/get_next_line_bonus.c ./Bonus/utils/get_next_line_utils_bonus.c\
			./Bonus/utils/ft_strtrim_bonus.c
BONUS_OBJS = $(SRCS_BONUS:.c=.o)

GREEN       := \033[32m
YELLOW      := \033[33m
CYAN        := \033[36m
RESET       := \033[0m
OK_SIGN     := ✅
ERROR_SIGN  := ❌
INFO_SIGN   := ℹ️
WORKING     := 🔧

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(OK_SIGN) $(GREEN)Compilation complete for mandatory!$(RESET)"
	@echo "\033[34m\
	███╗   ███╗        ██████╗ ██╗██████╗ ███████╗██╗  ██╗\n\
	████╗ ████║        ██╔══██╗██║██╔══██╗██╔════╝╚██╗██╔╝\n\
	██╔████╔██║        ██████╔╝██║██████╔╝█████╗   ╚███╔╝ \n\
	██║╚██╔╝██║        ██╔═══╝ ██║██╔═══╝ ██╔══╝   ██╔██╗ \n\
	██║ ╚═╝ ██║███████╗██║     ██║██║     ███████╗██╔╝ ██╗\n\
	╚═╝     ╚═╝╚══════╝╚═╝     ╚═╝╚═╝     ╚══════╝╚═╝  ╚═╝\n\
	\033[0m"


bonus: $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(NAME)
	@echo "$(OK_SIGN) $(GREEN)Compilation complete for bonus!$(RESET)"
		@echo "\033[34m\
	██████╗         ██████╗ ██╗██████╗ ███████╗██╗  ██╗\n\
	██╔══██╗        ██╔══██╗██║██╔══██╗██╔════╝╚██╗██╔╝\n\
	██████╔╝        ██████╔╝██║██████╔╝█████╗   ╚███╔╝ \n\
	██╔══██╗        ██╔═══╝ ██║██╔═══╝ ██╔══╝   ██╔██╗ \n\
	██████╔╝███████╗██║     ██║██║     ███████╗██╔╝ ██╗\n\
	╚═════╝ ╚══════╝╚═╝     ╚═╝╚═╝     ╚══════╝╚═╝  ╚═╝\n\
	\033[0m"

./Mandatory/%.o: ./Mandatory/%.c ./Mandatory/include/pipex.h
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(WORKING) $(CYAN)Compiling: $<$(RESET)"

./Bonus/%.o: ./Bonus/%.c ./Bonus/include/pipex_bonus.h ./Bonus/include/get_next_line_bonus.h
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(WORKING) $(CYAN)Compiling: $<$(RESET)"

clean:
	@echo "$(INFO_SIGN) $(YELLOW)Cleaning object files...$(RESET)"
	@rm -f $(OBJS) $(BONUS_OBJS)
	@echo "$(OK_SIGN) $(GREEN)Object files cleaned!$(RESET)"

fclean: clean
	@echo "$(INFO_SIGN) $(YELLOW)Removing executables: $(NAME) and $(NAME_BONUS)$(RESET)"
	@rm -f $(NAME) $(NAME_BONUS)
	@echo "$(OK_SIGN) $(GREEN)Executables removed!$(RESET)"

re: fclean all