//------------------------------------------------------------------------
//
//  $Workfile:: Init.as $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:08 $
//
//! \if file_doc
//!
//! \file   Init.asm
//! \author ������ �������
//! \brief  ������� ������������� � ����������� ��� ��������.
//!
//! \endif
//!
//------------------------------------------------------------------------

//#include "vMinMax.h"

extern vec_ram:label;

extern _nmppsTmpBuffer16_G_:long;

begin ".text_nmplv"

	

////////////////////////////////////////////////////////////////////////////

    //--------------------------------------------------------------------
    //! \fn void nmppsFill_16s(nm16s *pVec, int16b nVal, int nSize)
	//!
	//! \perfinclude _nmppsFill__FPSsii_.html
    //--------------------------------------------------------------------

global _nmppsFill__FPSsii_:label;
global _void._.8.8nmppsFill_.1short._.0.9._int.9._int.2 :label;
<_nmppsFill__FPSsii_>
<_void._.8.8nmppsFill_.1short._.0.9._int.9._int.2>
.branch;
    ar5 = sp - 2	with gr7=false;
    push ar0,gr0	with gr7++;
	push ar5,gr5	with gr7++;
	push ar6,gr6	with gr6=gr7;

    ar6 = [--ar5];			// Buffer
	gr0 = [--ar5];			// Init value
    gr5 = [--ar5];			// nSize
	ar0 = _nmppsTmpBuffer16_G_+2 with	gr7 = gr0 << 16;
	gr0 = gr7 >> 16;
	gr0 = gr7 or gr0;

	delayed call vec_ram with gr5 >>=2;
		[--ar0] = gr0;
		[--ar0] = gr0;

	pop ar6,gr6;
	pop ar5,gr5;
	pop ar0,gr0;
	return;
.wait;

		


end ".text_nmplv";