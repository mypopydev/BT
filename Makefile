IDIR =include
CC=gcc
CFLAGS=-I$(IDIR) -Wall

ODIR=obj
LDIR =lib

LIBS=-lm -lbluetooth

_DEPS = bluetooth.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = bluetooth.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

bluetooth: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ bluetooth
