int nmppsMinPosV25_(int* pSrcVec,int nStride,int& nPos)
{
	int Min=pSrcVec[0];
	nPos=0;
	int Cur;
	int Tmp;
	int j=nStride;
	for(int i=1;i<25;i++,j+=nStride)
	{
		Cur=pSrcVec[j];
		if ((Tmp=Cur-Min)<0)
		{
			Min=Cur;
			nPos=i;
		}
	}
	return Min;
}

