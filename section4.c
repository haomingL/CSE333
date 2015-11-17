#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	int i;
	int fd = open("foo.rtf", O_RDONLY);
	int sz;

	sz = 350;

	printf("%d\n", sz);

	if (fd == -1) {
		perror("open failed");
		return -1;
	}

	char *buf = (char*)malloc(sz);
	int bytes_left = sz;
	int result = 0;

	while (bytes_left > 0) {
		result = read(fd, buf + (sz - bytes_left), bytes_left);
		if (result == -1) {
			if (errno != EINTR) {
				return -1;
			}
			continue;
		}
		bytes_left -= result;
	}

	for (i = 0; i < (sz - bytes_left); i++) {
		printf("%c", *(buf + i));
	}

	printf("\n");

	close(fd);
}