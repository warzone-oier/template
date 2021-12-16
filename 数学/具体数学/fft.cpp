#include"fftalgo.h"
int main(){
	eax[0]=1,eax[1]=mod-4,eax[2]=12,eax[3]=mod-16,eax[4]=8;
	ecx(16,eax);
	conv(16,ecx,ecx,eax);
	for(word i=0;i<16;++i){
		if(eax[i]>(mod>>1)) printf("-%d ",mod-eax[i]);
		else printf("%u ",eax[i]);
	}
		
	return 0;
}