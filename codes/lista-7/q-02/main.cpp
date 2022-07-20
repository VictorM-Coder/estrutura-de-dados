#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

using std::cin;
using std::cout;
using std::endl;
using std::vector;




class Estudante{
    public:
        string nome;
        int h;
        Estudante(){}
        Estudante(string nome, int h) : nome(nome), h(h) {}

};

/*
Binary function that accepts two elements in the range as arguments, and returns a value convertible
to bool. The value returned indicates whether the element passed as first argument is considered to
go before the second in the specific strict weak ordering it defines.
The function shall not modify any of its arguments.
This can either be a function pointer or a function object.
*/

bool comp(const Estudante e1, const Estudante e2){
    return e1.h > e2.h;
}

bool compAlfabetico(const Estudante e1, const Estudante e2){
    return e1.nome < e2.nome;
}


int main(){
    int n, t;

    cin >> n >> t;

    vector <Estudante> estudantes;
    vector<vector<Estudante>> times(t);

    estudantes.resize(n);

    for(int i = 0; i < n; i++){
        cin >> estudantes[i].nome >> estudantes[i].h;
    }

    //Ordena os estudantes em ordem decrescente
    sort(estudantes.begin(), estudantes.end() , comp );

    for(int cont = 0, cont2 = 0; cont < n; cont++){
        times[cont2].push_back(estudantes[cont]);

        if(cont2 == t-1){
            cont2 = 0;
        }else{
            cont2++;
        }
    }

    for(int cont =  0; cont < t; cont++){
        cout << "Time "<< cont+1 << endl;

        vector<Estudante> time = times[cont];
        sort(time.begin(), time.end(), compAlfabetico);
        for(int cont2 = 0; cont2  < times[cont].size(); cont2++){
            cout << time[cont2].nome << endl;
        }
        cout << endl;
    }
    cout <<endl;

}