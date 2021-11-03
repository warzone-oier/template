#pragma once
#include"具体数学/fft.h"
#include"bigint.h"
static word eax[1<<mx],ebx[1<<mx];
template<word size>
bigint<size> bigint<size>::operator*(const bigint<size> &p)const{
	for(word i=0;i<size;++i){
		eax[i<<1]=  num[i]%10,eax[i<<1|1]=  num[i]/10;
		ebx[i<<1]=p.num[i]%10,ebx[i<<1|1]=p.num[i]/10;
	}
	fft(size<<1,eax,ebx,eax);
	bigint ans;
	ull out=0;
	for(word i=0;i<size;++i){
		out+=eax[i<<1|1]*10+eax[i<<1];
		ans.num[i]=out%100,out/=100;
	}
	return ans;
}