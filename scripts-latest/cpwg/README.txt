CPWG(1)			    General Commands Manual		       CPWG(1)

NAME
     cpwg  cheap password generator

SYNOPSIS
     cpwg [nolc] [nouc] [nunum] [nospec] [len]

DESCRIPTION
     By default, cpwg generates a 32 characters long random password,
     including lower and upper case letters, numbers and a subset of ascii
     special characters.

     It has been made to be very simple and available in minimal (say Busybox)
     environments with my own ccrypt(1) based password manager.	 This comes at
     the cost of features, notably some proper entropy is not granted.

     Options can be put in whatever order you want to:

     nolc    Do not use lowercase letters

     nouc    Do not use uppercase letters

     nonum   Do not use numbers

     nospec  Do not use special characters

     len     An integer value, setting the password length

EXAMPLES
     Generate a password:

	   $ cpwg

     Generate a 16 characters password, without lowercase letters:

	   $ cpwd 16 nolc

     Generate a 24 characters password without uppercase letters and numbers:

	   $ cpwd nonum nouc 24

SEE ALSO
     dicepassc(1), a standalone passphrase generator.

BUGS
     I would have liked to use standard flags for options, but with awk(1), it
     implies using -- which is more annoying in everyday use than this
     option handling.

INSTALLATION

    cpwg is installed by default in '/usr/local':

    $ make install

    If you want to use it out of '/usr/local', you can set the PREFIX
    environment variable:

    $ make PREFIX=~/.local install

    For convenience, 'make uninstall' is available.



OpenBSD 6.8		       January 12, 2021			   OpenBSD 6.8
