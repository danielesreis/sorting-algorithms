#include <iostream>
using namespace std;

int find_pos(int [], int);
void insertion(int [], int, int);

int main()
{
    int n, *vetor, i, pos;

    cout << "Nome de elementos do vetor: ";
    cin >> n;
    vetor = new int[n];

    cout << "Insercao dos elementos: " << endl;
    for (i=0; i<n; i++)
    {
        cin >> vetor[i];
    }

    for (i=1; i<n; i++)
    {
        pos = find_pos(vetor, i);
        insertion(vetor, i, pos);
    }

    cout << endl << "Vetor ordenado" << endl;
    for(i=0; i<n; i++)
        cout << vetor[i] << " ";

    delete [] vetor;
    return 0;
}

int find_pos(int vetor[], int elem)
{
    int i, aux=elem;

    for (i=elem-1; i>=0; i--)
    {
        if(vetor[elem]<vetor[i])
            aux=i;
    }
    return aux;
}

void insertion(int vetor[], int ant_pos, int nov_pos)
{
    int i, elem=vetor[ant_pos], aux;

    for (i=ant_pos; i>nov_pos; i--)
    {
        vetor[i]=vetor[i-1];
        aux=i;
    }
    if (ant_pos!=nov_pos) vetor[aux-1]=elem;

}
