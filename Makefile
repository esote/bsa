LIB=	bsa
SRCS=	bsa.c
OBJS=	bsa.o

CFLAGS=		-Wall -O2 -fPIC
LDFLAGS=	-Wl,-soname,lib$(LIB).so -Wl,-z,now -Wl,-z,relro

$(LIB): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)
	$(CC) -shared $(LDFLAGS) -o lib$(LIB).so $(OBJS)

CHK_PROG=	bsa_check
CHK_SRCS=	$(SRCS) bsa_check.c
CHK_FLAGS=	-g -Wall -Wextra -Wconversion -Wundef -Wimplicit -lcheck

$(CHK_PROG): $(CHK_SRCS)
	$(CC) $(CHK_FLAGS) -o $(CHK_PROG).out $(CHK_SRCS)

clean:
	rm -f $(CHK_PROG).out $(OBJS) lib$(LIB).so
