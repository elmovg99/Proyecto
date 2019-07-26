//Actividad Integradora

#include <iostream>
#include <stdlib.h>
#include "string.h"
#include "conio.h"
#include "stdio.h"
#include<fstream>

using namespace std;
class Vehiculo{
	protected:
		int numLlantas;
		int capacidad;
		string motor;
	public:
		Vehiculo(){
			numLlantas=0;
			capacidad=0;
			motor="N";
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
	private:
		string modelo;
		string marca;
		 
	public:         
		Carro *sig;                                                                                                                             
		Carro *ant;
		Carro():Vehiculo(){
			this->numLlantas=0;
			this->capacidad=0;
			this->motor="N";
			this->modelo="N";
			this->marca="N";
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

class Lista{
	private:
		Carro *lista;//Creación de objeto por asociar
		Carro *lista2;
	public:
		Lista(){
			this->lista=NULL;
			this->lista2=NULL;
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
		Carro* recorrerLista(){
			char ind;
			if(lista==NULL){
				cout<<"  Lista vacia"<<endl;
				getch();
				}
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
				return aux;
			}
			return NULL;
		}
		void elimarCarro(){
			Carro *aux=lista;
			Carro *ant=NULL;
			if(lista==NULL){
				cout<<"  Lista vacia"<<endl;
				getch();
				}
			else{
				Carro *op=recorrerLista();
				while((aux!=NULL)&&(aux!=op)){
					ant=aux;
					aux=aux->sig;
				}
				if(aux!=NULL){
					if(ant!=NULL&&aux->sig!=NULL){
						ant->sig=aux->sig;
						aux->sig->ant=aux->ant;
					}
					else if(ant==NULL&&aux->sig!=NULL){
						lista=aux->sig;
						lista->ant=NULL;
					}
					else if(ant!=NULL&&aux->sig==NULL){
						ant->sig=NULL;
					}
					else{
						lista=NULL;
						aux=NULL;
						free(lista);
					}
					free(aux);
					cout<<"Carro eliminado"<<endl<<endl;
				}
				else
					cout<<"El Carro no esta en la lista"<<endl<<endl;
				}
		}
		void eliminarNodoS(string z){
			Carro *aux=lista;
			Carro *ant=NULL;
			while((aux!=NULL)&&(aux->getmodelo()!=z)){
				ant=aux;
				aux=aux->sig;
			}
			if(aux!=NULL){
				if(ant!=NULL&&aux->sig!=NULL){
					ant->sig=aux->sig;
					aux->sig->ant=aux->ant;
				}
				else if(ant==NULL&&aux->sig!=NULL){
					lista=aux->sig;
					lista->ant=NULL;
				}
				else if(ant!=NULL&&aux->sig==NULL){
					ant->sig=NULL;
				}
				else{
					lista=NULL;
					aux=NULL;
					free(lista);
				}
				free(aux);
				cout<<"Carro eliminado"<<endl<<endl;
			}
			else
				cout<<"El Carro no esta en la lista"<<endl<<endl;
	}
		void acomodar(){
		if(lista==NULL){
			cout<<"  Lista vacia"<<endl;
			getch();
		}
		else{
			Carro *aux=lista;
			Carro *ante=NULL;
			while(aux!=NULL){
				ante=aux;
				aux=aux->sig;
				insertarNodo(ante);
			}
			lista=lista2;
		}
	}
		void insertarNodo(Carro *x){
		Carro *ne= new Carro();
		ne=x;
		if(lista2==NULL)
		lista2=ne;
		else{
			Carro *aux=lista2;
			Carro *ante=NULL;
			while((aux!=NULL)&&(aux->getmodelo()<=ne->getmodelo())){
				ante=aux;
				aux=aux->sig;
			}
			if(aux!=NULL){
				if(ante!=NULL){
					ante->sig=ne;
					ne->ant=ante;
					ne->sig=aux;
					aux->ant=ne;
				}
				else{
					ante=ne;
					lista2=ante;
					ante->sig=aux;
					aux->ant=ante;
					ante->ant=NULL;
				}
			}
			else{
				aux=ne;	
				ante->sig=aux;
				aux->ant=ante;
				aux->sig=NULL;
			}
			if(aux->sig==lista2)
				aux->sig=NULL;
		}
	}
	public: Carro* buscarValor(string x){
		Carro *aux = new Carro();
		aux=lista;
		while(aux!=NULL&&aux->getmodelo()!=x)
			aux=aux->sig;
		if(aux==NULL){
			cout<<endl<<"  El valor no esta en la lista"<<endl<<endl;
			return NULL;
		}
		else{
			return aux;
		}
	}
		void editar(Carro *aux){
			int  x;
			char opcion2;
			string z;
			do{
				system("cls");
				mostrar(aux);
				cout << "                          || EDITAR || "<< endl;
				cout<<endl<<"  MODELO ENCONTRADO\n\n  Que desea editar?\n\n  1)Marca\n  2)Modelo\n  3)Motor\n  4)Capacidad de pasajeros\n  5)Numero de llantas\n  6)Salir\n\n  Opcion: ";
				cin>>opcion2;
				switch(opcion2){
					case '1':
						cout<<endl<<"  Nueva marca: ";
						fflush(stdin);getline(cin,z);
						aux->setmarca(z);
						break;
					case '2':
						cout<<endl<<"  Nuevo modelo: ";
						fflush(stdin);getline(cin,z);
						aux->setmodelo(z);
						break;
					case '3':
						cout<<endl<<"  Nuevo motor: ";
						fflush(stdin);getline(cin,z);
						aux->setmotor(z);
						break;
					case '4':
						cout<<endl<<"  Nueva capacidad de pasajeros: ";
						cin>>x;
						aux->setcapacidad(x);
						break;
					case '5':
						cout<<endl<<"  Nuevo numero de llantas: ";
						cin>>x;
						aux->setnumLlantas(x);
						break;
					case '6':
						cout<<endl<<"  Saliste de editar"<<endl;
						break;
					default:
						cout<<endl<<"  Opcion invalida"<<endl;
						break;
					system("cls");
				}
			}while(opcion2!='6');
		}
		void registrar(Carro *c){
			string a, b, f;
			int d, e;
			cout<<"  Introduce la marca del vehiculo: ";
			fflush(stdin);getline(cin,a);
			c->setmarca(a);
			cout<<"  Introduce el modelo del vehiculo: ";
			fflush(stdin);getline(cin, b);
			c->setmodelo(b);
			cout<<"  Introduce el motor del vehiculo: ";
			fflush(stdin);getline(cin, f);
			c->setmotor(f);
			cout<<"  Introduce la capacidad de pasajeros del vehiculo: ";
			cin>>e;
			c->setcapacidad(e);
			cout<<"  Introduce el numero de llantas del vehiculo: ";
			cin>>d;
			c->setnumLlantas(d);
			cout<<endl;
		}	
		void mostrar(Carro *aux){
			cout<<endl<<"  Marca: "<<aux->getmarca()<<endl;
			cout<<"  Modelo: "<<aux->getmodelo()<<endl;
			cout<<"  Capacidad de pasajeros: "<<aux->getcapacidad()<<endl;
			cout<<"  Motor: "<<aux->getmotor()<<endl;
			cout<<"  Numero de llantas: "<<aux->getnumLlantas()<<endl;
			cout<<endl;
		}
};

typedef struct Comprador{
	string nombre;
	int telefono;
	string direccion;
}Comprador;
//venta
class Compra:public Lista {
	private:
		string fecha;
		float precio;
		Comprador cop;
		Compra *sig;
		Carro *carro;
		
	public:
		Compra(){
			this->precio=0;
			this->sig=NULL;
			this->fecha="X";
			this->cop.nombre="X";
			this->cop.direccion="X";
			this->cop.telefono=0;
			this->carro=NULL;
		}
		void setPrecio(float x){
			this->precio=x;
		}
		float getPrecio(){
			return this->precio;
		}
		void setFecha(string x){
			this->fecha=x;
		}
		string getFecha(){
			return this->fecha;
		}
		void setNombre(string x){
			this->cop.nombre=x;
		}
		string getNombre(){
			return this->cop.nombre;
		}
		void setDireccion(string x){
			this->cop.direccion=x;
		}
		string getDireccion(){
			return this->cop.direccion;
		}
		void setTelefono(int x){
			this->cop.telefono=x;
		}
		int getTelefono(){
			return this->cop.telefono;
		}
		Compra* getSig(){
			return this->sig;
		}
		void setSig(Compra *x){
			this->sig=x;
		}
		Carro* getCarro(){
			return this->carro;
		}
		void setCarro(Carro *x){
			this->carro=x;
		}
		Compra* creaenodo(Lista *list){
			Compra *compra = new Compra;
			int x;
			float y;
			string z;
			system("cls");
			cout << "                  || ENCLOAR ||"<< endl << endl;
			cout<<"  Escriba el Nombre del Comprador ";
			fflush(stdin); getline(cin,z);
			compra->setNombre(z);
			cout<<"  Escriba el Telefono del Comprador ";
			cin>>x;
			compra->setTelefono(x);
			cout<<"  Escriba la direccion del Comprador ";
			fflush(stdin); getline(cin,z);
			compra->setDireccion(z);
			cout<<"  Escriba el Precio de Veiculo ";
			cin>>y;
			compra->setPrecio(y);
			cout<<"  Escriba la Fecha de la venta ";
			fflush(stdin); getline(cin,z);
			compra->setFecha(z);
			cout << "   Escoja el carro ";
			compra->setCarro(list->recorrerLista());
			compra->getCarro()->setcapacidad(getCarro()->getcapacidad());
			compra->getCarro()->setmarca(getCarro()->getmarca());
			compra->getCarro()->setmodelo(getCarro()->getmodelo());
			compra->getCarro()->setmotor(getCarro()->getmotor());
			compra->getCarro()->setnumLlantas(getCarro()->getnumLlantas());
		}
		void mostrarCol(Compra *aux){
			cout<<"  Nombre del Comprador "<< aux->getNombre() << endl;
			cout<<"  Telefono del Comprador "<< aux->getTelefono() << endl;
			cout<<"  Direccion del Comprador "<< aux->getDireccion() <<endl;
			cout<<"  Precio de Veiculo "<< aux->getPrecio()<<endl;
			cout<<"  Fecha de la venta "<< aux->getFecha() <<endl;
			cout<<"  Marca: "<<aux->getCarro()->getmarca()<<endl;
			cout<<"  Modelo: "<<aux->getCarro()->getmodelo()<<endl;
			cout<<"  Capacidad de pasajeros: "<<aux->getCarro()->getcapacidad()<<endl;
			cout<<"  Motor: "<<aux->getCarro()->getmotor()<<endl;
			cout<<"  Numero de llantas: "<<aux->getCarro()->getnumLlantas()<<endl;
		}
};

class Cola{
	private:
		Compra *cola;
	public:
		Cola(){
			this->cola=NULL;
		}
		void entradas(Lista *list)
		{
		     ofstream entrada;
		  entrada.open("archivo.dat",ios::out|ios::app|ios::binary);
		  
		  if(entrada.fail())
		  {
		            cout<<"error al crear archivo";
		            getch();      
		  }   
		  
		  else 
		  {
		  	Compra *compra = new Compra;
		  int x;
			float y;
			string z;
			system("cls");
			cout << "                  || ENCLOAR ||"<< endl << endl;
			cout<<"  Escriba el Nombre del Comprador ";
			fflush(stdin); getline(cin,z);
			compra->setNombre(z);
			cout<<"  Escriba el Telefono del Comprador ";
			cin>>x;
			compra->setTelefono(x);
			cout<<"  Escriba la direccion del Comprador ";
			fflush(stdin); getline(cin,z);
			compra->setDireccion(z);
			cout<<"  Escriba el Precio de Veiculo ";
			cin>>y;
			compra->setPrecio(y);
			cout<<"  Escriba la Fecha de la venta ";
			fflush(stdin); getline(cin,z);
			compra->setFecha(z);
			cout << "   Escoja el carro ";
			compra->setCarro(list->recorrerLista());
		  entrada.write((char *)compra,sizeof(Compra));
		  entrada.close();
		  }   
		      
		}
		void salidas()
		{
		     ifstream salida;
		     salida.open("archivo.dat",ios::in|ios::binary);
		     
		     if (salida.fail())
		     {
		     cout<<"error al abrir el archivo"<<endl;
		     getch();                  
		     }
		     else       
		     {
		     int nreg;
		     Compra *aux=new Compra();
		     salida.seekg(0,ios::end);
		     nreg=salida.tellg()/sizeof(Compra);
		     salida.seekg(0);  
		     
		       for(int x=0;x<nreg;x++)
		              {
		              salida.read((char *)aux,sizeof(Compra));
		              cout<<"  Nombre del Comprador "<< aux->getNombre() << endl;
						cout<<"  Telefono del Comprador "<< aux->getTelefono() << endl;
						cout<<"  Direccion del Comprador "<< aux->getDireccion() <<endl;
						cout<<"  Precio de Veiculo "<< aux->getPrecio()<<endl;
						cout<<"  Fecha de la venta "<< aux->getFecha() <<endl;
						cout<<"  Marca: "<<aux->getCarro()->getmarca()<<endl;
						cout<<"  Modelo: "<<aux->getCarro()->getmodelo()<<endl;
						cout<<"  Capacidad de pasajeros: "<<aux->getCarro()->getcapacidad()<<endl;
						cout<<"  Motor: "<<aux->getCarro()->getmotor()<<endl;
						cout<<"  Numero de llantas: "<<aux->getCarro()->getnumLlantas()<<endl;
					cout << endl<< endl;
		              }
		     salida.close();
		     getch();
		       
		     }
		            
		}
		void eliminar()
		{
		      ofstream entrada;
		      entrada.open("temp.dat",ios::out|ios::binary);
		      ifstream salida;
		     salida.open("archivo.dat",ios::in|ios::binary);
		     
		     if (salida.fail()||entrada.fail())
		     {
		     cout<<"error al abrir el archivo"<<endl;
		     getch();                  
		     }
		     else
		     {
		     	Compra *aux=new Compra();
		     	bool auxb=true;
		     int nreg;
		     salida.seekg(0,ios::end);
		     nreg=salida.tellg()/sizeof(Compra);
		     salida.seekg(0);
		            for(int x=0;x<nreg;x++)
		              {
		              salida.read((char *)aux,sizeof(Compra));
		                   if(auxb)
		                     {
		                     	auxb=false;
		                     cout<<"registro borrado"<<endl;                             
		                     }
		                     
		                     else
		                     {
		                     entrada.write((char *)aux,sizeof(Compra));    
		                     }
		                    
		              }        
				    
		     salida.close();
		     entrada.close();
		     remove("archivo.dat");
		     rename("temp.dat","archivo.dat");
		     cout<<"registro borrado"<<endl; 
		     getch();   
		 }
		     }
		void encolar(Lista *list){
			Compra *nuevo=new Compra();
			nuevo->creaenodo(list);
			if(cola==NULL){
				
			cola=nuevo;
			}
			else{
				Compra *aux=new Compra();
				aux=cola;
				while(aux->getSig()!=NULL)
				aux=aux->getSig();
				aux->setSig(nuevo);
			}
		}
		void desencolar(){
			if(cola==NULL)
			cout<<"  Cola vacia"<<endl;
			else{
				 Compra *aux=cola;
				cout << "  Dato eliminado " ;
				cola=aux->getSig();
				free(aux);
			}
			getch();
		}
		void recorrerC(){
			if(cola==NULL)
				cout<<"  Cola vacia"<<endl;
			else{
				Compra *aux = new Compra();
				aux=cola;
				while(aux!=NULL){
					cout<<"  "<<endl;
					aux=aux->getSig();
				}
			}
			getch();
		}
};

void Eliminar(Lista*);
void menuVenta(Lista *);
void Editar(Lista*);

void entradas();
void salidas();
void eliminar();
void modificar();

void Encolarf(Cola*,Lista*);
void Desencolarf(Cola*);
int main(){
	char opcion;
	string a;
	Lista *list = new Lista();
	
	do{
		system("cls");
		cout << "                       || CARROS ||"<< endl;
		cout<<"  1)Agregar Veiculo\n  2)Recorrer\n  3)Editar\n  4)Eliminar\n  5)Ordenar \n  6)Registar Venta\n  7)Salir\n\n  Opcion: ";
		cin>>opcion;
		system("cls");
		switch(opcion){
			case '1':
				list->agregarCarro();
				break;
			case '2':
				list->recorrerLista();
				break;
			case '3':
				Editar(list);
				break;
			case '4':
				Eliminar(list);
				break;
			case '5':
				list->acomodar();
				break;
			case '6':
				menuVenta(list);
				break;
			case '7':
				cout<<endl<<"  Saliste del programa"<<endl;
				break;
			default:
				break;
		}
	}while(opcion!='7');		
}

void Eliminar(Lista *list){
	char opc;
	string z;
	cout << "                                   || ELIMINAR ||" << endl;
	cout << "  1-Eliminar por busqueda manual" << endl;
	cout << "  2-Eliminar por modelo" << endl;
	cout << "  3-Regresar" << endl << "  Opcion: ";
	fflush(stdin);cin >> opc;fflush(stdin);
	system("cls");
	switch(opc){
		case '1':
			list->elimarCarro();
			break;
		case '2':
			cout << "                           || ELIMINAR ||" << endl;
			cout << "  Anote el modelo de el carro que dese eliminar " << endl << "  Modelo: ";
			fflush(stdin);getline(cin,z);
			list->eliminarNodoS(z);
			break;
		case '3':
		default:
			break;
	}
}
void Editar(Lista *list){
	char opc;
	string z;
	cout << "                                    || BUSQUEDA ||" << endl;
	cout << "  1-Busqueda manual" << endl;
	cout << "  2-Busqueda por modelo" << endl;
	cout << "  3-Regresar" << endl << "  Opcion: ";
	fflush(stdin);cin >> opc;fflush(stdin);
	system("cls");
	switch(opc){
		case '1':
			list->editar(list->recorrerLista());
			break;
		case '2':
			cout << "                            || BUSQUEDA ||" << endl;
			cout<<"  Introduzca el modelo del vehiculo que busca: ";
			fflush(stdin);getline(cin,z);
			system("cls");
			if(list->buscarValor(z)!=NULL)
			list->editar(list->buscarValor(z));
			else 
			cout << "  valor no enconreado"<< endl;
			getch();
			break;
		case '3':
		default:
			break;
	}
}
void menuVenta(Lista *list ){
		Cola *co =new Cola();
		Compra *vent =new Compra();
	int y;
	string x,z,b;
	char op;
	float a;
	do{	
		printf("                       ||VENTA||");
		printf("\n  1-Encolar");
		printf("\n  2-Imprimir Datos de la venta");
		printf("\n  3-Desencolar");
		printf("\n  4-salir");
	    printf("\n  Opcion: ");
		 cin >> op;
	    switch(op){
	    	case '1':
	    		co->entradas(list);
		    	printf("\n");
		    	system("pause");
	    	break;
	    	case '2':
				system("cls");	
		    	co->salidas();
				printf("\n");
				system("pause");
	    	break;
	    	case '3':
		    	system("cls");
		    	co->eliminar();
		    	system("pause");
		    	break;
	    	default:
				break;
	    	
		}
		system("cls");
	}while(op!='4');
		
}
void Encolarf(Cola*co,Lista*list){
	
}
