#ifndef PAM_H
#define PAM_H
#include<map>
#include"../template.h"
template<word size_,typename type>
struct PAM{
	std::map<type,word> next[size_];
	int floor[size_],fail[size_],top;
	type s[size_];
	word last,size;
	inline PAM(){
		 fail[0]=1, fail[1]=-1;
		floor[0]=0,floor[1]=-1;
		last=0,size=1;
		s[top=0]=0xffffffffffffffff;
	}
	inline void operator >>(const type &c){
		auto ite=next[last].find(c);
		if(ite==next[last].end()) last=0;
		else last=ite->second;
	}
	inline void operator+=(const type &c){
		s[top+1]=c;
		while(s[top-floor[last]]!=c) last=fail[last];
		auto ite=next[last].find(c);
		if(ite!=next[last].end())
			return last=ite->second,void(++top);
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