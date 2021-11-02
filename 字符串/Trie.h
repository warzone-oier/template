#ifndef TRIE_H
#define TRIE_H
#include"../queue.h"
template<word size_,byte sum>
struct Trie{
	word next[size_][sum];
	word fail[size_],floor[size_];
	word size,last;
	inline Trie(){
		memset(next,0,sizeof(next));
		fail[0]=0xffffffff;
		floor[0]=size=last=0;
	}
	inline void operator >>(byte c){
		last=next[last][c];}
	inline void operator +=(byte c){
		if(next[last][c]==0){
			next[last][c]=++size;
			floor[size]=floor[last]+1;
		}
		last=next[last][c];
	}
	inline void operator()(){
		queue<word,size_> q;
		fail[0]=0;
		for(register word i=0;i<sum;++i)
			if(next[0][i]) fail[next[0][i]]=0,q.push(next[0][i]);
		for(register word id;!q.empty();){
			id=q.top(),q.pop();
			for(register word i=0,*pnext,pfail;i<sum;++i){
				pnext=next[id]+i,pfail=next[fail[id]][i];
				if(*pnext) fail[*pnext]=pfail,q.push(*pnext);
				else *pnext=pfail;
			}
		}
	}
};
#endif