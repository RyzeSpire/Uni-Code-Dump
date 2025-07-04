CC = gcc
TARGET = trabalho_2
SOURCE = ./src
INCLUDE = ./include
OBJETOS = ./objs

all: $(TARGET)

$(TARGET): $(OBJETOS)/utils.o $(OBJETOS)/menus.o $(OBJETOS)/cadastros.o $(OBJETOS)/relatorios.o $(OBJETOS)/buscas.o $(OBJETOS)/main.o
	$(CC) $(OBJETOS)/utils.o $(OBJETOS)/menus.o $(OBJETOS)/cadastros.o $(OBJETOS)/relatorios.o $(OBJETOS)/buscas.o $(OBJETOS)/main.o -o $(TARGET)

$(OBJETOS)/utils.o: $(SOURCE)/utils.c $(INCLUDE)/utils.h $(INCLUDE)/types.h
	mkdir -p $(OBJETOS)
	$(CC) -c $(SOURCE)/utils.c -I$(INCLUDE) -o $(OBJETOS)/utils.o

$(OBJETOS)/menus.o: $(SOURCE)/menus.c $(INCLUDE)/menus.h $(INCLUDE)/types.h $(INCLUDE)/utils.h
	$(CC) -c $(SOURCE)/menus.c -I$(INCLUDE) -o $(OBJETOS)/menus.o

$(OBJETOS)/cadastros.o: $(SOURCE)/cadastros.c $(INCLUDE)/cadastros.h $(INCLUDE)/types.h $(INCLUDE)/utils.h $(INCLUDE)/buscas.h
	$(CC) -c $(SOURCE)/cadastros.c -I$(INCLUDE) -o $(OBJETOS)/cadastros.o

$(OBJETOS)/relatorios.o: $(SOURCE)/relatorios.c $(INCLUDE)/relatorios.h $(INCLUDE)/types.h $(INCLUDE)/utils.h
	$(CC) -c $(SOURCE)/relatorios.c -I$(INCLUDE) -o $(OBJETOS)/relatorios.o

$(OBJETOS)/buscas.o: $(SOURCE)/buscas.c $(INCLUDE)/buscas.h $(INCLUDE)/types.h $(INCLUDE)/utils.h
	$(CC) -c $(SOURCE)/buscas.c -I$(INCLUDE) -o $(OBJETOS)/buscas.o

$(OBJETOS)/main.o: mainc.c $(INCLUDE)/types.h $(INCLUDE)/utils.h $(INCLUDE)/relatorios.h $(INCLUDE)/menus.h $(INCLUDE)/cadastros.h $(INCLUDE)/buscas.h
	$(CC) -c mainc.c -I$(INCLUDE) -o $(OBJETOS)/main.o
	


clear:
	rm -f $(TARGET)
	rm -f $(OBJETOS)/*.o

.PHONY: all clear