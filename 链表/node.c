#include "node.h"
#include <stdio.h>
#include <stdlib.h>

//typedef struct _node  {
//	int value;
//	struct _node *next;
//} Node;

typedef struct _list {
	Node *head;
} List;

void add (List *head, int number);
void print(List *plist);

int main(void)
{
	List list;
	int number;
	list.head = NULL;
	do{
		scanf("%d", &number);
		if(number != -1)
		{	
			add(&list, number);
		}
	}while (number != -1);
	Node *p;
	int isFound = 0;
	for ( p-list.head; p; p=p->next)	//查找链表中是否有这个值 
	{
		if(p->value == number);
		{
			printf(" 找到了\n ");
			isFound = 1;
			break;
		}
	}
	if ( !isFound )
	{
		printf(" 没找到 \n");
	}
	Node *q;
	for(q=NULL, p=list.head; p; q=p, p=p->next )	//找到就删除这个再链表中的值（free） 
	{
		if(p->value == number)
		{
			if( q ) 
			{
				q->next = p->next;
			
			} else {
				list.head = p->next;
			}
			free(p);
			break;
		}
	}
	for (p=head; p; p=q) {			//删除链表 
		q = p->next;
		free(p);
	}
	return 0;
} 

void add (List *head, int number)
{
	//add to licked-list
	Node *p  = (Node*)malloc(sizeof(Node));
	p->value = number;
	p->next  = NULL;
	
	//find the last
	Node *last = head;
	if( last )  		// (第一个是要分开，让 head指向第一个 node 而不是 last)要判断 last 自己是不是 null （因为last是等于head）如果是，就让 head 指向 P  
	{					//从第二个 node 开始 
		while( last->next )  //if last->next != NULL
		{
			last = last->next;
		}
		//attach
		last->next = p;
	} else {
		head = p;
	}
}

void print(List *pList)
{
	Node *p;
	for( p=pList->head; p; p = p->next)
	{
		printf("%d\t", p->value);
	}
	printf("\n");
}
