#include <iostream>

using namespace std;
void bubblesort(int);

int main()
{
    int n;
    cout << "Tamanho do vetor a ser ordenado: ";
    cin >> n;
    bubblesort(n);
    return 0;
}

void bubblesort(int n)
{
    int vetor[n], i, j, aux;

    cout << "Insira o vetor a ser ordenado: ";
    for(i=0; i<n; i++)
        cin >> vetor[i];

    for(i=n-1; i>0; i--)
    {
        for(j=0; j<i; j++)
        {
            if(vetor[j]>vetor[j+1])
            {
                aux=vetor[j+1];
                vetor[j+1]=vetor[j];
                vetor[j]=aux;
            }
        }
    }

    cout << "Vetor ordenado: ";

    for (i=0; i<n; i++)
        cout << vetor[i] << " ";
}
