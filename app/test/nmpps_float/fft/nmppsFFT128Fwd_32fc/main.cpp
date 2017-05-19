#include <math.h>
#include <malloc.h>
#include "time.h"
#include "fft_32fc.h"
#include "nmpp.h"
#include <stdio.h>

int main()
{
	int i, tm;
	nm32fcr *src, *dst;
	// best config (tm - 1208, src - malloc, dst - malloc1)
	src = (nm32fcr *)malloc(128 * sizeof(nm32fcr));
	dst = (nm32fcr *)malloc(128 * sizeof(nm32fcr));
	for(i = 0; i < 128; i++) {
		src[i].im = 0;
		src[i].re = i;
		dst[i].im = 0;
		dst[i].re = 0;
	}
	NmppsFFTSpec_32fc *rat;
	tm = nmppsFFT256FwdInitAlloc_32fc(&rat);
	if(tm < 0) {
		return 123;
	}
	nmppsFFT256Fwd_32fc(src, dst, rat);
	tm = nmppsFFTFree_32fc(rat);
	unsigned int crc = 0;
	nmppsCrcAcc_32f((nm32f *)dst, 13, 128*2, &crc);
	return crc>>2;
}