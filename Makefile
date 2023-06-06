OBJ = lcstring.o file.o tranquillity.o

tranquillity: $(OBJ)
	gcc -o tranquillity $(OBJ)

LCS_Dir = ./tools/lightweight-cstring/src
LCS_H_Dir = ./tools/lightweight-cstring/dist/include

SRC = ./src
INC = ./Include

lcstring.o: $(LCS_Dir)/lcstring.c $(LCS_H_Dir)/lcstring.h
	gcc -c $(LCS_Dir)/lcstring.c

file.o: $(SRC)/file.c $(INC)/file.h $(INC)/tranquillity.h
	gcc -c $(SRC)/file.c -I $(INC) -I $(LCS_H_Dir)

tranquillity.o: $(SRC)/tranquillity.c $(INC)/tranquillity.h
	gcc -c $(SRC)/tranquillity.c -I $(INC) -I $(LCS_H_Dir)

.PHONY: clean
clean:
	-rm *.o
	-rm *.exe
	-del *.o
	-del *.exe