OBJECTS = abs_max.o abs_min.o diff.o sum.o

all: menu

menu: menu.o $(OBJECTS)
	gcc -std=gnu99 -o menu menu.o $(OBJECTS)

diff.o:abs_max.h abs_min.h

sum.o:abs_max.h

menu.o: menu.c *.h
	gcc -std=gnu99 -c menu.c

$(OBJECTS): %.o: %.c %.h
	gcc -std=gnu99 -c $<

clean:
	rm *.o menu
