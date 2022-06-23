#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class ListNode {
public:

    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* readList(){
    int n;
    cin >> n;
    ListNode * head;
    for(int i = 0; i < n; i++){
        ListNode * ptr;
        int x;
        cin >> x;
        if( i == 0){
            head = new ListNode(x);
            ptr = head;
        }else{
            ptr->next = new ListNode(x, nullptr);
            ptr = ptr->next;
        }
    }

    return head;

}

void print_list(ListNode * head){

    for(auto ptr = head; ptr != nullptr; ptr = ptr->next){
        cout << ptr->val << endl;
    }

}

bool someAux(ListNode * head){
    if (head->next == nullptr){
        if (head->val + 1 == 10){
            head->val = 0;
            return 1;
        }else{
            head->val += 1;
            return 0;
        }
    }

    head->val += someAux(head->next);

    if (head->val == 10){
        head->val = 0;
        return 1;
    }else{
        return 0;
    }
}

ListNode* someUm(ListNode *head){
    if (someAux(head) == 1){
        ListNode *out = new ListNode(1, head);
        return out;
    }
    return head;
}




int main(){

    ListNode * head = readList();
    head = someUm(head);
    print_list(head);
    return 0;
}
