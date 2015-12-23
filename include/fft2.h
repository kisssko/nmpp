//***************************************************************************/
//*                     RC Module Inc., Moscow, Russia                      */
//*                     NeuroMatrix(r) NM6403 Software                      */
//*                                                                         */
//*   Fast Fourie Transform Library                                         */
//*  (C-callable functions)                                                 */
//*                                                                         */
//*  $Workfile:: sFFT.h                                                    $*/
//*  Contents:         Header file of FFT routines                          */
//*                                                                         */
//*                                                                         */
//*  Author:     S.Mushkaev                                                 */
//*                                                                         */
//*  Version         1.0                                                    */
//*  Start    Date:  03.07.2001                                             */
//*  Release $Date: 2005/07/13 14:19:56 $									*/
//*                                                                         */
//*                                                                         */
//***************************************************************************/

// LIBRARY  nmfft.lib



#ifndef _SFFT2_H_INCLUDED_
#define _SFFT2_H_INCLUDED_


#include "nmtype.h"


/*! \mainpage �������� 
 *
 * \htmlinclude intro.html 
 * \section intro_sec Introduction
 *
 * This is the introduction.
 *
 * \section install_sec Installation
 *
 * \subsection step1 Step 1: Opening the box
 *  
 * etc...
 
 */



//*****************************************************************************


	
	/**
	*
    * \if Russian
    *     \defgroup sFFT ������� �������������� �����
    * \endif
    * \if English
    *     \defgroup sFFT Fast Fourier Transform
    * \endif
    * 
	*/



//*****************************************************************************


/*
#ifndef _NMCMPLX_H_INCLUDED_
	struct nm32sc
	{
		int re;//Real;
		int im;//Imag;
		nm32sc():
			re(0),im(0){}; //Real(0),Imag(0){}
		nm32sc(int _Real,int _Imag):
			re(_Real),im(_Imag){};//Real(_Real),Imag(_Imag){}
	};
#endif //_NMCMPLX_H_INCLUDED_
*/
//#include "nmpp.h"

///////////////////////////////////////////////////////////////////////////////////
// The functions listed below are forward and inversed FFT routines for 
// 256,512,1024 or 2048-point compex data, represented as arrays of nm32sc type. 
// Each complex number is stored in 64-bit word.
// The lower  32-bits is real part of complex number.
// The higher 32-bits is imaginary part of complex number;
// The admissible input range of data depends on dimension of array, 
// mode of calculation accuracy and on/off mode of intermediate and final scaling down (shift normalization) of results.
// This range guarantee against overflow during calculation process. 
// The table of ranges you may find in "FFT Library Programmer's manual"
//
// The mode of calculation accuracy tells how sine-cosine coeffecients are represented if fixed-point format.
// When the 7-bit accuracy mode is used, output shape accuracy approaches of the maximum,
// but output is reduced by around 2%. 
// If the 6-bit accuracy mode is used, then output range corresponds to result of Fourie transform 
// based on floating-point arithmetic, but output is less precise.
// The mode of calulation accuracy may be set or switched by appropriate ***Set6bit() or ***Set7bit() function
// NOTE: At least on time the accuracy setting function must be called before FFT routine executing.
#include "malloc32.h"

