TARGET  = coin_info

SRCS	= $(shell find -name '*.[cS]')
OBJS	= $(addsuffix .o,$(basename $(SRCS)))

CFLAGS	= -lcurl

all: $(OBJS)
	@echo "LD  "$(TARGET)
	@$(CC) $(OBJS) -o $(TARGET) $(CFLAGS)

%.o: %.c
	@echo "CC  "$<
	@$(CC) -c -o $@ $^ $(CFLAGS)

clean:
	@rm -rf $(TARGET)
	@rm -rf $(OBJS)
