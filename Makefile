TARGET  = coin_info

SRCS	= $(wildcard 00_source_code/*.c)
OBJS	= $(addsuffix .o,$(basename $(SRCS)))

CFLAGS	= -lcurl -ljson -I./01_include -Wall

all: $(OBJS)
	@echo "LD  "$(TARGET)
	@$(CC) $(OBJS) -o $(TARGET) $(CFLAGS)

%.o: %.c
	@echo "CC  "$(notdir $<)
	@$(CC) -c -o $@ $^ $(CFLAGS)

clean:
	@rm -rf $(TARGET)
	@rm -rf $(OBJS)
