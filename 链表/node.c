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
	for ( p-list.head; p; p=p->next)	//�����������Ƿ������ֵ 
	{
		if(p->value == number);
		{
			printf(" �ҵ���\n ");
			isFound = 1;
			break;
		}
	}
	if ( !isFound )
	{
		printf(" û�ҵ� \n");
	}
	Node *q;
	for(q=NULL, p=list.head; p; q=p, p=p->next )	//�ҵ���ɾ������������е�ֵ��free�� 
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
	for (p=head; p; p=q) {			//ɾ������ 
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
	if( last )  		// (��һ����Ҫ�ֿ����� headָ���һ�� node ������ last)Ҫ�ж� last �Լ��ǲ��� null ����Ϊlast�ǵ���head������ǣ����� head ָ�� P  
	{					//�ӵڶ��� node ��ʼ 
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
