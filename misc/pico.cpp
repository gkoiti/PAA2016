/*
 Definição: um elemento pico de um vetor é aquele que é maior que seus dois vizinhos.
 Exemplo: no vetor {10, 20, 15, 2, 23, 90, 67} há dois elementos pico, o 20 e o 90.
 Faça um programa que retorne pelo menos um dos elementos pico de um dado vetor,
 primeiramente usando força bruta e posteriormente usando divisão e conquista.
 Note que você só precisa retornar um elemento pico e que os vetores tem pelo menos um elemento pico e não há repetições.
*/

#include <stdio.h>
#include <limits.h>
#include <algorithm>
#include <vector>

// Complexidade O(n)
int picoLinear(std::vector<int> v, int l, int r)
{
    if(r - l == 0)
        return v[l] > v[l - 1] && v[l] > v[l + 1] ? v[l] : INT_MIN;

    int m = l + (r - l) / 2;

    return std::max(picoLinear(v, l, m), picoLinear(v, m + 1, r));
}

// Complexidade O(log n)
int picoLog(std::vector<int> v, int l, int r)
{
    if(l <= r)
    {
        int m = l + (r - l) / 2;
        if(v[m] > v[m - 1] && v[m] > v[m + 1])
            return v[m];
        else if(v[m] < v[m - 1])
            return picoLog(v, l, m - 1);
        else
            return picoLog(v, m + 1, r);
    }
    return INT_MIN;
}


int main()
{
    std::vector<int> v;
    int n;

    printf("Numero de elementos: ");
    scanf("%d", &n);

    if(n < 3)
        printf("Nao ha pico.\n");
    else
    {
        v.resize(n);
        for(int i = 0; i < n; ++i)
            scanf("%d", &v[i]);

        int res = picoLog(v, 1, n - 2);

        if(res != INT_MIN)
            printf("Pico: %d.\n", res);
        else
            printf("Nao ha pico.\n");
    }

    return 0;
}
