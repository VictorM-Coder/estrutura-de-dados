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


ListNode * intersectionList(ListNode * head1, ListNode * head2){
    if (head1 == nullptr || head2 == nullptr){
        return nullptr;
    }

    if (head1->val == head2->val){
        return new ListNode(head1->val, intersectionList(head1->next, head2->next));
    }

    if (head1->val > head2->val){
        return intersectionList(head1, head2->next);
    }else{
        return intersectionList(head1->next, head2);
    }

}


void printList(ListNode * head){
    for(ListNode * ptr = head; ptr != nullptr; ptr = ptr->next)
        cout << ptr->val << endl;
}



int main(){

    ListNode * head1 = readList();
    ListNode * head2 = readList();

    ListNode * res = intersectionList(head1, head2);


    printList(res);

    return 0;
}
