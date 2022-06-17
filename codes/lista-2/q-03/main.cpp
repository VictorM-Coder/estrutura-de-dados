#include <bits/stdc++.h>

using namespace std;


class Product {
private:
    string name;
    int price;

public:
    Product(string n, int p) {
        name = n;
        price = p;
    }

    string getName(){
        return this->name;
    }

    bool operator<(const Product & a){
        if( price != a.price){
            return price < a.price;
        }else{
            return name < a.name;
        }
    }
    friend ostream& operator<<(ostream& os, const Product& p);
};

ostream& operator<<(ostream& os, const Product& p){
    os << "(" << p.name << "," << p.price << ")";
    return os;
}

void insert_sort(vector<Product> &products, Product product){
    products.push_back(product);
    if (products.size() > 1){
        for (int i = 1; i < products.size(); ++i) {
            Product key = products[i];
            int previous_index = i - 1;

            while(previous_index >= 0 && key < products[previous_index]){
                products[previous_index + 1] = products[previous_index];
                previous_index -= 1;
            }
            products[previous_index + 1] = key;
        }
    }
}

void enter_values_in_vectors(vector<Product> &products, int enters){
    string name;
    int price;
    for (int cont = 0; cont < enters; cont++){
        cin >> name;
        cin >> price;
        Product product = *new Product(name, price);
        insert_sort(products, product);
    }
}

void print_vector(vector<Product> &vector){
    for (int i = 0; i < vector.size(); i++) {
        cout << vector[i].getName();
        if (i < vector.size()-1) cout << " ";
    }
    cout << endl;
}

int main(){
    int N, M, P, Q;
    cin >> N;
    cin >> M;
    cin >> P;
    cin >> Q;

    vector<Product> section1;
    vector<Product> section2;
    vector<Product> bought_products;

    enter_values_in_vectors(section1, N);
    enter_values_in_vectors(section2, M);

    for(int cont = 0; cont < P; cont++){
        insert_sort(bought_products, section1[cont]);
    }

    for(int cont = 0; cont < Q; cont++){
        insert_sort(bought_products, section2[cont]);
    }

    print_vector(bought_products);
}