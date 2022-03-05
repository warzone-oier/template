#include"template.h"
inline byte popcntb(byte num){
	num=(num&0x55)+((num>>1)&0x55);
	num=(num&0x33)+((num>>2)&0x33);
	return num%15;
}
inline byte popcnth(hword num){
	num=(num&0x5555)+((num>>1)&0x5555);
	num=(num&0x3333)+((num>>2)&0x3333);
	num=(num&0x0f0f)+((num>>4)&0x0f0f);
	return num%255;
}
inline byte popcnt(word num){
	num=(num&0x5555'5555)+((num>>1)&0x5555'5555);
	num=(num&0x3333'3333)+((num>>2)&0x3333'3333);
	num=(num&0x0f0f'0f0f)+((num>>4)&0x0f0f'0f0f);
	return num%255;
}
inline ull popcntll(ull num){
	num=(num&0x5555'5555'5555'5555)+((num>>1)&0x5555'5555'5555'5555);
	num=(num&0x3333'3333'3333'3333)+((num>>2)&0x3333'3333'3333'3333);
	num=(num&0x0f0f'0f0f'0f0f'0f0f)+((num>>4)&0x0f0f'0f0f'0f0f'0f0f);
	//类似蝴蝶变换分组
	return num%255;
	//8 位值域 [0,255] 满足要求，计算循环卷积
}