#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct list
{
	int info;
	struct list* next;
};

struct list* New()
{
	list* temp;
	temp = (list*)malloc(sizeof(list));
	temp->info = 0;
	temp->next = NULL;
	return temp;
}

struct list* AddFirst(list* head, int value)
{
	list* temp = New();
	temp->info = value;
	temp->next = head;
	return temp;
}

struct list* AddLast(list* head, int value)
{
	list* temp = New();
	list* p = head;
	while (p->next != NULL)
		p = p->next;
	p->next = temp;
	temp->info = value;
	temp->next = NULL;
	return head;
}

int AddNext(list* head, int value, int data)
{
	list* p = head;
	while (p->info != value && p->next != 0)
		p = p->next;
	if (p->next == NULL)
		return 0;
	list* temp = New();
	temp->info = data;
	temp->next = p->next;
	p->next = temp;
	return 1;
}

void Delete(list** head, int n) {
	list* v = *head;
	if (v != NULL) {
		while (v->info > n) {
			*head = v->next;
			free(v);
			v = *head;
			if (v == NULL) return;
		}

		list* last_v = NULL;
		while (v != NULL) {
			if ((v->info) > n) {
				last_v->next = v->next;
				free(v);
				v = last_v;
			}
			last_v = v;
			v = v->next;
		}
	}
}

int count(list* head) {
	int c = 0;
	while (head) {
		c++;
		head = head->next;
	}
	return(c);
}

void printlist(list* head) {
	struct list* p = head;
	while (p != NULL) {
		printf("%5d ", p->info);
		p = p->next;
	}
}

void reverseprintlist(list* head) {
	int c = count(head);
	while (c > 0) {
		struct list* p = head;
		for (int i = 0; i < (c - 1); ++i) {
			p = p->next;
		}
		printf("%5d ", p->info);
		c--;
	}
}


void swap(list* head) {
	struct list* p1 = head;
	while(p1->next != NULL) {
		p1 = p1->next;
	}
	int tinfo = head->info;
	head->info = p1->info;
	p1->info = tinfo;
}

int poisk(list* head, int n) {
	struct list* p = head;
	int c = 1;
	while (c != n) {
		p = p->next;
		c++;
	}
	return p->info;
}

void deletehead(list** head) {
	struct list* p = *head;
	*head = p->next;
	free(p);
}

int main() {
	setlocale(LC_ALL, "Rus");
	int val, i, t, c, h;
	struct list* head = NULL;
	int exit = 1;
	val = 0;
	while (exit == 1) {
		printf("\nМЕНЮ\n\n");
		printf("1. Добавить запись в начало\n");
		printf("2. Добавить запись на n позицию\n");
		printf("3. Добавить запись в конец\n");
		printf("4. Подсчёт числа элементов в списке\n");
		printf("5. Печать списка (в прямом порядке)\n");
		printf("6. Печать списка (в обратном порядке)\n");
		printf("7. Удалить записи > n\n");
		printf("8. Выйти из программы\n");
		printf("9. Поменять первый и последний элемент спсика\n");
		printf("10. Возвращаем n элемент списка\n");
		printf("11. Удалить голову\n");
		int n;
		printf("Введите номер операции: \n");
		scanf("%d", &n);
		switch (n) {
		case 1:
			printf("\nВведите значение нового элемента: ");
			scanf("%d", &t);
			if (val == 0) {
				head = New();
				head->info = t;
				val++;
			}
			else {
				head = AddFirst(head, t);
			}
			break;
		case 2:
			printf("\nВведите значение элемента после которого будет добавлен новый: ");
			scanf("%d", &t);
			printf("\nВведите значение нового элемента: ");
			scanf("%d", &i);
			h = AddNext(head, t, i);
			if (h == 0) {
				printf("\nЭлемент не добавлен");
			}
			if (h == 1) {
				printf("\nЭлемент добавлен");
			}
			break;
		case 3:
			printf("\nВведите значение нового элемента: ");
			scanf("%d", &t);
			if (val == 0) {
				head = New();
				head->info = t;
				val++;
			}
			else {
				head = AddLast(head, t);
			}
			break;
		case 4:
			printf("\nКол-во элементов в списке: ");
			c = count(head);
			printf("%d", c);
			break;
		case 5:
			printf("\nЭлементы списка: ");
			printlist(head);
			break;
		case 6:
			printf("\nЭлементы списка: ");
			reverseprintlist(head);
			break;
		case 7:
			printf("\nВведите значение, больше которого нужно удалить элементы: \n");
			scanf("%d", &t);
			Delete(&head, t);
			break;
		case 8:
			exit = 0;
			break;
		case 9:
			swap(head);
			break;
		case 10:
			printf("\nВведите значение n: ");
			scanf("%d", &i);
			t = poisk(head, i);
			printf("\nЗначение n блока: %d ", t);
			break;
		case 11:
			deletehead(&head);
			printf("\nГолова удалена ");
			break;
		default:
			printf("Неправильный ввод.\n");
		}
	}
	return 0;
}