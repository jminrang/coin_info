TARGET  = coin_info

SRCS	= $(shell find -name '*.[cS]')
OBJS	= $(addsuffix .o,$(basename $(SRCS)))

CFLAGS	= -lcurl

all: $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c
	@echo "CC  "$<
	@$(CC) $(CFLAGS) -c -o $@ $^

clean:
	@rm -rf $(TARGET)
	@rm -rf $(OBJS)
