//------------------------------------------------------------------------
//
//  $Workfile:: Add.cpp    $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:15 $
//
//! \if file_doc
//!
//! \file   Remap.cpp
//! \author ������ �������
//! \brief  �������������� ������� 
//!
//! \endif
//!
//------------------------------------------------------------------------
#include "nmpp.h"


/////////////////////////////////////////////////////////////////////////////////////////
// Summation of two char vectors
void nmppsAdd_8s(
		nm8s*			pSrcVec1,		// input buffer		:long Local [VecSize/8]
		nm8s*			pSrcVec2,		// input buffer		:long Local [VecSize/8]
		nm8s*			pDstVec,			// output buffer	:long Global[VecSize/8]
		int				nSize			// size of input buffer in 8 bit elements. nSize=[0,8,16,24...]
		)
{
	int i;
	for (i=0; i<nSize; i++)
		pDstVec[i] = pSrcVec1[i] + pSrcVec2[i];

}

/////////////////////////////////////////////////////////////////////////////////////////
// Summation of two short vectors
void nmppsAdd_16s(
		nm16s*			pSrcVec1,		// input buffer		:long Local [VecSize/4]
		nm16s*			pSrcVec2,		// input buffer		:long Local [VecSize/4]
		nm16s*			pDstVec,			// output buffer	:long Global[VecSize/4]
		int				nSize			// size of input buffer in 16-bit elements. nSize=[0,4,8,12..]
		)
{
	int i;
	for (i=0; i<nSize; i++)
		pDstVec[i] = pSrcVec1[i] + pSrcVec2[i];

}

/////////////////////////////////////////////////////////////////////////////////////////
// Summation of two int vectors
void nmppsAdd_32s(
		nm32s*			pSrcVec1,		// input buffer		:long Local [VecSize/2]
		nm32s*			pSrcVec2,		// input buffer		:long Local [VecSize/2]
		nm32s*			pDstVec,			// output buffer	:long Global[VecSize/2]
		int				nSize			// size of input buffer in 32-bit elements. nSize=[0,2,4,6...]
		)
{
	int i;
	while(1);
	for (i=0; i<nSize; i++)
		pDstVec[i] = pSrcVec1[i] + pSrcVec2[i];

}

/////////////////////////////////////////////////////////////////////////////////////////
// Summation of two long vectors
void nmppsAdd_64s(
		nm64s*		pSrcVec1,		// input buffer		:long Local [nSize]
		nm64s*		pSrcVec2,		// input buffer		:long Local [nSize]
		nm64s*		pDstVec,			// output buffer	:long Global[nSize]
		int				nSize			// size of input buffer in 64-bit elements. nSize=[0,1,2,3...]
		)
{
	int i;
	for (i=0; i<nSize; i++)
		pDstVec[i] = pSrcVec1[i] + pSrcVec2[i];

}


/////////////////////////////////////////////////////////////////////////////////////////
// Summation of two long complex vectors
void nmppsAdd_64sc(nm64sc *pSrcVec1, nm64sc *pSrcVec2, nm64sc *pDstVec, int nSize)
{
	int i;
	for(i=0;i<nSize;i++)
	{
		pDstVec[i].re = pSrcVec1[i].re + pSrcVec2[i].re;
		pDstVec[i].im = pSrcVec1[i].im + pSrcVec2[i].im;
	}
}

