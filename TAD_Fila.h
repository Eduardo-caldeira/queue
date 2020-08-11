#ifndef TAD_FILA_H_INCLUDED
#define TAD_FILA_H_INCLUDED

template<typename tipo>
struct Dado{
    tipo dado;
};

template<typename tipo>
struct TElementoF{
    tipo elemento;
    TElementoF *next;
};

template<typename tipo>
struct TFila{
    TElementoF<tipo> *primeiro;
};

template<typename tipo>
bool inicializa_fila(TFila<tipo> *Fila){
    Fila->primeiro = NULL;
    return true;
}

template<typename tipo>
bool QUEUE (TFila<tipo> *Fila, tipo dado){
    TElementoF<tipo> *var;
    TElementoF<tipo> *escravo = Fila->primeiro;
    if(Fila->primeiro != NULL){
        while(escravo->next != NULL){
            escravo=escravo->next;
        }
        var = new TElementoF<tipo>;
        var->elemento = dado;
        var->next = NULL;

        escravo->next=var;
        return true;
    }else{
        var = new TElementoF<tipo>;
        var->elemento = dado;
        var->next = NULL;
        Fila->primeiro=var;
        return true;
    }
}

template<typename tipo>
tipo DEQUEUE(TFila<tipo> *Fila){
    tipo dado = Fila->primeiro->elemento;
    TElementoF<tipo> *lixeira=Fila->primeiro;
    if(Fila->primeiro==NULL){
        return false;
    }else{
        Fila->primeiro = Fila->primeiro->next;
        delete lixeira;
        return dado;
    }
}

#endif // TAD_FILA_H_INCLUDED
