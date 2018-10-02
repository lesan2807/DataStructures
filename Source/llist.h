#ifndef LINKED_LIST_llist
#define LINKED_LIST_llist
#include <iostream>

// Nodos de la lista:
template <typename T>
class llnode{
   public:
		// Esta clase es para ser usada por otras clases.
		// Por eficiencia los atributos se dejan publicos.
		T key;
		llnode<T> *prev, *next;
		//enum colors color;

		// Constructor por omision.
		llnode(){
		};

      // Inicializacion de los datos miembro.
		llnode (const T& k, llnode<T> *w = NULL, llnode<T> *y = NULL):key(k), prev(w), next(y) {};

		~llnode(){
		}
};

// Lista enlazada con nodo centinela:
template <typename T>
class llist{
	public:
		llist(){
      nil = new llnode<T>('0', nil, nil); //Cambiar
		};
			// Constructor (crea una lista vacia)

		llist(const llist<T>& obj){
		};
			// Constructor copia

		~llist(){
      llnode<T> *P = nil->prev->prev;
      while(P){
        std::cout << "Erasing" << std::endl;
        delete P->next;
        P = P->prev;
      }

		};
			// Destructor (borra la lista)

		llnode<T>* listSearch(const T& k){
      llnode<T> *p;
      p = nil->next;
      while(p != nil && p.key != k){
        p = p->next;
      }
      return p;
		};
			// Busca la llave iterativamente. Si la encuentra, devuelve un
            // apuntador al nodo que la contiene; sino devuelve NULL.

		void listInsert(llnode<T>* x){
      x->next = nil->next;
      nil->next = x;
      nil->next->prev = x;
      x->prev = nil;

		};
			// Inserta el nodo x en la lista.

		llnode<T>* listDelete(llnode<T>* x){
      if(x->prev == nil){
        nil->next = x->next;
        x->next->prev = nil;
      }
      else{
        x->prev->next = x->next;
        x->next->prev = x->prev;
      }
      return &x;
		};
			// Saca de la lista la llave contenida en el nodo apuntado por x.
			// Devuelve la direccion del nodo eliminado para que se pueda
			// disponer de el.

		llnode<T> * getNil() const{
			return this->nil;
		};
		// Devuelve el nodo centinela. (Para efectos de revision de la tarea).

    void print(){
      llnode<T> * P = nil -> next;
      while(P){
        std::cout << P->key << std::endl;
        P = P->next;
      }
    }

		private:

		llnode<T> *nil;	    // nodo centinela

};

#endif	// LINKED_LIST_llist
