src = $(wildcard *.c)
obj = $(src:.c=.o)

LDFLAGS = `sdl2-config --cflags --libs`

chipb8: $(obj)
	$(CC) -o $@ $^ 

main.o: main.c
	$(CC) $(LDFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm $(obj) chipb8
