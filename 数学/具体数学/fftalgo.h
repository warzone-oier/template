#pragma once
#ifndef FFT_H
#ifndef NTT_H
#include"fft.h"
#endif
#endif
word in[1<<mx],eax[1<<mx],ebx[1<<mx];
fftreg ecx,edx;
#define newton(size_)    \
    word size=2;   		 \
    while(size<<=1,(size>>2)<(size_))
inline void _1(const word size_){
	ebx[0]=pow_(eax[0],mod-2);
	newton(size_){
		ecx(size,eax),edx(size,ebx);
		conv(size,ecx,edx,ebx);
		FOR(size) ebx[i]=(mod-ebx[i])%mod;
		ebx[0]=(2+ebx[0])%mod;
		ecx(size,ebx);
		conv(size,ecx,edx,ebx);
	}
}
inline void ln(const word size){
	_1(size),ecx(size<<1,ebx);
	FOR(size) ebx[i]=(1ull+i)*eax[i+1]%mod;
	edx(size<<1,ebx),conv(size<<1,ecx,edx,ebx);
	for(word i=size-1;i;--i)
		ebx[i]=pow_(i,mod-2)*ebx[i-1]%mod;
	ebx[0]=0;
}
inline void exp_(const word size_){
	eax[0]=1;
	newton(size_){
		ln(size>>1);
		FOR(size>>1) ebx[i]=(in[i]+mod-ebx[i])%mod;
		ebx[0]=(ebx[0]+1)%mod;
		ecx(size,eax),edx(size,ebx);
		conv(size,ecx,edx,eax);
	}
}