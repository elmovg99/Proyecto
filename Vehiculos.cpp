//Actividad Integradora

#include <iostream>
#include <stdlib.h>
#include "string.h"
#include "conio.h"
#include "stdio.h"

using namespace std;
//En el ejmplo la clase a asociar va al principio para poder declarr el objeto de venta en la de lista
//Inicio de la Clase venta(Lamada Nodo) con estructura y funciones
typedef struct Comprador{
	string nombre;
	int telefono;
	string direccion;
}Comprador;
//venta
class Nodo{
	private: Comprador comp;
	private: float precio;
	private: string fecha;
	public: Nodo *sig;
	public: Nodo(){
		this->comp.nombre="x";
		this->comp.telefono=0;
		this->comp.direccion="x";
		this->precio=0;
		this->fecha="x";
		this->sig=NULL;
	}
	public: Nodo(string x, int y, string z, float a, string b){
		this->comp.nombre=x;
		this->comp.telefono=y;
		this->comp.direccion=z;
		this->precio=a;
		this->fecha=b;
		this->sig=NULL;
	}
	public: void setNombre(string x){
		this->comp.nombre=x;
	}
	public: void setTelefono(int y){
		this->comp.telefono=y;
	}
	public: void setDireccion(string z){
		this->comp.direccion=z;
	}
	public: void setPrecio(float a){
		this->precio=a;
	}
	public: void setFecha(string b){
		this->fecha=b;
	}
	public: string getNombre(){
		return this->comp.nombre;
	}
	public: int getTelfono(){
		return this->comp.telefono;
	}
	public: string getDireccion(){
		return this->comp.direccion;
	}
	public: float getPrecio(){
		return this->precio;
	}
	public: string grtFecha(){
		return this->fecha;
	}

};


class Cola{
	private: Nodo *cola;
	public: Cola(){
		this->cola=NULL;
	}
	public: void encolar(string _x,int _y,string _z,float _a,string _b ){
	Nodo *nuevo =new Nodo(_x,_y,_z,_a,_b); //personalizado
		if(cola==NULL)
		    cola=nuevo;
		else{
			Nodo *aux=new Nodo(_x,_y,_z,_a,_b);//por Default
			aux=cola;
			while(aux->sig!=NULL)
			   aux=aux->sig;
			aux->sig=nuevo;
		
	    }
   }
	public: void recorrercola(){
		if(cola==NULL)
		   cout<<"la cola esta Vacia"<<endl;
		else{
			Nodo *aux=new Nodo();
			aux=cola;
			cout<<"||VENTAS REGISTRADAS||"<<endl;
			while(aux->sig!=NULL){
				cout<<"Nombre: "<<aux->getNombre()<<endl;
	    		cout<<"Telefono: "<<aux->getTelfono()<<endl;
	    		cout<<"Direccion: "<<aux->getDireccion()<<endl;
	    		cout<<"Precio: "<<aux->getPrecio()<<endl;
	    		cout<<"Fecha: "<<aux->grtFecha()<<endl;
	    		cout<<endl;
				aux=aux->sig;
			}
			cout<<"Nombre: "<<aux->getNombre()<<endl;
			cout<<"Telefono: "<<aux->getTelfono()<<endl;
			cout<<"Direccion: "<<aux->getDireccion()<<endl;
			cout<<"Precio: "<<aux->getPrecio()<<endl;
			cout<<"Fecha: "<<aux->grtFecha()<<endl;
		}
	}

	public: void Desencolar(){
			Nodo *aux=cola;
			
			if(cola==NULL)//Al entrar aquí significa que sí lo encontró
                cout<<"No hay nodos en la Pila";
				else{
				
				cola=aux->sig;
				free(aux);
				cout<<"Nodo eliminado"<<endl;
		    }
	}
};//Fin de la Clase venta(Lamada Nodo) con estructura y funciones


