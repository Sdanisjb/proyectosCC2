#include<iostream>
#include "linked_list.h"
using namespace std;

int main (){
	clist  miLista;
	miLista.insert_element(5);
	miLista.print();
	miLista.insert_element(2);
	miLista.print();
	miLista.insert_element(3);
	miLista.print();
	return 0;
}

