#pragma once
#pragma once
#ifndef _LIST_H
#define _LIST_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


struct Data {
	float n = 0;

};

struct LE {
	Data data;
	LE* next = NULL;
};

struct List {
	LE* head = NULL;
};

void Plus(List& list, Data data);
void Minus(List& list, Data data);
void Multiplication(List& list, Data data);
void Division(List& list, Data data);
void Max(List& list, Data& data);
void Min(List& list, Data& data);
int Size(List& list);
void Show_List(List& list);
void Push(List& list, int index, Data data);
Data Peek(List& list, int index);
bool Is_Empty(List& list);
void Clear(List& list);
void link_vectors(List& list1, List& list2);
bool check_Belong(List* list, Data n);
void edit_Element(List* list, int n, Data data);

#endif
