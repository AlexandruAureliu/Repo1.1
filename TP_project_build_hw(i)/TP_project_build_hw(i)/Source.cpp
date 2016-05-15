#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <ctime>

#define COOP 50

typedef struct node
{
	char key[5];
	int numero;
	float hidden;
	node * next;
	node * prev;
};

//void menu();
//void game();

void create_list(node ** head);

int main()
{
	node *circuit;
	circuit = (node*)malloc(sizeof(node));
	create_list(&circuit);

	node * head = circuit;
	do {
		printf("%d\n", head->numero);
		
		head = head->next;

	} while (head != circuit);
	return 0;
}

void create_list(node ** head)
{
	node * proto;
	node * ult;
//	proto = (node*)malloc(sizeof(node));
	proto = *head;
	ult = proto;

	srand(time(NULL));

	proto->hidden = 0.0;
	proto->numero = 0;
	char nno = 0;
	for (int i = 0; i < 5; i++) {
		proto->key[i] = nno^i;
	}
	bool vlf[100];
	vlf[0] = true;
	for (int i = 1; i < COOP; i++) { vlf[i] = false; }
	

	for (int i = 1; i < COOP; i++) {
		node * port;
		port = (node*)malloc(sizeof(node));

		int val = rand() % COOP;
		while (vlf[val] == true)	// || (vlf[val] == false && (i < val ? i - val : val - i) <= 3)) 
		{
			val = rand() % COOP;
		}
		
		port->numero = val;
		port->hidden = 0.0;
		port->next = NULL;
		port->prev = ult;
		ult->next = port;

		vlf[val] = true;
		ult = port;

		printf("\t%p\n", ult);

	}
	ult->next = proto;
	proto->prev = ult;
	head = &proto;
//	printf("\t%p\n", proto);
}