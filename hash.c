#include <stdio.h>
#include <math.h>

// map the input +/- to each data structure
// Stack: 
#define PLUS insert
#define MINUS delete
#define HASEARCH hasearch
// Queue:
//#define PLUS  enqueue
//#define MINUS dequeue
// Linked List:
//#define PLUS  insert
//#define MINUS delete
// uncomment the appropriate lines above


// define your push/pop, enqueue/dequeue, or insert/delete 
// 	and an appropriate print_datastructure function here



int thehash[32] = {0};

int probe(int k, int i){
	return (divide(k) + i * multiply(k)) % 32;
}

int multiply(int k){
	int hk;
	float ka;
	float A = ((sqrt(5) - 1) / 2);
	ka = A * k;
	hk = (int)(A * k);
	ka = ka - hk;
	hk = 16 * ka;
	return hk;
}

int divide(int k){
	return(k % 10);
}

void insert(int key){
	int i;
	for(i=0;i<32;i++){
		if( thehash[probe(key,i)] <= 0 ){
			thehash[probe(key,i)] = key;
			printf("Successfully inserted '%d'. (proof: thehash[%d] == %d)\n", key, probe(key,i), thehash[probe(key,i)]);
			return;
		}
	}
	printf("No available spots for '%d'\n.", key);
}

int delete(int key){
	int found;
	found = hasearch(key);
	if( found >= 0 ){
		thehash[found] = -1;
		printf("Deleted.\n");
	}
}

int hasearch(int key){
	int i;
	for(i=0;i<32;i++){
		if (thehash[probe(key,i)] == key){
			printf("Key '%d' found at [%d].\n", key, probe(key,i));
			return probe(key,i);
		}else if(thehash[probe(key,i)] == 0){
			printf("Item '%d' not found. (case: reached an empty)\n", key);
			return -1;
		}
	}
	printf("Item '%d' not found. (case: full loop)\n", key);
	return -1;
}

void print_datastructure(){
	int i;
	for(i = 0; i<32 ; i++){
		printf("%d, ", thehash[i]); 
	}
	printf("\n");
}
// end definitions


// Leave this alone:
#include "datastruct.h"
int main()
{
	parse_exec();
	print_datastructure();
}