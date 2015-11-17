#ifndef DUMPHEX_H
#define DUMPHEX_H

// Allocates a buffer and fills it an ASCII representing
// the hex values of byteLen bytes starting at *pData.
// (The caller is responsible for free'ing th buffer.)
char* DumpHex(const void *pData, unsigned int byteLen);

#endif // DUMPHEX_H
