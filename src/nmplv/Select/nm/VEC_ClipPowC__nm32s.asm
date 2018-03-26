//------------------------------------------------------------------------
//
//  $Workfile:: Clip.as $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:09 $
//
//! \if file_doc
//!
//! \file   Clip.asm
//! \author ������ �������
//! \brief  ������� ��������� � ������������ ���������� ��������� �������
//!         ��� ��������� �����.
//!
//! \endif
//!
//------------------------------------------------------------------------
//#include "vClip.h"

extern vec_activate_data_add_0:label;
extern tbl_f1cr_nm32:long[32];

begin ".text_nmplv"


/////////////////////////////////////////////////////////////////////////////////


//! \fn void nmppsClipPowC_32s(nm32s *pSrcVec, int nClipFactor, nm32s *pDstVec, int nSize) 
//!
//! \perfinclude _nmppsClipPowC_32s.html

global _nmppsClipPowC_32s:label;
<_nmppsClipPowC_32s>
.branch;

	ar5=ar7-2;
	push ar0,gr0	with gr7=false;
	push ar5,gr5	with gr7++;
	push ar6,gr6	with gr7++;
	
	ar0 = [--ar5] with gr0=gr7;	//Src	
	gr6 = [--ar5];							//ClipIndex
	ar6 = tbl_f1cr_nm32	with gr6<<=1;		
	f1cr= [ar6+=gr6];
	ar6 = [--ar5] with gr6=gr7;	//Dst
	delayed call vec_activate_data_add_0;
		gr5 = [--ar5];							//Size
		with gr5>>=1;

	pop ar6,gr6;
	pop ar5,gr5;
	pop ar0,gr0;

	return;
.wait;



end ".text_nmplv";
