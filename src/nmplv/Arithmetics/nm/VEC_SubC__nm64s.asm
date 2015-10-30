//------------------------------------------------------------------------
//
//  $Workfile:: SubVN.as $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:03 $
//
//! \if file_doc
//!
//! \file   SubVN.asm
//! \author ������ �������
//! \brief  ������� ��������� ��� ��������.
//!
//! \endif
//!
//------------------------------------------------------------------------

extern vec_data_sub_ram:label;
extern _nmppsTmpBuffer16_G_:long;

begin ".text_nmplv"


/////////////////////////////////////////////////////////////////////////////////////////
//! \fn void nmppsSubC (nm64s *pSrcVec, int64b *pnVal, nm64s *pDstVec, int nSize) 
//!
//! \perfinclude _nmppsSubC__FPlPlPli.html

global _void._.8.8nmppsSubC.1long._.0.9._long._.0.9._long._.0.9._int.2 :label;
<_void._.8.8nmppsSubC.1long._.0.9._long._.0.9._long._.0.9._int.2>
.branch;
	ar5 = sp - 2	with gr7=false;
	push ar0,gr0	with gr7++;
	push ar1,gr1	with gr7++;
	push ar5,gr5	with gr0=gr7;
	push ar6,gr6	with gr6=gr7;
	ar0 = [--ar5];						// pSrcVec
	ar1 = [--ar5];						// SrcN
	ar6 = [--ar5];						// pDstVec
	gr5 = [--ar5];						// nSize
	
	nb1 = 00000000h;
	wtw;
	delayed call vec_data_sub_ram 	with gr5;		// nSize in 64-bit longs
		nul;
		nul;
		
	pop ar6,gr6;
	pop ar5,gr5;
	pop ar1,gr1;
	pop ar0,gr0;
return;
.wait;


end ".text_nmplv";
