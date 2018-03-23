#include <nmtype.h>
#include <malloc.h>
#include <stdio.h>
#include "fft_32fcr.h"
#include "nmpp.h"

int main()
{
	int i, tm;
	nm32fcr *src, *dst;
	// best config (tm = 592, src - malloc, dst - malloc1)
	src = (nm32fcr *)malloc(128 * sizeof(nm32fcr));
	dst = (nm32fcr *)malloc(128 * sizeof(nm32fcr));
	for(i = 0; i < 128; i++) {
		src[i].im = 1;
		src[i].re = i;
		dst[i].im = 0;
		dst[i].re = 0;
	}
	NmppsFFTSpec_32fcr *rat, *irat;
	tm = nmppsFFT128FwdInitAlloc_32fcr(&rat);
	if(tm) {
		return 123;
	}
	tm = nmppsFFT128InvInitAlloc_32fcr(&irat);
	if(tm) {
		return 124;
	}
	nmppsFFT128Fwd_32fcr(src, dst, rat);
	nmppsFFT128Inv_32fcr(dst, dst, irat);
	tm = nmppsFFTFree_32fcr(rat);
	if(tm) {
		return 125;
	}
	unsigned int crc = 0;
	nmppsCrcAcc_32f((nm32f *)dst, 11, 128*2, &crc);
	tm = nmppsFFTFree_32fcr(irat);
	if(tm) {
		return 126;
	}
	for(i = 0; i < 128; i++){
		printf("%.5f %.5f\n", dst[i].re, dst[i].im);
	}
	return crc >> 2;
}