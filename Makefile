# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/09 17:02:23 by hisasano          #+#    #+#              #
#    Updated: 2025/08/06 20:02:23 by hisasano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
B_NAME := checker

SRC  := bit_radix.c\
		chunk.c\
		index_list.c\
		main.c\
		make_list.c\
		my_atoi.c\
		small_sort.c\
		clean_exit.c\
		ope_push.c\
		ope_rotate.c\
		ope_rev.c\
		ope_swap.c\
		is_sorted.c

B_SRC := main_bonus.c\
		check_stac.c\
		make_list.c\
		my_atoi.c\
		clean_exit.c\
		ope_push_b.c\
		ope_rotate_b.c\
		ope_rev_b.c\
		ope_swap_b.c

SRCDIR       := src
B_SRCDIR 	 := bonus_src
OBJDIR       := obj
B_OBJDIR	 := obj_bonus
INCDIR       := include

CC      := cc
CFLAGS  := -Wall -Wextra -Werror
AR      := ar
ARFLAGS := rcs
RM      := rm -f
RMDIR   := rm -rf

SRCS := $(addprefix $(SRCDIR)/,$(SRC))
B_SRCS := $(addprefix $(B_SRCDIR)/,$(B_SRC))

OBJS := $(addprefix $(OBJDIR)/,$(notdir $(SRCS:.c=.o)))
B_OBJS := $(addprefix $(B_OBJDIR)/,$(notdir $(B_SRCS:.c=.o)))

vpath %.c $(SRCDIR)
vpath %.c $(B_SRCDIR)

all: $(NAME)

bonus: $(B_NAME)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(addprefix -I, $(INCDIR)) -c $< -o $@

$(B_OBJDIR)/%.o: %.c | $(B_OBJDIR)
	$(CC) $(CFLAGS) $(addprefix -I, $(INCDIR)) -c $< -o $@

$(OBJDIR) $(B_OBJDIR):
	@mkdir -p $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(B_NAME): $(B_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	@$(RMDIR) $(OBJDIR) $(B_OBJDIR)

fclean: clean
	$(RM) $(NAME) $(B_NAME)

re: fclean all

.PHONY: all bonus clean fclean re 