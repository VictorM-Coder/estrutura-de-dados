#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

void insert_sort(vector<int> &vector, int value){
    if (vector.size() == 1){
        vector.push_back(value);
    }else{
        vector.push_back(value);
        for (int i = 1; i < vector.size(); ++i) {
            int key = vector[i];
            int previous_index = i - 1;

            while(previous_index >= 0 && vector[previous_index] > key){
                vector[previous_index + 1] = vector[previous_index];
                previous_index -= 1;
            }
            vector[previous_index + 1] = key;
        }
    }
}

void enter_values_in_vectors(vector<int> &vetor, vector<int> &out, int enters){
    int comand;
    int value;
    for (int cont = 0; cont < enters; cont++){
        cin >> comand;
        cin >> value;

        if (comand == 1){
            insert_sort(vetor, value);
        }else if (comand == 2){
            out.push_back(vetor[value]);
        } else{
            printf("error");
            exit(0);
        }
    }
}

void print_vector(vector<int> &vector){
    for (int i = 0; i < vector.size(); i++) {
        cout << vector[i] << endl;
    }
}

int main(){
    int size;
    cin >> size;
    vector<int> values;
    vector<int> out;
    enter_values_in_vectors(values, out, size);
    print_vector(out);
    return 0;
}
