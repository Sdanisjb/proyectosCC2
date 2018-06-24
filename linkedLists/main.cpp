#include<iostream>
#include "linked_list.h"
using namespace std;


int main (){
	list listaPar;
	for(int i=0;i<=10;i+=2){
		listaPar.insert_element(i);
	}
	listaPar.print();
	
	list listaImpar;
	for(int i=1;i<=9;i+=2){
		listaImpar.insert_element(i);
	}
	
	listaImpar.print();
	
	merge_sort(listaPar,listaImpar);
	return 0;
}

