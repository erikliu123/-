#include<vector>
#include<algorithm>
#include<iostream>
//#include <pthread.h> 线程安全的时候用到
using namespace std;

class MemoryChunk;
struct MemoryBlock;

struct BlockHeader{
	MemoryChunk* pChunk;
	size_t len;
};
struct BlockData{
	union{
		MemoryBlock* pNext;
		char pBuffer;
	};
};
struct MemoryBlock{
	BlockHeader header;
	BlockData data;
};
 
class MemoryChunk{
public:
	MemoryChunk(size_t size, int count)
	{
		//pthread_mutex_init(&hMutex,NULL);
		this->pFreeList=nullptr;
		this->size=size;
		this->count=0;
		MemoryBlock* pBlock;
		while(count--){
			pBlock=CreateBlock();
			if(!pBlock)break;
			pBlock->data.pNext=pFreeList;
			pFreeList=pBlock;
		}
	}
	char* malloc()
	{
		MemoryBlock* pBlock;
		//pthread_mutex_lock(&hMutex);
		if(pFreeList){
			pBlock=pFreeList;
			pFreeList=pBlock->data.pNext;
			count--;
		}
		else{
			if(!(pBlock=CreateBlock())){
				//pthread_mutex_unlock(&hMutex);
				return NULL;
			}
		}
		//pthread_mutex_unlock(&hMutex);
		return &pBlock->data.pBuffer;
	}
	static void free(void* pMem)
	{
		MemoryBlock* pBlock=(MemoryBlock*)((char*)pMem-sizeof(BlockHeader));
		pBlock->header.pChunk->free(pBlock);
	}
	void free(MemoryBlock* pBlock)
	{
		//pthread_mutex_lock(&hMutex);
		if(pBlock==pFreeList)
			return;
		pBlock->data.pNext=pFreeList;
		pFreeList=pBlock;
		count++;
		//pthread_mutex_unlock(&hMutex);
	}
	MemoryChunk* Next(){return pNext;}
	MemoryBlock* CreateBlock()
	{
		MemoryBlock* pBlock=(MemoryBlock*)::malloc(sizeof(BlockHeader)+size);
		if(pBlock){
			pBlock->header.pChunk=this;
			pBlock->header.len=size;
			++count;
		}
		return pBlock;
	}
private:
	MemoryBlock* pFreeList;
	size_t size;    //Block大小
	int count;      //Block数目
	MemoryChunk* pNext;//MemoryChunk
	//pthread_mutex_t hMutex;
};

struct HeapHeader{
	size_t size;
};
struct MemoryHeap{
	size_t size;
	char pBuffer;
};
 
class StaticMemory{
public:
	StaticMemory(){
        NumofBlocks=20;
		chunkcount=16;
		pChunkList.resize(16,nullptr);
		int index=0;
		for(size_t size=8; size<=128; size+=8)
			pChunkList[index++]=new MemoryChunk(size,NumofBlocks);
	}
    int freelist_index(size_t n){
        return (n+7)/8-1;
    }
	char* Malloc(size_t size)
	{
		if(size>128)
			return malloc(size);
		int index=freelist_index(size);
		return pChunkList[index]->malloc();
	}
	void Free(void* pMem)
	{
		if(!(free(pMem)))
			MemoryChunk::free(pMem);    
	}
	char* malloc(size_t size)
	{
		MemoryHeap* pHeap=(MemoryHeap*)::malloc(sizeof(HeapHeader)+size);
		if(pHeap){
			pHeap->size=size;
			return &(pHeap->pBuffer);
		}
		return nullptr;
	}
	bool free(void* pMem)
	{
		MemoryHeap* pHeap=(MemoryHeap*)((char*)pMem-sizeof(HeapHeader));
		if(pHeap->size>128){
			::free(pHeap);
			return true;
		}
		return false;
	}
private:
    vector<MemoryChunk*> pChunkList;
    vector<int> chunklistSize={8,16,24,32,40,48,56,64,72,80,88,96,104,112,120,128};  //16个大小容量
    int NumofBlocks;
	int chunkcount;
};
int main()
{
	StaticMemory* tm=new StaticMemory();
	char* temp=tm->Malloc(8);
	MemoryBlock* pBlock=(MemoryBlock*)((char*)temp-sizeof(BlockHeader));
	cout<<"allocation space:"<<pBlock->header.len<<endl;
	char* temp1=tm->Malloc(8);
	tm->Free(temp);
	tm->Free(temp1);
	return 0;
}
