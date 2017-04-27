#
# File: Makefile
# Creator: George Ferguson
# Created: Mon Nov 28 13:52:02 2016
# Time-stamp: <Mon Nov 28 14:31:03 EST 2016 ferguson>
#

SRCS = Value.c Gates.c Circuit.c main.c
HDRS = Value.h Gates.h Circuit.h
OBJS = $(SRCS:.c=.o)
EXE = boosim
ZIPDIR = CSC173 Project5 Boolean Circuit Simulator

$(EXE): $(OBJS)
	$(CC) -o $@ $(OBJS)

clean:
	-rm $(OBJS) $(EXE)

zip:
	mkdir '$(ZIPDIR)'
	cp -p $(SRCS) $(HDRS) Makefile '$(ZIPDIR)'
	zip -r '$(ZIPDIR)' '$(ZIPDIR)'
	rm -r '$(ZIPDIR)'

