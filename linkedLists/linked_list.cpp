#include "linked_list.h"
#include <iostream>


//Lista enlazada simple
//constructor con valores
node::node(int valor){
	value = valor;
	next = NULL;
}

//constructor padron
node::node(){
	value = 0;
	next = NULL;
}

//constructor de la lista
list::list(){
	head = NULL;
}

//insercion de elementos
void list::insert_element(int elemento){
	//Creamos el nodo a insertar
	node* temp = new node(elemento);
	//Variables auxiliares para la inserción en el medio
	node* prev = new node;
	node* actual = new node;
	//Si no hay elementos en la lista inserta
	//al comienzo
	if(head==NULL){
		head = temp;
		temp = NULL;
		return;
	}		
	else{
		actual = head;
		//inserción del elemento en la posición adecuada
		while(actual!=NULL){			
			//insercion antes del head
			if(actual->value == elemento){
				delete temp;				
				return;
			}
			if(elemento < head->value){
				head = temp;
				temp->next = actual;				
				temp = NULL;
				return;
			}
			//insercion en el medio
			else if((prev->value < elemento) && (elemento<actual->value)){
				prev->next = temp;
				temp->next = actual;
				temp = NULL;
				return;
			}			
			prev = actual;
			actual = actual->next;
		}
		//Salida del bucle e inserción al final
		prev->next=temp;
		temp = NULL;
		return;
	}
}

//borrado de elementos
void list::delete_element(int elemento){
	//nodo temporal
	node* actual = new node;
	actual = head;
	//variables auxiliares
	node* prev = new node;
	prev = head;
	while(actual!=NULL){
		if(actual->value==elemento){
			if(actual==head){
				head=head->next;
			}
			prev->next = actual->next;
			delete actual;			
			return;
		}
		prev = actual;
		actual = actual->next;
	}
	std::cout<<"No se encontro el elemento"<<std::endl;
	
}

//Funcion que borra toda la lista
void list::delete_all(){
	node* temp = new node;
	temp = head;
	node*temp2= new node;
	temp2=head->next;
	while(temp2!=NULL){
		delete temp;
		temp = temp2;
		temp2 = temp2->next;		
	}
	head = NULL;
	print();
}

//Funcion que imprime la lista
void list::print(){
	node* temp = new node;
	temp = head;
	while(temp!=NULL){
		std::cout<<temp->value<<"\t";
		temp = temp->next;
	}
	std::cout<<std::endl;
}


//Lista enlazada circular
clist::clist(){
	head = NULL;
}

//insertar elementoa
void clist::insert_element(int elemento){
	//Creamos el nodo a insertar
	node* temp = new node(elemento);
	//Variables auxiliares para la inserción en el medio
	node* prev = new node;
	node* actual = new node;	
	actual = head;
	prev = NULL;
	//Si no hay elementos en la lista inserta
	//al comienzo
	if(head==NULL){
		head = temp;
		temp->next = head;
		temp = NULL;		
	}
	//insercion antes del head
	
	//otras inserciones
	else{
		while(actual->next!=head){
			if(actual->value==elemento){
				delete temp;
				return;
			}
			else if(prev->value<elemento && elemento<actual->value){
				prev->next=temp;
				temp->next=actual;
				temp = NULL;
				return;
			}
			prev=actual;
			actual=actual->next;
		}
		//insercion al final de la lista
		actual->next=temp;
		temp->next=head;		
		if(elemento<head->value){
			head=temp;
		}
		temp = NULL;
	}
}

//inmprimir la lista
void clist::print(){
	node* temp = head;
	if(head==NULL)return;
	while(temp->next!=head){
		std::cout<<temp->value<<"\t";
		temp = temp->next;
	}
	std::cout<<temp->value<<"\t";
	std::cout<<std::endl;
}
