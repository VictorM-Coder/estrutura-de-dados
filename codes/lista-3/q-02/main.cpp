#include <iostream>
#include <vector>
using namespace std;

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


void reverse(vector<int> &arr, int start, int end){
    while (start < end){
        int aux = arr[start];
        arr[start] = arr[end];
        arr[end] = aux;
        start++;
        end--;
    }
}

void tapioca_sort(vector<int> &arr, vector<int> &out, int start, int mark){
    if (mark < 1){
        out.push_back(0);
        return;
    }

    if (arr.size() ==  1){
        out.push_back(0);
        return;
    }

    if (arr.size() ==  2){
        if (arr[start] < arr[mark]){
            out.push_back(0);
        }else{
            reverse(arr, start, mark);
            out.push_back(arr.size() - mark);
            out.push_back(0);
        }
        return;
    }

    int bigger = mark;
    for(int index = start; index >= 0; index--){
        if (arr[index] > arr[bigger]){
            bigger = index;
        }
    }
    if (bigger == mark){
        tapioca_sort(arr, out, mark-2, mark-1);
        return;
    }else{
        start = bigger;
    }

    if (arr[start] > arr[mark]){
        if (start == 0){
            reverse(arr, 0, mark);
            out.push_back(arr.size() - mark);
            tapioca_sort(arr, out, mark-2, mark-1);
            return;
        }else{
            reverse(arr, 0, start);
            out.push_back(arr.size() - start);
            reverse(arr, 0, mark);
            out.push_back(arr.size() - mark);
            tapioca_sort(arr, out, mark-2, mark-1);
            return;
        }
    }else{
        tapioca_sort(arr, out, mark-2, mark-1);
    }
}

int main() {
    int size;
    vector<int> arr, out;

    cin >> size;
    enter_values_in_vectors(arr, size);
    tapioca_sort(arr, out, arr.size()-2, arr.size()-1);
    print_vector(arr);
    print_vector(out);
    return 0;
}
