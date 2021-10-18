# $OpenBSD: Makefile,v 1.12 2020/07/03 21:12:38 sthen Exp $

# XXX This is an UNOFFICIAL port, with an unused PKGNAME, see pkg/DESCR
# for the motivation behind this, unless you're on a very slow arch
# with -current packages that are already old, you don't need it.

COMMENT =		distributed builds for C, C++ and Objective C (minimal)

GH_PROJECT =		distcc
GH_ACCOUNT =		distcc
VERSION =		3.3.5
REVISION=		0
DISTNAME =		distcc-${VERSION}
PKGNAME =		distcc-minimal-${VERSION}
CATEGORIES =		devel net

HOMEPAGE =		https://distcc.github.io/

# GPLv2
PERMIT_PACKAGE =	Yes

WANTLIB += c popt pthread

MASTER_SITES =		https://github.com/distcc/distcc/releases/download/v${VERSION}/

LIB_DEPENDS =		devel/popt

USE_GMAKE =		Yes

CONFIGURE_STYLE =	gnu
CONFIGURE_ENV =		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS +=	--without-libiberty \
			--without-avahi \
			--without-gtk \
			--disable-pump-mode

FAKE_FLAGS =		sysconfdir="${PREFIX}/share/examples/"

pre-configure:
	cd ${WRKSRC} && sed -i -E \
	    -e 's,/usr/(bin|lib)/distcc,${PREFIX}/\1/distcc,g' \
	    man/distcc.1 man/distccd.1 update-distcc-symlinks.py \
	    src/daemon.c src/serve.c

post-install:
	rm -r ${PREFIX}/share/examples/default

.include <bsd.port.mk>

# Don't try to use distcc to build itself
COMPILER_WRAPPER=
