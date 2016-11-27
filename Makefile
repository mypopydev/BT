IDIR =include
CC=gcc
CFLAGS=-I$(IDIR) -Wall

ODIR=obj
LDIR =lib

LIBS=-lm -lbluetooth

_DEPS = bluetooth.h xxtea.h urlencode.h rl_protocol.h stringx.h \
	urlparser.h http_client.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = bluetooth.o xxtea.o urlencode.o rl_protocol.o stringx.o \
	urlparser.o http_client.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

bluetooth: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ bluetooth
