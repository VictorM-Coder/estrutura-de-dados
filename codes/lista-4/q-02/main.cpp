#include <bits/stdc++.h>
#include "Raios.hpp"

using namespace std;


int main(){


    int n;
    cin >> n;

    Raios R(500,500);

    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        R.add(x,y);
    }
    cout << R.mesmo_lugar() << endl;


}