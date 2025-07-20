# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/09 17:02:23 by hisasano          #+#    #+#              #
#    Updated: 2025/07/10 16:49:25 by hisasano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME := push_swap.a

SRC  = ope_swap.c \
	   ope_push.c\
	   ope_rotate.c\
	   ope_rev.c

SRCDIR       := src
OBJDIR       := obj
INCDIR       := include

CC      := cc
CFLAGS  := -Wall -Wextra -Werror
AR      := ar
ARFLAGS := rcs
RM      := rm -f
RMDIR   := rm -rf

SRCS := $(addprefix $(SRCDIR)/,$(SRC))

OBJS := $(addprefix $(OBJDIR)/,$(notdir $(SRCS:.c=.o))) 

vpath %.c $(SRCDIR)

all: $(NAME)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(addprefix -I, $(INCDIR)) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(NAME): $(OBJS)
	@mkdir -p ar_tmp
	@cd ar_tmp && $(AR)
	@$(AR) $(ARFLAGS) $@ $(OBJS) ar_tmp/*.o
	@$(RMDIR) ar_tmp

clean:
	$(MAKE) -C $(LIBFTDIR) clean
	@$(RMDIR) $(OBJDIR)

fclean: clean
	$(MAKE) -C fclean
	$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re