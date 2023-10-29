NAME			=	libftprintf.a

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
AR				=	ar
ARFLAGS 		=	rcs
RM				=	rm -rf

OUT_DIR			=	build
SRCS			=	ft_printf.c ft_args.c ft_str_insert.c ft_convert.c convert_c.c convert_id.c convert_p.c convert_s.c convert_u.c convert_upx.c convert_x.c hex_convert.c
SRC_DIR			=	./src
OBJS			=	$(SRCS:%.c=$(OUT_DIR)/%.o)

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

all:				$(NAME)


$(OBJS): $(OUT_DIR)/%.o: $(SRC_DIR)/%.c
					mkdir -p $(@D)
					@echo "Compiling $<"
					$(CC) $(CFLAGS) -Iincludes -c $< -o $@

bonus:				all

$(NAME):			$(LIBFT) $(OBJS)
					$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(LIBFT):
					make -C $(LIBFT_PATH) bonus
					cp	$(LIBFT) ./$(NAME)

clean:
					make -C $(LIBFT_PATH) clean
					$(RM) ${OBJS}

fclean:				clean
					make -C $(LIBFT_PATH) fclean
					$(RM) $(NAME)
					rm -f libft.so
					rm -f libftprintf.so
					rm -f libftprintf.a
					rm -f libft.a
					rm -f test.out

re:					fclean all

so:		all
					make -C $(LIBFT_PATH) so
					cp $(LIBFT_PATH)/libft.so .
					gcc -lft -L . -nostartfiles -shared -o libftprintf.so $(OBJS)

test:				${OUT_DIR}
					make -C $(LIBFT_PATH) bonus so
					gcc src/*.c -I includes -I libft/ -I . -L libft -fPIC -lft -Wl,-rpath=libft/ -o build/test -g
					./build/test

retest:				fclean test

.PHONY:				all bonus clean fclean re libft test

${OUT_DIR}:
		mkdir -p ${OUT_DIR}
