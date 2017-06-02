#include <iostream>
using namespace std;

typedef struct elem_fila
{
   int vf;
   struct elem_fila *p_el;
}elem_f;

typedef struct fila
{
    elem_f *ptr;
}FILA;

elem_f* cria_elem(int);
void libera_elem(elem_f*);
FILA* cria_fila();
int tam_fila(FILA);
void insere_fila(FILA*, int);
elem_f* valor_pos(FILA, int);
void selectionsort(FILA*);
elem_f* pos_menor(FILA, int);
void imprime_fila(FILA);
void troca_elem(FILA*, elem_f*, elem_f*);
void libera_fila(FILA*);

int main()
{
    int num=0;
    FILA *f = cria_fila();

    cout << "Insira aos elementos (digite -1 para parar): ";

    while(num!=-1)
    {
        cin >> num;
        if (num!=-1) insere_fila(f, num);
    }

    selectionsort(f);
    imprime_fila(*f);
    libera_fila(f);

    delete f;

    return 0;
}

elem_f* cria_elem(int elem)
{
    elem_f *e = new elem_f();
    e->vf=elem;
    e->p_el=NULL;

    return e;
}

void libera_elem(elem_f *e)
{
    delete e;
}

FILA* cria_fila()
{
    FILA *f = new FILA();
    f->ptr=NULL;

    return f;
}

int tam_fila(FILA f)
{
    int tam=0;

    for(; f.ptr!=NULL; f.ptr=f.ptr->p_el)
        tam++;

    return tam;
}

void insere_fila(FILA *f, int elem)
{
    int tam=tam_fila(*f);
    elem_f *e = cria_elem(elem);

    elem_f *aux=f->ptr;

    if (!tam)
        f->ptr=e;

    else
    {
        for(; aux->p_el!=NULL; aux=aux->p_el);
        aux->p_el=e;
    }
}

elem_f* valor_pos(FILA f, int pos)
{
    int i;
    elem_f *e = f.ptr;

    for(i=0; i<pos; i++)
        e=e->p_el;

    return e;
}

void selectionsort(FILA *f)
{
    int i, tam=tam_fila(*f);
    elem_f *ant_elem, *nov_elem;

    for(i=0; i<tam; i++)
    {
        ant_elem=valor_pos(*f, i);
        nov_elem=pos_menor(*f, i);
        troca_elem(f, ant_elem, nov_elem);
    }
}

elem_f* pos_menor(FILA f, int pos)
{
    int i, tam=tam_fila(f);
    elem_f *menor, *aux;

    menor=valor_pos(f, pos);

    for(i=pos; i<tam; i++)
    {
        aux=valor_pos(f, i);
        if (aux->vf<menor->vf)
            menor = aux;
    }

    return menor;
}

void imprime_fila(FILA f)
{
    cout << endl << "Fila ordenada: " << endl;
    for(; f.ptr!=NULL; f.ptr=f.ptr->p_el)
        cout << f.ptr->vf << " ";
}

void troca_elem(FILA *f, elem_f *ant, elem_f *nov)
{
    int vl = ant->vf;
    elem_f *aux, *aux2;

    for(aux=f->ptr; aux!=NULL; aux=aux->p_el)
    {
        if (aux->vf==ant->vf)
        {
            aux->vf=nov->vf;
            aux2=aux;
            break;
        }
    }

    for(aux2=aux2->p_el; aux2!=NULL; aux2=aux2->p_el)
    {
        if (aux2->vf==nov->vf) aux2->vf=vl;
    }
}

void libera_fila(FILA *f)
{
    int i, tam=tam_fila(*f);
    elem_f *aux, *aux2;

    aux=f->ptr;
    aux2=aux->p_el;

    for(i=0; i<tam-1; i++)
    {
        delete aux;
        aux=aux2;
        aux2=aux2->p_el;
    }
    delete aux2;
}
