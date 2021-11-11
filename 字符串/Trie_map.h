#ifndef TRIE_H
#define TRIE_H
#include<map>
#include"../template.h"
template<word size_,typename type>
struct Trie{
	std::map<type,word> next[size_];
	word floor[size_];
	word size,last;
	inline Trie(){
		memset(next,0,sizeof(next));
		floor[0]=size=last=0;
	}
	inline void operator >>(const type &c){
		auto ite=next[last].find(c);
		if(ite==next[last].end()) last=0;
		else last=ite->second;
	}
	inline void operator +=(byte c){
		if(next[last][c]==0){
			next[last][c]=++size;
			floor[size]=floor[last]+1;
		}
		last=next[last][c];
	}
};
#endif