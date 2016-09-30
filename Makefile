TARGET  = coin_info

SRCS	= $(wildcard 00_source_code/*.c)
OBJS	= $(addsuffix .o,$(basename $(SRCS)))

CFLAGS	= -lcurl -ljson -I./01_include -Wall -g

all: $(OBJS)
	@echo "LD  "$(TARGET)
	@$(CC) $(OBJS) -o $(TARGET) $(CFLAGS)

test:
	@$(MAKE) -C 98_test

%.o: %.c
	@echo "CC  "$(notdir $<)
	@$(CC) -c -o $@ $^ $(CFLAGS)

clean:
	@rm -rf $(TARGET)
	@rm -rf $(OBJS)