class Vehiculo{
	protected:
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
	private:
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

class Lista{
	private:
		Nodo *venta;
		Carro *lista;//Creación de objeto por asociar
	public:
		Lista(){
			lista=NULL;
			venta= new Nodo();//inicialización del objeto con new
		}
		public:	void incluye(Nodo *v){//Definición del método que asocia
			          this->venta=v;
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
			
		string recorrerLista(){
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
				return aux->getmodelo();
			}
			return "undefine";
		}
		void eliminarNodo(string z){
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
	public: void buscarValor(string x){
		Carro *aux = new Carro();
		aux=lista;
		while(aux!=NULL&&aux->getmodelo()!=x)
			aux=aux->sig;
		if(aux==NULL)
			cout<<endl<<"El valor no esta en la lista"<<endl<<endl;
		else{
			int opcion2, i;
			do{
				cout<<endl<<"  MODELO ENCONTRADO\n\n  Que desea editar?\n\n  1)Marca\n  2)Modelo\n  3)Motor\n  4)Capacidad de pasajeros\n  5)Numero de llantas\n  6)Salir\n\n  Opcion: ";
				cin>>opcion2;
				system("cls");
				switch(opcion2){
					case 1:
						cout<<endl<<"Nueva marca: ";
						cin>>x;
						aux->setmarca(x);
						system("cls");
						break;
					case 2:
						cout<<endl<<"Nuevo modelo: ";
						cin>>x;
						aux->setmodelo(x);
						system("cls");
						break;
					case 3:
						cout<<endl<<"Nuevo motor: ";
						cin>>x;
						aux->setmotor(x);
						system("cls");
						break;
					case 4:
						cout<<endl<<"Nueva capacidad de pasajeros: ";
						cin>>i;
						aux->setcapacidad(i);
						system("cls");
						break;
					case 5:
						cout<<endl<<"Nuevo numero de llantas: ";
						cin>>i;
						aux->setnumLlantas(i);
						system("cls");
						break;
					case 6:
						cout<<endl<<"Saliste de editar"<<endl;
						system("cls");
						break;
					default:
						cout<<endl<<"Opcion invalida"<<endl;
						system("cls");
						break;
				}
			}while(opcion2!=6);
		}
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
};

void Eliminar(Lista*);
void menuVenta(Lista *);

int main(){
	char opcion;
	string a;

	Lista *list = new Lista();
	
	do{
		system("cls");
		cout<<"  1)Agregar Veiculo\n  2)Recorrer\n  3)Editar\n  4)Eliminar\n  5)Registar Venta\n   6)Salir\n\n  Opcion: ";
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
				cout<<"  Introduzca el modelo del vehiculo que busca: ";
				fflush(stdin);getline(cin, a);
				system("cls");
				list->buscarValor(a);
				break;
			case '4':
				Eliminar(list);
				break;
			case '5':
				menuVenta(list);
				break;
			case '6':
				cout<<endl<<"  Saliste del programa"<<endl;
				break;
			default:
				break;
		}
	}while(opcion!='6');		
}

void Eliminar(Lista *list){
	char opc;
	string z;
	cout << "                            ELIMINAR" << endl;
	cout << "  1-Eliminar por busqueda manual" << endl;
	cout << "  2-Eliminar por modelo" << endl;
	cout << "  3-Regresar" << endl << "  Opcion: ";
	fflush(stdin);cin >> opc;fflush(stdin);
	system("cls");
	switch(opc){
		case '1':
			list->eliminarNodo(list->recorrerLista());
			break;
		case '2':
			cout << "  Anote el modelo de el carro que desee eliminar " << endl << "  Modelo: ";
			fflush(stdin);getline(cin,z);
			list->eliminarNodo(z);
			break;
		case '3':
		default:
			break;
	}
}
void menuVenta(Lista *_list ){
		Cola *co =new Cola();
		Nodo *_vent =new Nodo();
	    _list->incluye(_vent);//Asociacion. en vio del objeto al la clase Lista
	int op,y;
	string x,z,b;
	float a;
	do{	printf(" ||VENTA||");
	printf("\n1.-Registar Venta");
	printf("\n2.-Imprimir Datos de la venta");
	printf("\n3.-Borrar Venta");
	printf("\n4.-salir");
    printf("\nOpcion: ");
    scanf("%i",&op);
    switch(op){
    	case 1:
    	system("cls");
    	cout<<"\nEscriba el Nombre del Comprador "<<endl;
    	fflush(stdin); getline(cin,x);
      
    	cout<<"\nEscriba el Telefono del Comprador "<<endl;
    	cin>>y;
        
    	cout<<"\nEscriba la direccion del Comprador "<<endl;
    	fflush(stdin); getline(cin,z);
       
    	cout<<"\nEscriba el Pecio de Veiculo "<<endl;
    	cin>>a;
    
    	cout<<"\nEscriba la Fecha de la venta "<<endl;
    	fflush(stdin); getline(cin,b);
    	
        co->encolar(x,y,z,a,b);
        
    	printf("\n");
    	system("pause");
    	break;
    	case 2:
		system("cls");	
    	co->recorrercola();
    	printf("\n");
    	system("pause");
    	break;
    	case 3:
    	system("cls");
    	co->Desencolar();
    	system("pause");
    	break;

    	
	}

	
	system("cls");
	}while(op!=4);
		
	}
////Archivo-Codigo22
//#include<conio.h>
//#include<stdlib.h>
//#include<fstream>
//#include<iostream>
//using namespace std;
//
//class Persona{
//	private:
//		string nombre;
//		string direccion;
//		int telefono;
//	public:
//		Persona();
//		Persona(string, string, int);
//		void setNombre(string);
//		void setDireccion(string);
//		void setTelefon(int);
//		string getNombre();
//		string getDireccion();
//		long getTelefono();
//};
//
//class Archivo{
//	public:
//		void crearArchivo();
//		void agregarPersona(Persona *);
//		void mostrarContenido();
//		void buscarPersona();
//		
//};
//
//void Archivo::crearArchivo(){
//	ofstream archivo;
//	archivo.open("personas.dat",ios::out | ios::app);
//	if(!archivo){
//		cout<<"Error al abrir el archivo"<<endl;
//	}
//	archivo.close();//importante cerrar o el archivo se dañara
//}
//
//void registrarPersona(Persona *); 
//
//
//void Archivo::agregarPersona(Persona *p){
//	ofstream archivo;
//	archivo.open("personas.dat",ios::app);
//	if(!archivo){
//		cout<<"Error al abrir el archivo"<<endl;
//	}else{
//		archivo.write((char *)&*p, sizeof(*p));//puntero hacia el bloque de memoria y tamaño del archivo
//	    }
//	archivo.close();
//}
//void Archivo::mostrarContenido(){//Debemos saber que, para  mostrar, se abrirá primero el archivo, y este, pasará toda la informacion a la clase
//	ifstream archivo("personas.dat"); // después, ya con la informacion en la clase, podremos imprimir medinte ella
//	Persona *p =new Persona();//se inicilaza nuevamente la clase persona para que sea rellenada por el archivo
//	if(archivo.good()){
//		while(!archivo.eof()){//mientrar archivo no llegue al final
//			archivo.read((char *)&*p,sizeof(*p));
//			if(archivo.eof())//salir si el archivo llego al final
//			break;//ya ha llegado al final. ya no hay nada que mostrar
//			cout<<"Nombre: "<<p->getNombre()<<endl;
//			cout<<"direccion: "<<p->getDireccion()<<endl;
//			cout<<"Telefono: "<<p->getTelefono()<<endl;
//		}
//	}else
//		cout<<"Archivo vacio"<<endl; 
//}
//void Archivo::buscarPersona(){
//	fstream archivo("personas.dat",ios::in | ios::out);
//	Persona *p =new Persona();
//	string buscarNom,nom, dir;
//	long int posicion=0;
//	int mod=0,tel;
//	if(!archivo){
//		cout<<"Error al abrir el archivo"<<endl;
//	}else{
//		cout<<"Nombre a buscar: ";
//		fflush(stdin); getline(cin,buscarNom);
//		while(!archivo.eof()){
//			archivo.read((char *)&*p,sizeof(*p));
//			posicion=archivo.tellp();
//			if(p->getNombre()==buscarNom){
//				cout<<"Nombre encontrado"<<endl;
//				cout<<"Modifacar los datos?(1=Sí,2=No)"<<endl;
//				cin>>mod;
//				if(mod==1){
//					archivo.seekp((posicion-sizeof(*p)),ios::beg);
//					cout<<"Nombre: ";
//					cin>>nom;
//					p->setNombre(nom);
//					cout<<"Direccion: ";
//					cin>>dir;
//					p->setDireccion(dir);
//					cout<<"Telefono: ";
//					cin>>tel;
//					p->setTelefon(tel);
//					archivo.write((char *)&*p,sizeof(*p));
//					cout<<"Datos actualizados"<<endl;
//					
//				}//if-mod
//			}//if-comparación
//		}//while
//	}//else-Archivo
//	archivo.close();
//}//Métod
//int main(){
//	Archivo a;
//	Persona *obj =new Persona();
//	int op=0;
//	a.crearArchivo();
//	do{
//		//menu opciones
//		cout<<"1.-registra ersona"<<endl;
//		cout<<"2.-Mostar daros"<<endl;
//		cout<<"3.-buscar Persona"<<endl;
//		cout<<"4.-Salir"<<endl;
//		cout<<"Opciion: ";
//		cin>>op;
//		switch(op){
//			case 1: registrarPersona(&obj);
//			        a.agregarPersona(&obj);
//			break;
//			case 2: a.mostrarContenido();
//			break;
//			case 3: a.buscarPersona();
//			break;
//		}
//	}while(op!=4);
//getch();
//return(0);	
//}
//void registrarPersona(Persona *p){
//	string n,d;
//	int tel;
//	
//	cout<<"Escribe el nombre ";
//	fflush(stdin); getline(cin,n);
//	p->setNombre(n);
//	cout<<"Escribe la direccion ";
//	fflush(stdin); getline(cin,d);
//	p->setDireccion(d);
//	cout<<"Digita el Telefono ";
//	cin>>tel;
//	p->setTelefon(tel);
//}

