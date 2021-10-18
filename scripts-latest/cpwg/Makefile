BIN =		cpwg
MAN =		${BIN}.1

PREFIX ?=	/usr/local
BINDIR ?=	${PREFIX}/bin
MANDIR ?=	${PREFIX}/man/man1

.PHONY: all install uninstall

all:
	@echo "Nothing to build - use install or uninstall"

install:
	install -d ${BINDIR}
	install -d ${MANDIR}
	install ${BIN} ${BINDIR}/${BIN}
	install -m 0644 ${MAN} ${MANDIR}/${MAN}

uninstall:
	rm ${BINDIR}/${BIN} ${MANDIR}/${MAN}
	-rmdir ${BINDIR} ${MANDIR}
