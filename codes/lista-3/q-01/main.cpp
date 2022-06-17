#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int> &arr, int item){
    int start = 0;
    int end = arr.size()-1;
    int count = 0;

    while(start <= end){
        int mid =  (start+end)/2;
        count++;

        if (arr[mid] == item){
            break;
        }else if(arr[mid] > item){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }

    return count;
}

void enter_values_in_vectors(vector<int> &vetor, int size){
    for (int cont = 0; cont < size; cont++){
        int value;
        cin >> value;
        vetor.push_back(value);
    }
}

void print_vector(vector<int> &vector){
    for (int i = 0; i < vector.size(); i++) {
        cout << vector[i];
        if (i < vector.size()-1) cout << " ";
    }
    cout << endl;
}

int main() {
    int size_vector, questions_size;
    vector<int> arr, questions, iterations;
    cin >> size_vector;
    cin >> questions_size;

    enter_values_in_vectors(arr, size_vector);
    enter_values_in_vectors(questions, questions_size);

    for(int cont = 0; cont < questions_size; cont++){
        iterations.push_back(binary_search(arr, questions[cont]));
    }

    print_vector(iterations);
    return 0;
}
