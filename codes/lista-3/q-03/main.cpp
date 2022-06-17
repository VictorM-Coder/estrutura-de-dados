#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void enter_values_in_vectors(vector<int> &vetor, int size){
    for (int cont = 0; cont < size; cont++){
        int value;
        cin >> value;
        vetor.push_back(value);
    }
}

int distancia_valida(int n, vector<int> arr, int num_vacas){
    int ultima_vaca = 0;
    num_vacas--;
    int cont = 1;

    while (num_vacas > 0 && cont < arr.size()){
        if (arr[cont] - arr[ultima_vaca] >= n){
            ultima_vaca = cont;
            num_vacas--;
        }
        cont++;
    }

    if (num_vacas > 0){
        return 0;
    }else{
        return 1;
    }
}

int distancia(vector<int> arr, int num_vacas){
    int maior_distancia_valida = 0;
    int max_distancia = arr[arr.size()-1] - arr[0];
    int min_distancia = arr[1] - arr[0];

    for(int cont = 2; cont < arr.size(); cont++){
        int distancia_rod = arr[cont] - arr[cont - 1];
        if (min_distancia > distancia_rod){
            min_distancia = distancia_rod;
        }
    }

    for(int cont = min_distancia; cont <= max_distancia; cont++){
        if (distancia_valida(cont, arr, num_vacas) == 1){
            if(cont > maior_distancia_valida){
                maior_distancia_valida = cont;
            }
        }
    }

    return maior_distancia_valida;
}

int main() {
    int num_baias, vacas;
    cin >> num_baias;
    cin >> vacas;

    vector<int> baias;
    enter_values_in_vectors(baias, num_baias);
    sort(baias.begin(), baias.end());
    cout << distancia(baias, vacas) << endl;

    return 0;
}
