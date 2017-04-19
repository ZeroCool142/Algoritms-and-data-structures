#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node {
	int data;
	Node *next;
	Node *prev;
};

typedef struct {
	int count;
	Node *tail;
	Node *head;
} List;


Node* newNode(int value);

void add(List *l, int index, int value);
void addFirst(List *l, int value);
void addLast(List *l, int value);

List* arrayToList(int *arr, int count);
int* listToArray(List *l); 

int rm(List *l, int index);
int removeFirst(List *l);
int removeLast(List *l);
void clear(List *l);

int peek(List *l, int index);

void printList(List *l);
void printListRevers(List *l);
void initList(List *l);
void deleteList(List *l);

//////////    MAIN    ////////////
int main(void)
{	
	List list;
	initList(&list);

	int a[] = {11,22,33};

	List *lst = arrayToList(a, 3);
	printList(lst);

	int *ar = listToArray(lst);
	for (int i = 0; i < lst->count; ++i)
	{
		printf("->%d\n", ar[i]);
	}
	free(ar);

	for (int i = 0; i < 10; ++i) {
		addFirst(&list, i);
	}
	for (int i = 0; i < 10; ++i) {
		addLast(&list, i);
	}
	add(&list, 10, 99);
	printf("Value of removed element: %d\n", rm(&list, 21));
	printf("Value of element with index 2: %d\n", peek(&list, 2));
	printList(&list);

	deleteList(lst);
	deleteList(&list);
	return 0;
}


Node* newNode(int value) {
	Node *temp = malloc(sizeof(Node));
	temp->data = value;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

/////////     ADD      /////////////

void add(List *l, int index, int value) {
	if(index < 0 || index > l->count) {
		printf("Out of bound!\n");
		return;
	}
	if (index == 0) {
		addFirst(l, value);
		return;
	}
	if (index == l->count) {
		addLast(l, value);
		return;
	}

	Node *temp = newNode(value);
	Node *e;
	if(index > (l->count>>1)) {
		 e = l->tail;
		for (int i = 0; i < (l->count-index); ++i) {
			e = e->prev;
		}
	}
	else {
		e = l->head;
		for (int i = 0; i < index-1; ++i) {
			e = e->next;
		}

	}
	temp->next = e->next;
	temp->prev = e;
	e->next->prev = temp;
	e->next = temp;
	l->count++;
}
void addFirst(List *l, int value) {
	Node *temp = newNode(value);
	if(l->head == NULL) {
		l->head = temp;
		l->tail = temp;
		l->count++;
		return;
	}
	
	l->head->prev = temp;
	temp->next = l->head;
	l->head = temp;
	l->count++;
}
void addLast(List *l, int value) {
	Node *temp = newNode(value);
	if(l->tail == NULL){
		l->head = temp;
		l->tail = temp;
		l->count++;
		return;
	}
	
	l->tail->next = temp;
	temp->prev = l->tail;
	l->tail = temp;
	l->count++;
}


/////////    REMOVE   ///////////

int rm(List *l, int index) {
	if(index < 0 || index > l->count) {
		printf("Out of bound!\n");
		return 0;
	}
	if (index == 0) {
		return removeFirst(l);
	}
	if (index == l->count) {
		return removeLast(l);
	}

	Node *e;
	if(index > (l->count>>1)) {
		 e = l->tail;
		for (int i = 0; i < (l->count-index)-1; ++i) {
			e = e->prev;
		}
	}
	else {
		e = l->head;
		for (int i = 0; i < index; ++i) {
			e = e->next;
		}

	}
	e->next->prev = e->prev;
	e->prev->next = e->next;
	int value = e->data;
	free(e);
	l->count--;
	return value;
}
int removeFirst(List *l) {
	Node *temp = l->head;
	int value = l->head->data;
	l->head = l->head->next;
	l->head->prev = NULL;
	free(temp);
	l->count--;
	return value;
}
int removeLast(List *l) {
	Node *temp = l->tail;
	int value = l->tail->data;
	l->tail = l->tail->prev;
	l->tail->next = NULL;
	free(temp);
	l->count--;
	return value;
}



////////    UTILS     /////////

int peek(List *l, int index) {
	if(index == 0) {
		return l->head->data;
	}
	else if(index == l->count) {
		return l->head->data;
	}

	Node *e;
	if(index > (l->count>>1)) {
		 e = l->tail;
		for (int i = 0; i < (l->count-index)-1; ++i) {
			e = e->prev;
		}
	}
	else {
		e = l->head;
		for (int i = 0; i < index; ++i) {
			e = e->next;
		}

	}
	int value = e->data;
	return value;
}

void printList(List *l) {
	Node *current = l->head;
	while(current!=NULL) {
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}
void printListRevers(List *l) {
	Node *current = l->tail;
	while(current!=NULL) {
		printf("%d ", current->data);
		current = current->prev;
	}
	printf("\n");
}
void initList(List *l) {
	l->tail = NULL;
	l->head = NULL;
	l->count = 0;
}
void deleteList(List *l) {
	while(l->head!=NULL) {
		Node *current = l->head;
		l->head = current->next;
		free(current);
	}
}
List* arrayToList(int *arr, int count){
	List *l = malloc(sizeof(List));
	initList(l);
	for (int i = 0; i < count; ++i)
	{
		addLast(l, *(arr+i));
	}
	return l;
}
int* listToArray(List *l){
	int *arr = malloc(sizeof(int)*l->count);
	Node *current = l->head;
	for (int i = 0; i < l->count; ++i)
	{
		*(arr + i) = current->data;
		current = current->next;
	}
	return arr;
}
/* Output:
11 22 33
->11
->22
->33
Value of removed element: 9
Value of element with index 2: 7
9 8 7 6 5 4 3 2 1 0 99 0 1 2 3 4 5 6 7 8

*/