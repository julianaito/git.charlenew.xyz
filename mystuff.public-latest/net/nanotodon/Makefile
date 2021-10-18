# $OpenBSD: Makefile.template,v 1.90 2021/02/25 21:59:27 sthen Exp $

COMMENT =	text user interface client for mastodon

# XXX see https://gist.github.com/ao-kenji/c734809b784fd451a56147601adb200b
# XXX and modify files/Makefile.bsd-wrapper accordingly when updating
GH_ACCOUNT =	taka-tuos
GH_PROJECT =	nanotodon
GH_TAGNAME =	0.2.0

CATEGORIES =	net

# MIT
PERMIT_PACKAGE =	Yes

WANTLIB += c curl curses json-c pthread

LIB_DEPENDS =	devel/json-c \
		net/curl

NO_TEST =	Yes

MAKE_FILE =	Makefile.bsd-wrapper

post-extract:
	${SUBST_CMD} -m 555 -c ${FILESDIR}/${MAKE_FILE} ${WRKSRC}/${MAKE_FILE}

.include <bsd.port.mk>
