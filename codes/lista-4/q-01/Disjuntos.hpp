#ifndef DISJUNTOS_HPP
#define DISJUNTOS_HPP

#include <bits/stdc++.h>

using namespace std;

class Disjuntos{

private:
    vector<int> numbers;

public:

    Disjuntos(int n){
        for(int cont = 0; cont < n; cont++){
            numbers.push_back(cont);
        }
    }

    void une(int x, int y){
        numbers[y] = numbers[x];
    }

    int mesmo(int x, int y){
        if ((numbers[x] == numbers[y])){
            return 1;
        }else{
            return 0;
        }
    }
};
#endif