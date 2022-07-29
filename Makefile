NAME		=	libftprintf.a
LIBFT		=	libft.a
ARRC		=	ar rcs
CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror -I ${SRCS_DIR}ft_printf.h
SRCS_FILES	=	ft_printf \
				ft_printfc \
				ft_prints \
				ft_printfp \
				ft_extrafunct \


SRCS		= 	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))
OBJS		= 	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILES)))
BONUS_FILES	=	ft_printf \
				ft_printfc \
				ft_prints \
				ft_printfp \
				ft_extrafunct \

				
BONUS		= 	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))
BOBJS		= 	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILES)))
# BONUS		= 	$(addprefix $(BONUS_DIR), $(addsuffix .c, $(BONUS_FILES)))
# BOBJS		= 	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(BONUS_FILES)))
SRCS_DIR	=	srcs/
LIBFT_DIR	=	libft
OBJS_DIR	=	objs/
BONUS_DIR	=	bonus/

all:			$(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR)%.o: $(BONUS_DIR)%.c
				$(CC) $(CFLAGS) -c $< -o $@

$(NAME):		mkdir_objs create_libft $(OBJS)
				$(ARRC) $(NAME) $(OBJS)

bonus:			mkdir_objs create_libft $(BOBJS)
				$(ARRC) $(NAME) $(BOBJS)

create_libft:
				make -C $(LIBFT_DIR)
				cp $(LIBFT_DIR)/$(LIBFT) .
				mv $(LIBFT) $(NAME)

mkdir_objs:
				mkdir -p $(OBJS_DIR)

clean:
				rm -rf $(OBJS_DIR)
				make fclean -C $(LIBFT_DIR)

fclean:			clean
				rm -rf $(NAME)
				rm -rf $(LIBFT)

re:				fclean all

.PHONY: 		all clean fclean re