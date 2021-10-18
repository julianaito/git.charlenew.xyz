CC =		cc
CFLAGS ?=	-O2 -pipe
EXTRACFLAGS=	-Wall -Wextra -pedantic -std=c99

SRCS =		mountpoint.c
PROG =		mountpoint

PREFIX ?=	/usr/local
BINDIR ?=	${PREFIX}/bin
MANDIR ?=	${PREFIX}/man/man1

${PROG}: ${SRCS}
	${CC} ${CFLAGS} ${EXTRACFLAGS} ${SRCS} -o ${PROG}

.PHONY: clean test install uninstall

install: ${PROG}
	install -s -m 0755 ${PROG} ${BINDIR}
	install -m 0644 ${PROG}.1 ${MANDIR}

uninstall:
	rm ${BINDIR}/${PROG}
	rm ${MANDIR}/${PROG}.1

clean:
	rm ${PROG}

test: ${PROG}
	@/bin/sh test.sh ./${PROG}

