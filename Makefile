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
			$(SRC_PATH)/parse2.c \
			$(SRC_PATH)/init.c \
			$(SRC_PATH)/simulation.c \
			$(SRC_PATH)/monitor.c \
			$(SRC_PATH)/utils.c \
			$(SRC_PATH)/time_utils.c \
			$(SRC_PATH)/clean.c \

OBJS        = $(SRCS:$(SRC_PATH)/%.c=$(BUILD_PATH)/%.o)

#==============================================================================#
#                              FLAGS & COMMANDS                                #
#==============================================================================#

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g
CFLAGS     += -pthread
INC         = -I$(INC_PATH)

RM          = rm -f
AR          = ar rcs
MKDIR_P     = mkdir -p
V_ARGS      = --leak-check=full --show-leak-kinds=all
# V_ARGS      = --tool=helgrind

#==============================================================================#
#                                    RULES                                     #
#==============================================================================#

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INC) -o $(NAME) $(OBJS)

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.c $(HEADERS)
	$(MKDIR_P) $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

#==============================================================================#
#                                 TESTS W/ARGS                                 #
#==============================================================================#

test1:
	valgrind $(V_ARGS) ./$(NAME) 1 800 200 200

test2:
	valgrind $(V_ARGS) ./$(NAME) 4 310 200 100

test3:
	valgrind $(V_ARGS) ./$(NAME) 200 180 60 60

test4:
	valgrind $(V_ARGS) ./$(NAME) 4 410 200 200

test5:
	valgrind $(V_ARGS) ./$(NAME) 5 800 200 200

test6:
	valgrind $(V_ARGS) ./$(NAME) 5 800 200 200 7

#==============================================================================#

clean:
	$(RM) $(OBJS)
	$(RM) -r $(BUILD_PATH)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
