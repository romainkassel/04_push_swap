NAME = push_swap
NAME_BONUS = checker

SRCS = ./srcs/
SRCS_BONUS = ./bonus/srcs/

LIBFT_FLAGS = -Llibft -lft

PS_INCLUDES = -Iincludes
PS_INCLUDES_BONUS = -Ibonus/includes
LIBFT_INCLUDES = -Ilibft
FT_PRINTF_INCLUDES = -Ilibft/ft_printf/includes

CFILES = $(SRCS)push_swap.c $(SRCS)expand_argv.c $(SRCS)check_args.c $(SRCS)manage_stacks.c $(SRCS)ops_swap.c $(SRCS)ops_push.c $(SRCS)ops_rotate.c $(SRCS)ops_reverse_rotate.c $(SRCS)exit_program.c $(SRCS)manage_ptrs.c $(SRCS)do_the_trick_1.c $(SRCS)do_the_trick_2.c $(SRCS)do_the_trick_3.c $(SRCS)do_the_trick_4.c $(SRCS)do_the_trick_5.c $(SRCS)do_the_trick_6.c
OFILES = $(CFILES:.c=.o)

CFILES_BONUS = $(SRCS_BONUS)push_swap_bonus.c $(SRCS_BONUS)expand_argv_bonus.c $(SRCS_BONUS)check_args_bonus.c $(SRCS_BONUS)manage_stacks_bonus.c $(SRCS_BONUS)ops_swap_bonus.c $(SRCS_BONUS)ops_push_bonus.c $(SRCS_BONUS)ops_rotate_bonus.c $(SRCS_BONUS)ops_reverse_rotate_bonus.c $(SRCS_BONUS)exit_program_bonus.c $(SRCS_BONUS)manage_ptrs_bonus.c $(SRCS_BONUS)do_the_trick_1_bonus.c $(SRCS_BONUS)do_the_trick_2_bonus.c $(SRCS_BONUS)do_the_trick_3_bonus.c $(SRCS_BONUS)do_the_trick_4_bonus.c $(SRCS_BONUS)do_the_trick_5_bonus.c $(SRCS_BONUS)do_the_trick_6_bonus.c
OFILES_BONUS = $(CFILES_BONUS:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OFILES)
	make -C libft/
	$(CC) -o $(NAME) $(OFILES) $(LIBFT_FLAGS)

$(SRCS)%.o: $(SRCS)%.c
	$(CC) $(FLAGS) -c -o $@ $< $(PS_INCLUDES) $(LIBFT_INCLUDES) $(FT_PRINTF_INCLUDES)

$(SRCS_BONUS)%.o: $(SRCS_BONUS)%.c
	$(CC) $(FLAGS) -c -o $@ $< $(PS_INCLUDES_BONUS) $(LIBFT_INCLUDES) $(FT_PRINTF_INCLUDES)

bonus: fclean $(OFILES_BONUS)
	cd libft && $(MAKE)
	rm -f $(NAME)
	$(CC) $(WFLAGS) -o $(NAME_BONUS) $(OFILES_BONUS) $(LIBFT_FLAGS)

clean:
	rm -f $(OFILES)
	rm -f $(OFILES_BONUS)
	cd libft && $(MAKE) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	cd libft && rm -f libft.a

re: fclean all

.PHONY: all clean fclean re bonus
