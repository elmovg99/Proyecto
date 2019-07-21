//Actividad Integradora

#include <iostream>
#include <stdlib.h>
#include "string.h"
#include "conio.h"
#include "stdio.h"

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
		Carro *sig;
		Carro *ant;
		Carro():Vehiculo(){
			this->numLlantas=0;
			this->capacidad=0;
			this->motor="x";
			this->modelo="x";
			this->marca="x";
			this->sig=NULL;
			this->ant=NULL;
		}
		void setmodelo(string d){
			this->modelo=d;
		}
		void setmarca(string e){
			this->marca=e;
		}
		string getmodelo(){
			return this->modelo;
		}
		string getmarca(){
			return this->marca;
		}
};

void registrar(Carro *);
void mostrar(Carro *);

class Lista{
	private:
		Carro *lista;
	public:
		Lista(){
			lista=NULL;
		}
		public: void agregarCarro(){
			Carro *nuevo = new Carro();
			registrar(nuevo);
			if(lista==NULL){
				lista=nuevo;
			}
			else{
				Carro *aux=new Carro();
				Carro *ant= new Carro();
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
			char ind;
			if(lista==NULL)
				cout<<"  Lista vacia"<<endl;
			else{
				Carro *aux = new Carro();
				aux=lista;
				do{
					system("cls");
					cout << "  A-Para atras"<< endl;
					cout << "  D-Para delante"<< endl;
					cout << "  S-Salir/Seleccionar"<< endl << endl;
					mostrar(aux);
					ind=getche();
					aux=(((ind=='a'||ind=='A')&&aux->ant!=NULL)?aux->ant:((ind=='d'||ind=='D')&&aux->sig!=NULL)?aux->sig:aux);
				}while(ind != 'S' && ind != 's');
			}
		}
		
//	public: void eliminarNodo(int x){
//		Nodo *aux=lista;
//		Nodo *ant=NULL;
//		while((aux!=NULL)&&(aux->getNum()!=x)){
//			ant=aux;
//			aux=aux->sig;
//		}
//		if(aux!=NULL){
//			if(ant!=NULL){
//				ant->sig=aux->sig;
//				aux->sig->ant=aux->ant;
//			}
//			else
//				lista=aux->sig;
//			free(aux);
//			cout<<"Nodo eliminado"<<endl<<endl;
//		}
//		else
//			cout<<"El valor no esta en la lista"<<endl<<endl;
//	}
//	public: void buscarValor(int x){
//		Nodo *aux = new Nodo();
//		int editar=0;
//		aux=lista;
//		while(aux!=NULL&&aux->getNum()!=x)
//			aux=aux->sig;
//		if(aux==NULL)
//			cout<<endl<<"El valor no esta en la lista"<<endl<<endl;
//		else{
//			cout<<endl<<"	Valor encontrado"<<endl<<endl;
//			cout<<"Modifica valor?(Si=1, No=0)\nOpcion: "; 
//			cin>>editar;
//			cout<<endl;
//			if(editar==1){
//				cout<<"Nuevo valor: ";
//				cin>>x;
//				cout<<endl;
//				aux->setNum(x);
//			}
//		}
//	}
};

void registrar(Carro *);

int main(){
	int opcion;
	Lista *list = new Lista();
	do{
		system("cls");
		cout<<"  1)Agregar\n  2)Recorrer\n  3)Editar\n  4)Eliminar\n  5)Ordenar\n  6)Salir\n\n  Opcion: ";
		cin>>opcion;
		system("cls");
		switch(opcion){
			case 1:
				list->agregarCarro();
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
				cout<<endl<<"  Saliste del programa"<<endl;
				break;
		}
	}while(opcion!=6);		
}

void registrar(Carro *c){
	string a, b, f;
	int d, e;
	cout<<endl<<"  Introduce la marca del vehiculo: ";
	fflush(stdin);getline(cin,a);
	c->setmarca(a);
	cout<<endl<<"  Introduce el modelo del vehiculo: ";
	fflush(stdin);getline(cin, b);
	c->setmodelo(b);
	cout<<endl<<"  Introduce el motor del vehiculo: ";
	fflush(stdin);getline(cin, f);
	c->setmotor(f);
	cout<<endl<<"  Introduce la capacidad de pasajeros del vehiculo: ";
	cin>>e;
	c->setcapacidad(e);
	cout<<endl<<"  Introduce el numero de llantas del vehiculo: ";
	cin>>d;
	c->setnumLlantas(d);
	cout<<endl<<endl;
}

void mostrar(Carro *aux){
			cout<<endl<<"  Marca: "<<aux->getmarca()<<endl;
			cout<<"  Modelo: "<<aux->getmodelo()<<endl;
			cout<<"  Capacidad de pasajeros: "<<aux->getcapacidad()<<endl;
			cout<<"  Motor: "<<aux->getmotor()<<endl;
			cout<<"  Numero de llantas: "<<aux->getnumLlantas()<<endl;
			cout<<endl;
		}

