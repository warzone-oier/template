#ifndef PAM_H
#define PAM_H
#include"../template.h"
template<word size_,byte sum>
struct PAM{
	word next[size_][sum];
	int floor[size_],fail[size_],top;
	byte s[size_];
	word last,size;
	inline PAM(){
		 fail[0]=1, fail[1]=-1;
		floor[0]=0,floor[1]=-1;
		last=0,size=1;
		s[top=0]=255;
	}
	inline void operator >>(byte c){
		last=next[last][c];}
	inline void operator+=(byte c){
		s[top+1]=c;
		while(s[top-floor[last]]!=c) last=fail[last];
		if(next[last][c]) return last=next[last][c],void(++top);
		next[last][c]=++size;
		floor[size]=floor[last]+2;
		if(last==1) fail[size]=0;
		else{
			while(last=fail[last],s[top-floor[last]]!=c);
			fail[size]=next[last][c];
		}
		return last=size,void(++top);
	}
};
#endif