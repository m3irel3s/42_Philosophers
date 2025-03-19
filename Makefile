#==============================================================================#
#                           PHILOSOPHERS PROJECT                               #
#==============================================================================#

NAME        = philo

#==============================================================================#
#                             NAMES AND PATHS                                  #
#==============================================================================#

BUILD_PATH  = .build
SRC_PATH    = src
INC_PATH    = inc

HEADERS     = $(addprefix $(INC_PATH)/, philo.h)

SRCS        = $(SRC_PATH)/main.c \
			$(SRC_PATH)/parse.c \
			$(SRC_PATH)/init.c \
			$(SRC_PATH)/utils.c \
			$(SRC_PATH)/time_utils.c \
			$(SRC_PATH)/clean.c \

OBJS        = $(SRCS:$(SRC_PATH)/%.c=$(BUILD_PATH)/%.o)

#==============================================================================#
#                              FLAGS & COMMANDS                                #
#==============================================================================#

CC          = gcc
CFLAGS      = -Wall -Wextra -Werror
CFLAGS     += -pthread
INC         = -I$(INC_PATH)

RM          = rm -f
AR          = ar rcs
MKDIR_P     = mkdir -p

#==============================================================================#
#                                    RULES                                     #
#==============================================================================#

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INC) -o $(NAME) $(OBJS)

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.c $(HEADERS)
	$(MKDIR_P) $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) -r $(BUILD_PATH)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
