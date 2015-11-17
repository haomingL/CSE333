// Haoming Liu
// 1332998
// haoming@uw.edu
#include <stdio.h>
#include <stdlib.h>

char * DumpHex(const void *pData, unsigned int byteLen) {
	int i;
	if (pData == NULL) 
		return NULL;
	char* p = (char *)pData;
	char* result = (char *)malloc(byteLen * 3);
	if (byteLen < 1)
		return result;
	sprintf(result, "%.2x", p[0] & 0xff);
	for (i = 1; i < byteLen; i++) {
		sprintf((result + i * 3 - 1), " %.2x", *(p + i) & 0xff);
	}
	*(result + byteLen * 3 - 1) = '\0';
	return result;
}
