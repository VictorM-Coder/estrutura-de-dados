#ifndef RAIOS_HPP
#define RAIOS_HPP

#include <bits/stdc++.h>

using namespace std;

class Raios{

private:
    int **quadrante;
    int caiu_no_mesmo_lugar = 0;
public:

    Raios(int n, int m){
        quadrante = static_cast<int **>(malloc((n+1) * sizeof(int *)));

        for(int cont = 0; cont <= n; cont++){
            quadrante[cont] = static_cast<int *>(malloc((m+1) * sizeof(int)));
        }

        for(int c = 0; c <= n; c++){
            for(int l = 0; l <= m; l++){
                quadrante[c][l]= 0;
            }
        }
    }

    void add(int x, int y){
        if (quadrante[x][y] == 1){
            caiu_no_mesmo_lugar = 1;
        }else{
            quadrante[x][y] = 1;
        }

    }

    int mesmo_lugar(){
        return caiu_no_mesmo_lugar;
    }
};


#endif