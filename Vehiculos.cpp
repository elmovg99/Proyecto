//Actividad Integradora

#include <iostream>
#include <stdlib.h>

using namespace std;

class Vehiculo{
	public:
		int numLlantas;
		int capacidad;
		string motor;
	public:
		Vehiculo(){
			numLlantas=0;
			capacidad=0;
			motor="x";
		}
		void setnumLlantas(int a){
			numLlantas=a;
		}
		void setcapacidad(int b){
			capacidad=b;
		}
		void setmotor(string c){
			motor=c;
		}
		int getnumLlantas(){
			return numLlantas;
		}
		int getcapacidad(){
			return capacidad;
		}
		string getmotor(){
			return motor;
		}
};

class Carro: public Vehiculo{
	public:
		string modelo;
		string marca;
	public:
		Carro(){
			numLlantas=0;
			capacidad=0;
			motor="x";
			modelo="x";
			marca="x";
		}
		void setmodelo(string d){
			modelo=d;
		}
		void setmarca(string e){
			marca=e;
		}
		string getmodelo(){
			return modelo;
		}
		string getmarca(){
			return marca;
		}
};

class Nodo:public Vehiculo{
	public:
		Nodo *sig;
		Nodo *ant;
		Carro *datos;
		Nodo(){
			this->sig=NULL;
			this->datos=NULL;
		}
		Nodo(Carro *c){
			this->sig=NULL;
			this->datos=c;
		}
		int getnumLlantas(Nodo *lista){
			return lista->datos->numLlantas;
		}
		int getcapacidad(Nodo *lista){
			return lista->datos->capacidad;
		}
		string getmotor(Nodo *lista){
			return lista->datos->motor;
		}
		string getmarca(Nodo *lista){
			return lista->datos->marca;
		}
		string getmodelo(Nodo *lista){
			return lista->datos->modelo;
		}
};

class Lista{
	private:
		Nodo *lista;
	public:
		Lista(){
			lista=NULL;
		}
		public: void agregarNodo(Carro *c){
			Nodo *nuevo = new Nodo(c);
			if(lista==NULL){
				lista=nuevo;
			}
			else{
				Nodo *aux=new Nodo();
				Nodo *ant= new Nodo();
				aux=lista;
				while(aux->sig!=NULL){
					ant=aux;
					aux = aux->sig;
				}
				aux->sig=nuevo;
				nuevo->ant=aux;
			}
		}
			
		void recorrerLista(){
			if(lista==NULL)
				cout<<"Lista vacia"<<endl;
			else{
				Nodo *aux = new Nodo();
				aux=lista;
				while(aux!=NULL){
					cout<<endl<<"Marca: "<<aux->getmarca(aux)<<endl;
					cout<<"Modelo: "<<aux->getmodelo(aux)<<endl;
					cout<<"Capacidad de pasajeros: "<<aux->getcapacidad(aux)<<endl;
					cout<<"Motor: "<<aux->getmotor(aux)<<endl;
					cout<<"Numero de llantas: "<<aux->getnumLlantas(aux)<<endl;
					cout<<endl;
					aux=aux->sig;
				}
			}
		}
	public: void eliminarNodo(int x){
		Nodo *aux=lista;
		Nodo *ant=NULL;
		while((aux!=NULL)&&(aux->getNum()!=x)){
			ant=aux;
			aux=aux->sig;
		}
		if(aux!=NULL){
			if(ant!=NULL){
				ant->sig=aux->sig;
				aux->sig->ant=aux->ant;
			}
			else
				lista=aux->sig;
			free(aux);
			cout<<"Nodo eliminado"<<endl<<endl;
		}
		else
			cout<<"El valor no esta en la lista"<<endl<<endl;
	}
	public: void buscarValor(int x){
		Nodo *aux = new Nodo();
		int editar=0;
		aux=lista;
		while(aux!=NULL&&aux->getNum()!=x)
			aux=aux->sig;
		if(aux==NULL)
			cout<<endl<<"El valor no esta en la lista"<<endl<<endl;
		else{
			cout<<endl<<"	Valor encontrado"<<endl<<endl;
			cout<<"Modifica valor?(Si=1, No=0)\nOpcion: "; 
			cin>>editar;
			cout<<endl;
			if(editar==1){
				cout<<"Nuevo valor: ";
				cin>>x;
				cout<<endl;
				aux->setNum(x);
			}
		}
	}
};

void registrar(Carro *);

int main(){
	int opcion;
	Carro *carro = new Carro();
	Lista *list = new Lista();
	do{
		cout<<"1)Agregar\n2)Recorrer\n3)Editar\n4)Eliminar\n5)Ordenar\n6)Salir\n\nOpcion: ";
		cin>>opcion;
		switch(opcion){
			case 1:
				registrar(carro);
				list->agregarNodo(carro);
				break;
			case 2:
				list->recorrerLista();
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				cout<<endl<<"Saliste del programa"<<endl;
				break;
		}
	}while(opcion!=6);		
}

void registrar(Carro *c){
	string a, b, f;
	int d, e;
	cout<<endl<<"Introduce la marca del vehiculo: ";
	fflush(stdin);getline(cin,a);
	c->setmarca(a);
	cout<<endl<<"Introduce el modelo del vehiculo: ";
	fflush(stdin);getline(cin, b);
	c->setmodelo(b);
	cout<<endl<<"Introduce el motor del vehiculo: ";
	fflush(stdin);getline(cin, f);
	c->setmotor(f);
	cout<<endl<<"Introduce la capacidad de pasajeros del vehiculo: ";
	cin>>e;
	c->setcapacidad(e);
	cout<<endl<<"Introduce el numero de llantas del vehiculo: ";
	cin>>d;
	c->setnumLlantas(d);
	cout<<endl<<endl;
}


