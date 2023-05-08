tranquillity: lcstring.o file.o pretreatment.o  object.o runtime.o tranquillity.o
	gcc -o tranquillity lcstring.o file.o object.o runtime.o tranquillity.o

lcstring.o: lcstring.c lcstring.h
	gcc -c lcstring.c

file.o: file.c file.h tranquillity.h
	gcc -c file.c

pretreatment.o: pretreatment.c pretreatment.h
	gcc -c pretreatment.c

object.o: object.c object.h
	gcc -c object.c

runtime.o: runtime.c runtime.h
	gcc -c runtime.c

tranquillity.o: tranquillity.c tranquillity.h
	gcc -c tranquillity.c

.PHONY: clean
clean:
	-rm *.o
	-rm *.exe
	-del *.o
	-del *.exe