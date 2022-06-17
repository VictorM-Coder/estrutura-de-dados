#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

void enter_values_in_vector(vector<int> &vetor){
    for (int cont = 0; cont < vetor.size(); cont++){
        cin >> vetor[cont];
    }
}

int select_sort(vector<int> &vetor){
    int number_swaps = 0;
    for(int cont = 0; cont < vetor.size(); cont++){
        int index_of_lower = cont;
        for(int cont_1 = cont + 1; cont_1 < vetor.size(); cont_1++){
            if (vetor[index_of_lower] > vetor[cont_1]){
                index_of_lower = cont_1;
            }
        }
        if (cont != index_of_lower){
            int aux = vetor[cont];
            vetor[cont] = vetor[index_of_lower];
            vetor[index_of_lower] = aux;
            number_swaps++;
        }
        
    }
    return number_swaps;
}

int main(){
    int size;
    cin >> size;
    vector<int> vector(size);
    enter_values_in_vector(vector);
    cout << select_sort(vector);;
    return 0;
}
