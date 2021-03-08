CC=clang
LDFLAGS = -L../build -lhelium -Wl,-rpath=../build
TARGET ?= tests
CFLAGS ?= -Wall -I../..

SRCS := tests.c
OBJS := $(addsuffix .o,$(basename $(SRCS)))

%.o: %.c
	@echo [ CC ] $<
	@$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	@echo [ BIN ] $<
	@$(CC) $(LDFLAGS) $(OBJS) -o $@ $(LOADLIBS) $(LDLIBS)

.PHONY: clean
clean:
	$(RM) $(TARGET) $(OBJS) 
