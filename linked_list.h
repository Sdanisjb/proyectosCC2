#ifndef LINKED_LIST_H
#define LINKED_LIST_H

class node{
public:
	int value;
	node* next;
	node();
	node(int);
};

class list{
	node* head;
public:
	list();
	void insert_element(int);
	void delete_element(int);
	void delete_all();
	void print();
};

class clist{
	node* head;
public:
	clist();
	void insert_element(int);
	void delete_element(int);
	void delete_all();
	void print();
};

#endif