#ifdef __cplusplus
		extern "C" {
#endif
//=============================  Forward FFT 256 =====================================

	
#include "time.h"
#include "malloc32.h"
	


	typedef struct {
		
		int shift[4];
		int round[4];
		void* fftTable[2];
		void* buffer[4];
		Free32Func* free;
		//NmppsAllocation allocOrder;
	} NmppsFFTSpec;

	
	
	
//	int  nmppsFFT256FwdInitAlloc(Malloc32Func* allocate,  Free32Func* free, NmppsFFTSpec* spec);
//	void nmppsFFT256Fwd(nm32sc* src, nm32sc* dst, NmppsFFTSpec* spec);
//	void nmppsFFTFree(NmppsFFTSpec* spec );
//	
//	int  nmppsFFT256FwdInitCustomAlloc(Malloc32Func* allocate,  Free32Func* free, NmppsFFTSpec* spec);
//	void nmppsFFT256FwdOptimize(void* src, void* dst, uint64* allocOrder);
	
	

#ifdef __NM__
#define sizeof32(t) sizeof(t)
#else
#define sizeof32(t) (sizeof(t)*4)
#endif
	
	#define NMPP_OPTIMIZE_DISABLE  1 
	#define NMPP_NORMALIZE_DISABLE 2
	#define NMPP_FFT_6BIT 4
	#define NMPP_FFT_7BIT 0
	#define NMPP_OK 0
	#define NMPP_ERROR -1

	void nmppsFFTFree(NmppsFFTSpec* spec );
	
	void nmppsFFT256Fwd(nm32sc* src, nm32sc* dst, NmppsFFTSpec* spec);
	int  nmppsFFT256FwdOptimize(void* src, void* dst, fseq64* allocOrder) ;
	int  nmppsFFT256FwdInitAlloc( NmppsFFTSpec** spec, void* src, void* dst,  int settings);
	int  nmppsFFT256FwdInitAllocCustom(  NmppsFFTSpec** specFFT, Malloc32Func* allocate, Free32Func* free, int settings);
	
	void nmppsFFT256Inv(nm32sc* src, nm32sc* dst, NmppsFFTSpec* spec);
	int  nmppsFFT256InvOptimize  (void* src, void* dst, fseq64* allocOrder) ;
	int  nmppsFFT256InvInitAlloc (NmppsFFTSpec** spec, void* src, void* dst,  int settings);
	int  nmppsFFT256InvInitAllocCustom(  NmppsFFTSpec** specFFT, Malloc32Func* allocate, Free32Func* free,  int settings);
	
	void nmppsFFT512Fwd(nm32sc* src, nm32sc* dst, NmppsFFTSpec* spec);
	int  nmppsFFT512FwdOptimize(void* src, void* dst, fseq64* allocOrder) ;
	int  nmppsFFT512FwdInitAlloc( NmppsFFTSpec** spec, void* src, void* dst,  int settings);
	int  nmppsFFT512FwdInitAllocCustom(  NmppsFFTSpec** specFFT, Malloc32Func* allocate, Free32Func* free, int settings);

	void nmppsFFT512Inv(nm32sc* src, nm32sc* dst, NmppsFFTSpec* spec);
	int  nmppsFFT512InvOptimize  (void* src, void* dst, fseq64* allocOrder) ;
	int  nmppsFFT512InvInitAlloc (NmppsFFTSpec** spec, void* src, void* dst,  int settings);
	int  nmppsFFT512InvInitAllocCustom(  NmppsFFTSpec** specFFT, Malloc32Func* allocate, Free32Func* free,  int settings);
	
	void nmppsFFT1024Fwd(nm32sc* src, nm32sc* dst, NmppsFFTSpec* spec);
	int  nmppsFFT1024FwdOptimize(void* src, void* dst, fseq64* allocOrder) ;
	int  nmppsFFT1024FwdInitAlloc( NmppsFFTSpec** spec, void* src, void* dst,  int settings);
	int  nmppsFFT1024FwdInitAllocCustom(  NmppsFFTSpec** specFFT, Malloc32Func* allocate, Free32Func* free, int settings);

	void nmppsFFT1024Inv(nm32sc* src, nm32sc* dst, NmppsFFTSpec* spec);
	int  nmppsFFT1024InvOptimize  (void* src, void* dst, fseq64* allocOrder) ;
	int  nmppsFFT1024InvInitAlloc (NmppsFFTSpec** spec, void* src, void* dst,  int settings);
	int  nmppsFFT1024InvInitAllocCustom(  NmppsFFTSpec** specFFT, Malloc32Func* allocate, Free32Func* free,  int settings);
	
	void nmppsFFT2048Fwd(nm32sc* src, nm32sc* dst, NmppsFFTSpec* spec);
	int  nmppsFFT2048FwdOptimize(void* src, void* dst, fseq64* allocOrder) ;
	int  nmppsFFT2048FwdInitAlloc( NmppsFFTSpec** spec, void* src, void* dst,  int settings);
	int  nmppsFFT2048FwdInitAllocCustom(  NmppsFFTSpec** specFFT, Malloc32Func* allocate, Free32Func* free, int settings);

	void nmppsFFT2048Inv(nm32sc* src, nm32sc* dst, NmppsFFTSpec* spec);
	int  nmppsFFT2048InvOptimize  (void* src, void* dst, fseq64* allocOrder) ;
	int  nmppsFFT2048InvInitAlloc (NmppsFFTSpec** spec, void* src, void* dst,  int settings);
	int  nmppsFFT2048InvInitAllocCustom(  NmppsFFTSpec** specFFT, Malloc32Func* allocate, Free32Func* free,  int settings);
	


#ifdef __cplusplus
		};
#endif

#endif 
		