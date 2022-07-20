#include <iostream>
#include <queue>
#include <vector>
#include <list>

using namespace std;

bool ePossivel(queue<int> gasolina, queue<int>distancias, int sobra){
    if (gasolina.empty()){
        return true;
    }

    if(sobra + gasolina.front() >= distancias.front()){
        sobra = sobra + gasolina.front() - distancias.front();
        gasolina.pop();
        distancias.pop();
        return ePossivel(gasolina, distancias, sobra);
    }

    return false;
}

int main() {
    queue<int> gasolina;
    queue<int> distancias;
    int tam;

    cin >> tam;

    for(int cont = 0; cont < tam; cont++){
        int bomba, distancia;
        cin >> bomba >> distancia;

        gasolina.push(bomba);
        distancias.push(distancia);
    }



    int index = 0;
    for(int cont= 0; cont < tam; cont++){
        if (ePossivel(gasolina, distancias, 0)){
            index = cont;
            break;
        }else{
            gasolina.pop();
            distancias.pop();
        }
    }

    cout << index << endl;

    return 0;
}
