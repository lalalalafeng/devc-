#include "array.h"
#include <stdio.h>
#include <stdlib.h>

//typedef struct {
//	int *array;
//	int size;
//} Array;

Array array_create(int init_size)
{
	Array a;
	a.size = init_size;
	a.array = (int*) malloc(sizeof(int)*a.size);
	return a;
 } 
void array_free(Array *a)
{
	free(a->array);
	a->array = NULL;
	a->size = 0;
}

//  封装 ; 
int array_size(const Array *a)
{
	return a->size;
}

//  可以直接  用函数调用来给main中赋值 		*array_at(&a, 0); 
int* array_at(Array *a, int index)
{
	return &(a->array[index]);
}
void array_inflate(Array *a, int more_size)
{
	int *p = (int*)malloc(sizeof(int)*(a->size+more_size));
	int i;
	for(i=0; i<a->size; i++)		//将前面的数组移到下一个增大的数组中 
	{
		p[i] = a->array[i];			//推荐使用  库函数  memcpy 来 复制数组 
	}
	free(a->array);
	a->array = p;
	a->size += more_size;
}

int main(void)
{
	Array a = array_create(100);

	array_free(&a); 
	return 0;
}

