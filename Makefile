src = $(wildcard *.c)
obj = $(src:.c=.o)

CFLAGS = --std=c11
LDFLAGS = `sdl2-config --cflags --libs`

chipb8: $(obj)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

main.o: main.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c -o $@ $<

graphics.o: graphics.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c -o $@ $<

input.o: input.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c -o $@ $<

chip8.o: chip8.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm $(obj) chipb8
