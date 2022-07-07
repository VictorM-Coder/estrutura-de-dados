#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    vector<int> inputs;
    stack <int> indexs;
    vector<int> out;
    int nextBigger = 0;
    int size;

    cin >> size;

    for(int cont = 0; cont < size; cont++){
        int value;
        cin >> value;
        inputs.push_back(value);
        out.push_back(-1);

        if (!indexs.empty()){
            while(value > inputs[indexs.top()]){
                out[indexs.top()] = cont;
                indexs.pop();
                if (indexs.empty())break;
            }
        }

        indexs.push(cont);
    }

    for(int cont  = 0; cont < size; cont++){
        cout << out[cont];

        if (cont != size-1){
            cout << " ";
        }else{
            cout << endl;
        }
    }

    return 0;
}
