#include <stdio.h>
#include <stdlib.h>

char * DumpHex(const void *pData, unsigned int byteLen) {
	int i;
	char* p = (char *)pData;
	char* result = (char *)malloc(byteLen * 3);
	sprintf(result, "%x", p[0]);
	for (i = 1; i < byteLen; i++) {
		sprintf((result + i * 3 - 1), " %x", *(p + i));
	}
	return result;
}

int main(int argc, const char *argv[]) {
	char* p = DumpHex("example", 3);
	printf("%s\n", p);
	free(p);
}