#include <iostream>
#include <sstream>
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
    BTree(){
    }

    void clone(stringstream& ss, Node ** elo){
        string value;
        ss >> value;
        if(value == "#")
            return;
        int num;
        stringstream(value) >> num;
        *elo =  new Node(num);
        clone(ss, &(*elo)->left);
        clone(ss, &(*elo)->right);
    }

    BTree(string serial){
        stringstream ss(serial);
        clone(ss, &root);
    }
    void __destroy(Node * node){
        if(node == nullptr)
            return;
        __destroy(node->left);
        __destroy(node->right);
        delete node;
    }

    ~BTree(){
        __destroy(this->root);
    }

    int sum(Node * root){
        if(root == nullptr)return 0;

        return root->value + sum(root->right) + sum(root->left);
    }

    int min(Node * root){
        if (root->left == nullptr && root->right == nullptr){
            return root->value;
        }

        if (root->right == nullptr){
            return std::min(root->value, min(root->left));
        }

        if (root->left == nullptr){
            return std::min(root->value, min(root->right));
        }

        int value = std::min(root->value, min(root->left));
        value = std::min(value, min(root->right));
        return value;
    }

};




int main(){
    string line;
    getline(cin, line);
    BTree bt(line);
    cout << bt.sum(bt.root) << " " << bt.min(bt.root) << "\n";
}