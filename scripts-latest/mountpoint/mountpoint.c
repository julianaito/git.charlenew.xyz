/* mountpoint: Check if a directory or file is a mounpoint, OpenBSD-compatible
 * version of util-linux's mountpoint
 * Released under the term of the Unlicense, see <http://unlicense.org/>
 */

#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mount.h>

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void usage(void);

int
main(int argc, char **argv) {
	int i, ch, nmntfs;
	int show_blockdev, quiet;
	struct statfs *mntfs;
	struct stat sb;
	
	show_blockdev = 0;
	quiet = 0;

	while ((ch = getopt(argc, argv, "bhq")) != -1) {
		switch (ch) {
		case 'b':
			show_blockdev = 1;
			break;
		case 'q':
			quiet = 1;
			break;
		case 'h':
		default:
			usage();
		}
	}
	argc -= optind;
	argv += optind;
	if (argc != 1)
		usage();

	/* bail out asap if the mountpoint is non-existent */
	if (stat(argv[0], &sb) == -1) {
		if (!quiet) {
			fprintf(stderr, "%s: ", getprogname());
			perror(argv[0]);
		}
		exit(EXIT_FAILURE);
	}

	nmntfs = getmntinfo(&mntfs, MNT_NOWAIT);
	for (i = 0; i < nmntfs; i++) {
		if (strcmp(argv[0], mntfs[i].f_mntonname) == 0) {
			if (!quiet && show_blockdev)
				puts(mntfs[i].f_mntfromname);
			else if (!quiet)
				printf("%s is a valid mountpoint.\n",
					argv[0]);
			exit(EXIT_SUCCESS);
		}
	}

	if (!quiet)
		fprintf(stderr, "%s: %s is not a valid mountpoint.\n",
			getprogname(), argv[0]);
	exit(EXIT_FAILURE);
}

void
usage(void) {
	fprintf(stderr,
		"usage: %s [-q] [-h|-b] possible_mountpoint\n",
		getprogname());
	exit(EXIT_FAILURE);
}

