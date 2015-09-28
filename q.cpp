#include<iostream>
#include<stdio.h>
#include<cstddef>

using namespace std;
#define TCB_t int

struct node{
	node* next;
	node* prev;
	TCB_t data;
} *HEAD , *end_p;

static int n_element;

void InitQ(node* Q)
{
	//Q = new node();
	HEAD = Q;
	
	Q->data = 0;
	Q->next = NULL;
	Q->prev = NULL;
	end_p = HEAD;
	n_element = 0;
	//end_p = HEAD;
}

void ADDQ(node* Q, TCB_t* data)
{
	if (n_element == 0) {
		HEAD->data = *data;
		HEAD->next = end_p;
		HEAD->prev = end_p;
		end_p->prev = HEAD;
		end_p->next = HEAD;
	}
	else{
		node * temp = new node();
		temp->data = *data;
		temp->prev = HEAD;
		temp->next = end_p;
		HEAD->next = temp;
		HEAD = temp;
		end_p->prev = HEAD;
	}
	// Q is Head
	n_element++;
}

void print_q(node* Q)
{
	if (n_element == 0)
	{
		cout << "\nPrinting Empty Queue. return";
		return;
	}
	bool ret = false;
	do{
		if (Q == end_p)
		{
			cout << Q->data << "\n";
			ret = true;
		}
		else{
			cout << Q->data << "\n";
			Q = Q-> prev;
		}
	} while (ret != true);
}

node* DelQ(node* Q)
{
	if (n_element == 0)
	{
		cout << "Delete in Empty Queue!";
		return NULL;
	}
	Q = HEAD;
	node* temp = new node();
	temp->data = Q->data;
	temp->next = NULL;
	temp->prev = NULL;
	HEAD = HEAD->prev;
	HEAD->next = end_p;
	n_element--;
	return temp;
}

int main()
{
	node * q = new node();
	InitQ(q);
	int data = 10;
	ADDQ(HEAD, &data);
	data = 15;
	//ADDQ(HEAD, &data);
	data = 20;
	//ADDQ(HEAD, &data);
	cout << "\n The content of the queue: ";
	print_q(HEAD);
	node * n = DelQ(HEAD);
	if (n != NULL){
		cout << "\n Deleted item ";
		cout << n->data;
	}
	cout << "\n The content of the queue: ";
	print_q(HEAD);
	//_getch();
}
