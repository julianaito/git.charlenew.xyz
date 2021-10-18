# $OpenBSD: Makefile,v 1.2 2019/05/03 05:32:41 rsadowski Exp $

# XXX UNOFFICIAL XXX
# XXX It's primarily made to get a static cmark for usage with cgit in
# a httpd chroot. You can't package it, as it may break the few ports
# that depend on it.

# How to get it:
# $ make
#
# That it's, at the end the cmark static binary location will be shown.


COMMENT =	CommonMark parsing and rendering library and program in C

GH_ACCOUNT =	commonmark
GH_PROJECT =	cmark
GH_TAGNAME =	0.29.0

CATEGORIES =	textproc

HOMEPAGE =	https://commonmark.org/

# BSD2
PERMIT_PACKAGE =	Yes

MODULES =	devel/cmake

CONFIGURE_ARGS +=	-DCMARK_STATIC=ON
CONFIGURE_ARGS +=	-DCMARK_SHARED=OFF
CONFIGURE_ENV +=	LDFLAGS="${LDFLAGS} ${STATIC}"

post-build:
	strip ${WRKBUILD}/src/cmark
	@printf "\nThe static cmark binary can be found at:\n%s\n\n" \
		${WRKBUILD}/src/cmark

package fake install:
	@echo "It's not meant to be packaged/installed!"

.include <bsd.port.mk>
