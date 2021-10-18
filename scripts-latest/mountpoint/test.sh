#!/bin/sh

if test ! -x "$1"; then
	echo "It's needed to build before testing!"
	exit 1
fi

echo
echo "Testing against a valid mountpoint... "
"$1"  /

echo
echo "Testing against an invalid mountpoint... "
invalid="$(mktemp)"
"$1" "$invalid"
rm "$invalid"

echo
echo "Testing if fetching block device is working..."
dfawk="$(df | awk '$NF == "/" {print $1}')"
mountpoint="$("$1" -b /)"
printf "df+awk: %s ${1}: %s\n" "$dfawk" "$mountpoint"
if test "$dfawk" == "$mountpoint"; then
	echo "OK"
else
	echo "NOT OK"
fi
