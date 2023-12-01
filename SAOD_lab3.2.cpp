#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "List.h"

void get_num(int &b) {
	printf("enter vector num");
	scanf_s("%d", &b);
}
int main() {
	system("chcp 1251");
	List list[2];
	Data data;
	int b;
	int key, n, length = 0;
	Data tmp;
	bool flag = true;
	while (flag) {
		do {
			printf("1 - получение элемента по индексу \n\
2 - принадлежность элемента вектору \n\
3 - изменение элемента вектора \n\
4 - инициализация вектора \n\
5 - увеличить элемент на определенное значение \n\
6 - уменьшить элемент на определенное значение \n\
7 - умножить элемент на определенное значение\n\
8 - разделить элемент на определенное значение \n\
9 - определить нижнюю и верхнюю границу \n\
10 - размер вектора\n\
11 - очистка вектора \n\
12 - слить 2 вектора \n");
			scanf_s("%i", &key);
		} while (key < 1 or key > 12);
		switch (key) {

		case 1:
			get_num(b);
			printf("Введите номер элемента: ");
			scanf_s("%d", &n);
			tmp = Peek(list[b], n - 1);
			printf("%lf", tmp.n);
			break;
		case 2:
			get_num(b);
			printf("Введите значение вектора: ");
			scanf_s("%f", &data.n);
			if (check_Belong(&list[b], data)) {
				printf("Значение принадлежит вектору");
			}
			else
				printf("Значение не принадлежит вектору");
			break;
		case 3:
			get_num(b);
			printf("Введите индекс вектора: ");
			scanf_s("%d", &n);
			printf("Введите значение вектора: ");
			scanf_s("%f", &data.n);
			edit_Element(&list[b], n, data);
			break;
		case 4:
			get_num(b);
			printf("Введите индекс вектора: ");
			scanf_s("%d", &n);
			printf("Введите значение вектора: ");
			scanf_s("%f", &data.n);
			Push(list[b], n, data);
			break;
		case 5:
			get_num(b);
			printf("Введите значение: ");
			scanf_s("%f", &data.n);
			Plus(list[b], data);
			break;
		case 6:
			get_num(b);
			printf("Введите значение: ");
			scanf_s("%f", &data.n);
			Minus(list[b], data);
			break;
		case 7:
			get_num(b);
			printf("Введите значение: ");
			scanf_s("%f", &data.n);
			Multiplication(list[b], data);
			break;
		case 8:
			get_num(b);
			printf("Введите значение: ");
			scanf_s("%f", &data.n);
			Division(list[b], data);
			break;
		case 9:
			get_num(b);
			Min(list[b], data);
			printf("min = %f ", data.n);
			Max(list[b], data);
			printf("max = %f \n", data.n);
			break;
		case 10:
			get_num(b);
			printf("size = %d ", Size(list[b]));
			break;
		case 11:
			get_num(b);
			Clear(list[b]);
			break;
		case 12:
			link_vectors(list[0], list[1]);
			break;

		}
		Show_List(list[0]);
		Show_List(list[1]);
		printf("\n");
	}
}


//• получение элемента по индексу;
//• принадлежность элемента вектору
//• изменение элемента;
//• арифметические операции над векторами : поэлементное
//сложение, вычитание, умножение, деление;
//• операции определения нижней и верхней границ индекса;
//• размер вектора;
//• инициализация вектора и его очистка;
//• слияние векторов.