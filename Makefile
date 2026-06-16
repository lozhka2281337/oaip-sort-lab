CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = sorting

OBJ_DIR = obj
GEN_DIR  = generators
SORT_DIR = algorithms

SRCS = main.c \
	$(GEN_DIR)/generateArray.c \
	$(SORT_DIR)/selectSort.c \
	$(SORT_DIR)/bubbleSort.c \
	$(SORT_DIR)/quickSort.c \
	$(SORT_DIR)/mergeSort.c \
	$(SORT_DIR)/heapSort.c 

DEPS = $(GEN_DIR)/generateArray.h $(SORT_DIR)/sort.h 

OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

$(OBJ_DIR)/%.o: %.c $(DEPS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(TAGRET)
	rm sorting

.PHONY: all clean