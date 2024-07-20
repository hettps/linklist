#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}linklist;

int i,n;

//��������
linklist* creat_list(int arr[],int n) {
	//����ͷ���
	linklist* head = NULL;
	head = (linklist*)malloc(sizeof(linklist));
	if (head == NULL)
		exit(1);
	head->next = NULL;
	//β�巨����ڵ�
	linklist* p = head;
	for (i = 0; i < n; i++) {
		linklist* tmp=(linklist*)malloc(sizeof(linklist));
		tmp->data = arr[i];
		p->next = tmp;
		p = p->next;
	}
	p->next = NULL;
	return head;
	}

//ɾ������
void list_delet(linklist* L,int data) {
	if (L == NULL)
		exit(1);
	linklist* p = L;
	for (; p->next; p=p->next) {
		if (p->next->data == data)
			break;
	}
	if (p->next == NULL)
		exit(1);
	linklist* tmp = p->next;
	p->next = tmp->next;
	free(tmp);
}


//��ӡ����
void print_list(linklist* L) {
	if (L == NULL)
		exit (1);
	L = L->next;
	for (i = 0; i < n; i++) {
		printf("%d  ", L->data);
		L = L->next;
	}
	printf("\n");
}

int main()
{
	int arr[20];
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	linklist* L = creat_list(arr,n);
	print_list(L);
	list_delet(L,5);
	print_list(L);
	return 0;
}