tranquillity: lcstring.o file.o pretreatment.o  object.o runtime.o tranquillity.o
	gcc -o tranquillity lcstring.o file.o object.o runtime.o tranquillity.o

LCS_Dir = ./tools/lightweight-cstring/src
LCS_H_Dir = ./tools/lightweight-cstring/dist/include

SRC = ./src
INC = ./Include

lcstring.o: $(LCS_Dir)/lcstring.c $(LCS_H_Dir)/lcstring.h
	gcc -c $(LCS_Dir)/lcstring.c

file.o: $(SRC)/file.c $(INC)/file.h $(INC)/tranquillity.h
	gcc -c $(SRC)/file.c -I $(INC) -I $(LCS_H_Dir)

pretreatment.o: $(SRC)/pretreatment.c $(INC)/pretreatment.h
	gcc -c $(SRC)/pretreatment.c -I $(INC) -I $(LCS_H_Dir)

object.o: $(SRC)/object.c $(INC)/object.h
	gcc -c $(SRC)/object.c -I $(INC) -I $(LCS_H_Dir)

runtime.o: $(SRC)/runtime.c $(INC)/runtime.h
	gcc -c $(SRC)/runtime.c -I $(INC) -I $(LCS_H_Dir)

tranquillity.o: $(SRC)/tranquillity.c $(INC)/tranquillity.h
	gcc -c $(SRC)/tranquillity.c -I $(INC) -I $(LCS_H_Dir)

.PHONY: clean
clean:
	-rm *.o
	-rm *.exe
	-del *.o
	-del *.exe