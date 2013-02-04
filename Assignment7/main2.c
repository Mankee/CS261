#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "toDoList.h"
#include "dynArray.h"
#include "skipList.h"

int main (int argc, const char * argv[])
{
	const long size = atoi(argv[1]);
  	TYPE *task = (TYPE*)malloc(sizeof(TYPE)*size*2);
	int *flip = (int*)malloc(sizeof(int)*size*2);
	DynArr mainList;
	long i;
	struct skipList skippy;
	printf("Enter\n");
	initDynArr(&mainList, 10000000);	/*Avoid effects of resizing*/
	initSkipList(&skippy);
	/* create tasks */
	for(i=0;i<size*2; i++)
	{
		task[i] = createTask(rand(), "r");
		flip[i] = rand()%2;
	}
	
		
	/* add tasks to the dynamic array */
	
	for(i=0;i<size; i++)
	{
		addHeap(&mainList, task[i]);
		addSkipList(&skippy, task[i]);
	}
	
	
	
	long start = clock();
	long finish = clock();
	
	long add = 0;
	long remove = 0;
	long cnt_add = 0;
	long cnt_remove = 0;
	long sadd = 0;
	long sremove = 0;
	long scnt_add = 0;
	long scnt_remove = 0;
	for(i=0;i<size*2; i++)
	{
		if(flip[i])
		{
			start = clock();
			addHeap(&mainList, task[i]);
			finish = clock();
			add += (finish-start);
			cnt_add++;
			start = clock();
			addSkipList(&skippy, task[i]);
			finish = clock();
			sadd += (finish-start);
			scnt_add++;
		}
		else
		{
			start = clock();
			removeMinHeap(&mainList);
			finish = clock();
			remove += (finish-start);
			cnt_remove++;
			start = clock();
			removeMinSkipList(&skippy);
			finish = clock();
			sremove += (finish-start);
			scnt_remove++;
		}
	}
	
	printf("Below are the average runtimes for a given number of operations.\n");
	printf("----HEAP----\n");
	printf("Adding %ld tasks took %lf clocks.\n", cnt_add, (double)(add) / (double)(cnt_add));
	printf("Removing %ld minimums took %lf clocks.\n", cnt_remove, (double)(remove) / (double)cnt_remove);
	printf("----SKIP LIST----\n");
	printf("Adding %ld tasks took %lf clocks.\n", scnt_add, (double)(sadd) / (double)(scnt_add));
	printf("Removing %ld minimums took %lf clocks.\n", scnt_remove, (double)(sremove) / (double)scnt_remove);

	

	return 0;
}
