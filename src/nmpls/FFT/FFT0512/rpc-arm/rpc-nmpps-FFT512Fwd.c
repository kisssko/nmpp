#include "fft.h"
#include "rpc-host.h"	

	void nmppsFFT512Fwd(const nm32sc* src, nm32sc* dst,const  NmppsFFTSpec* spec)
	{
		int ret;	
		int size=512;
		int k=8;
		struct aura_buffer *iobuf_src = aura_buffer_request(n, size*k);	
		struct aura_buffer *iobuf_dst = aura_buffer_request(n, size*k);	
		memcpy(iobuf_src->data,src,size*k);	
		struct aura_buffer *retbuf; 
		ret = aura_call(n, "nmppsFFT512Fwd", &retbuf,  iobuf_src, iobuf_dst, spec); 
		if (ret != 0) {
			slog(0, SLOG_ERROR, "call failed, reason: %d\n", ret);
			BUG(n, "Call nmppsFFT512Fwd failed!"); 
		}
		memcpy(dst,iobuf_dst->data,size*k);
		aura_buffer_release( iobuf_dst); 
		aura_buffer_release( iobuf_src); 
		aura_buffer_release( retbuf); 
		slog(3, SLOG_INFO, "ARM: Call nmppsFFT512Fwd -ok"); 
	
	}


	int nmppsFFT512FwdInitAlloc( NmppsFFTSpec** spec, const void* src, const void* dst,  int settings)
	{
		struct aura_buffer *iobuf_src = aura_buffer_request(n, 512*8);	
		struct aura_buffer *iobuf_dst = aura_buffer_request(n, 512*8);	
		struct aura_buffer *retbuf; 
		int ret =  aura_call(n, "nmppsFFT512FwdInitAlloc", &retbuf,  iobuf_src, iobuf_dst, settings); 
		if (ret != 0) {
			slog(0, SLOG_ERROR, "call failed, reason: %d\n", ret);
			BUG(n, "Call nmppsFFT512FwdInitAlloc failed!"); 
		}
		*spec = (NmppsFFTSpec*) aura_buffer_get_u32(retbuf);
		ret   = aura_buffer_get_u32(retbuf);
		aura_buffer_release( iobuf_src); 
		aura_buffer_release( iobuf_dst); 
		aura_buffer_release( retbuf); 
		slog(3, SLOG_INFO, "ARM: Call nmppsFFT512FwdInitAlloc -ok"); 
		return ret;
	}

