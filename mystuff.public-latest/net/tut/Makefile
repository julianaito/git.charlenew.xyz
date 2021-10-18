# $OpenBSD: Makefile,v 1.1.1.1 2021/05/25 22:14:44 abieber Exp $

COMMENT =	text user interface for mastodon

MODGO_MODNAME =	github.com/RasmusLindroth/tut
# To update, empty the version and see modgo-gen-modules in go-module(5)
MODGO_VERSION =	v0.0.0-20210912191755-dd7b536d5927

DISTNAME =	tut-0.0.33

HOMEPAGE =	https://github.com/RasmusLindroth/tut

CATEGORIES =	net

# MIT
PERMIT_PACKAGE =	Yes

WANTLIB += c pthread

MODULES =		lang/go

# The default configuration uses xdg-open to open links and medias.
RUN_DEPENDS =	devel/xdg-utils

.include "modules.inc"

.include <bsd.port.mk>
