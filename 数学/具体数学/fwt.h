#pragma once
#include"fftdef.h"
#define _and(num) [&](){									\
	const word num1=(num)[head|i];							\
	(num)[head|i]=(num1+(num)[head|i|floor])%mod;}()
#define and_(num) [&](){									\
	const word num1=(num)[head|i];							\
	(num)[head|i]=(num1+mod-(num)[head|i|floor])%mod;}()
#define _or(num) [&](){										\
	const word num2=(num)[head|i|floor];					\
	(num)[head|i|floor]=(num2+(num)[head|i])%mod;}()
#define or_(num) [&](){										\
	const word num2=(num)[head|i|floor];					\
	(num)[head|i|floor]=(num2+mod-(num)[head|i])%mod;}()
#define _xor(num) [&](){						\
		const word num1=(num)[head|i];			\
		const word num2=(num)[head|i|floor];	\
		(num)[head|i]=(num1+mod-num2)%mod;		\
		(num)[head|i|floor]=(num1+num2)%mod;}()
#define xor_(num) _xor(num)