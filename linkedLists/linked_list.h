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
public:
	node* head;
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
	void josephus(int,int);
};

void merge_sort(list,list);


#endif
