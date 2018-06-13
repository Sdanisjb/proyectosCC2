#include <iostream>

using namespace std;

void insertValues(int lista[],int numE){
	for(int i=0;i<numE;i++){
		int n;
		cin>>n;
		lista[i]=n;
	}
}

void printList(int lista[], int numE){
    for(int i=0;i<numE;i++){
        cout<<lista[i]<<" ";
    }
    cout<<endl;
}

void swapValues(int*a,int*b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

void ascendingCS(int lista[], int numE){
    bool ordenado = false;
    int* inicio = lista;
    int* fin = lista+numE;

    while(!ordenado){
        ordenado = true;
        for(int*i=inicio;i<fin-1;i++){
            if(*i>*(i+1)){
                swapValues(i,i+1);
                printList(lista,numE);
                ordenado=false;
            }
        }

        for(int*i=fin-1;i>inicio;i--){
            if(*i<*(i-1)){
                swapValues(i,i-1);
                printList(lista,numE);
                ordenado=false;
            }
        }
        inicio++;
        fin--;
    }


    printList(lista,numE);

}

void descendingCS(int lista[],int numE){
    bool ordenado = false;
    int* inicio = lista;
    int* fin = lista+numE;

    while(!ordenado){
        ordenado = true;
        for(int*i=inicio;i<fin-1;i++){
            if(*i<*(i+1)){
                swapValues(i,i+1);
                printList(lista,numE);
                ordenado=false;
            }
        }

        for(int*i=fin-1;i>inicio;i--){
            if(*i>*(i-1)){;
                swapValues(i,i-1);
                printList(lista,numE);
                ordenado=false;
            }
        }
        inicio++;
        fin--;
    }
}

void run(int lista[], int numE){
	insertValues(lista,numE);
	cout<<"Ascendente(0) o Descendiente(1)?"<<endl;
	int tipo;
	cin>>tipo;
	if(tipo==0){
		ascendingCS(lista,numE);
	}
	else{
		descendingCS(lista,numE);
	}
	printList(lista,numE);
}

int main()
{
    int numE;
    cin>>numE;
    int lista[numE];
    run(lista,numE);

    return 0;
}
