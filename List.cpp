#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "List.h"

void Plus(List& list, Data data)
{
	for (LE* l = list.head; l != NULL; l = l->next)
		l->data.n += data.n;
}

void Minus(List& list, Data data)
{
	for (LE* l = list.head; l != NULL; l = l->next)
		l->data.n -= data.n;

}

void Division(List& list, Data data)
{
	for (LE* l = list.head; l != NULL; l = l->next)
		l->data.n /= data.n;

}

void Multiplication(List& list, Data data)
{
	for (LE* l = list.head; l != NULL; l = l->next)
		l->data.n *= data.n;

}

void Min(List& list, Data& data)
{
	data.n = 10000000.0;
	
	for (LE* l = list.head; l != NULL; l = l->next)
		if(data.n<l->data.n)
		data.n=l->data.n;

}

void Max(List& list, Data& data)
{
	data.n = -10000000.0;

	for (LE* l = list.head; l != NULL; l = l->next)
		if (data.n > l->data.n)
			data.n = l->data.n;

}

int Size(List& list)
{
	int n = 0;
	for (LE* l = list.head; l != NULL; l = l->next, n++);
	return n;

}

void Show_List(List& list)
{
	if (!Is_Empty(list)) {
		for (LE* l = list.head; l != NULL; l = l->next) {
		
			printf("%.1lf ", l->data.n);
		}
		printf("\n");
	}

}

void Push(List& list, int index, Data data)
{
	LE* l = (LE*)malloc(sizeof(LE));
	l->data = data;
	l->next = NULL;
	if (list.head == NULL)
		list.head = l;
	else
	{
		LE* cur = list.head;
		for (int i = 1; i < index and cur->next != NULL; i++)
			cur = cur->next;
		if (index == 0)
		{
			l->next = list.head;
			list.head = l;
		}
		else
		{
			if (cur->next != NULL)
				l->next = cur->next;
			cur->next = l;
		}
	}
}


Data Peek(List& list, int index)
{
	LE* cur = list.head;
	for (int i = 0; i < index and cur->next != NULL; i++)
		cur = cur->next;
	if (cur != NULL)
		return cur->data;
	return Data({0});
}


bool check_Belong(List* list, Data n) {
	
	for (LE* cur = list->head; cur->next != NULL; cur = cur->next)
		if (cur->data.n == n.n)
			return 1;
	return 0;
}

void edit_Element(List* list, int n, Data data) {
	LE* cur = list->head;
	for (int i = 0; i < n and cur->next != NULL; i++)
		cur = cur->next;
	if (cur != NULL)
		cur->data = data;
}

void link_vectors(List& list1, List& list2) {

		for (LE* cur = list1.head; cur != NULL; cur = cur->next)
			if (cur->next == 0) {
				cur->next = list2.head;
				break;
			}
		list2.head = NULL;
	
}

bool Is_Empty(List& list)
{
	return list.head == NULL;
}

void Clear(List& list)
{
	while (not Is_Empty(list))
	{
		LE* cur = list.head;
		list.head = list.head->next;
		free(cur);
	}list.head = 0;
}