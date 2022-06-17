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

ListNode* specialList(ListNode* head){
    if(head->next == nullptr)return head;
    if (head->next->next == nullptr){
        head->next = nullptr;
        return head;
    }

    ListNode* aux = head->next;
    head->next = head->next->next;
    head->next = specialList(head->next);
    return head;
}

ListNode* oddEvenList(ListNode* head){

}


int main(){
    int n;
    ListNode * head= nullptr;
    cin >> n;
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

    head = oddEvenList(head);

    for(ListNode * ptr = head; ptr != nullptr; ptr = ptr->next)
        cout << ptr->val << endl;

    return 0;
}