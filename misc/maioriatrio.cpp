/*
Assuma que existe um array A[1..n] com n elementos. Um elemento maiorit�rio de A � qualquer elemento que ocorra em mais de n/2 posi��es (portanto, se n = 6 ou n = 7, o elemento maiorit�rio dever� ocorrer em pelo menos 4 posi��es).

Assuma que os elementos n�o podem ser ordenados, mas podem ser comparados.

Projete um algoritmo de divis�o e conquista eficiente que encontre o elemento maiorit�rio do array A (ou determine que ele n�o existe) em tempo O(n log n).

*/

#include <stdio.h>
#include <limits.h>
#include <map>
#include <vector>

int main()
{
    std::map<int, int> mapa;
    std::vector<int> v;
    int n, aux = INT_MIN, maioritario;

    printf("Numero de elementos: ");
    scanf("%d", &n);

    v.resize(n);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &v[i]);
        mapa.find(v[i]) != mapa.end() ? ++mapa[v[i]] : mapa[v[i]] = 1;
        if(mapa[v[i]] > aux)
        {
            aux = mapa[v[i]];
            maioritario = v[i];
        }
    }

    if(aux > n >> 1)
        printf("Elemento maioritario: %d\n", maioritario);
    else
        printf("Nao ha elemento maioritario.\n");
    return 0;
}
