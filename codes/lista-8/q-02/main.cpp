#include <iostream>
#include <sstream>
#include <string>

#define MARKER "#"
using namespace std;

struct Node{
    int value;
    Node * left;
    Node * right;
    Node(int value = 0, Node * left = nullptr, Node * right = nullptr){
        this->value = value;
        this->left = left;
        this->right = right;
    }
};

struct BTree{
    Node * root {nullptr};
    BTree(string serial){
        stringstream serialStream(serial);
        addItem(root, serialStream);
    }

    void addItem(Node * &node, stringstream & serial){
        string val;
        serial >> val;

        if (val == MARKER){
            return;
        }

        int value;
        stringstream(val) >> value;
        node = new Node(value);

        addItem(node->left, serial);
        addItem(node->right, serial);
    }

    ~BTree(){ //destrutor da árvore
        __destroy(this->root);
    }

    void __destroy(Node * node){
        if(node == nullptr)
            return;
        __destroy(node->left);
        __destroy(node->right);
        delete node;
    }

    void showAux(Node * node, string serial){
        if(node != nullptr && (node->left != nullptr || node->right != nullptr)){
            showAux(node->left, serial + "l");
        }

        for(int cont = 0; cont < serial.size(); cont++){
            cout << "....";
        }

        if(node == nullptr){
            cout << "#" << endl;
            return;
        }

        cout << node->value << endl;

        if(node != nullptr && (node->left != nullptr || node->right != nullptr)){
            showAux(node->right, serial + "r");
        }

    }
    void show(){
        showAux(root, "");
    }
};

int main(){
    string line;
    getline(cin, line);
    BTree bt(line);
    bt.show();
}