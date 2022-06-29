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


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr && l2 == nullptr){
        return nullptr;
    }

    if (l1 == nullptr)return l2;
    if (l2 == nullptr)return l1;

    if (l1->val > l2->val){
        return new ListNode(l2->val, mergeTwoLists(l1, l2->next));
    }else{
        return new ListNode(l1->val, mergeTwoLists(l1->next, l2));
    }

}

ListNode* readList(){
    int n;
    cin >> n;
    ListNode * head = nullptr;
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


int main(){

    ListNode * list1 = readList();
    ListNode * list2 = readList();
    ListNode * head = mergeTwoLists(list1, list2);

    for(ListNode * ptr = head; ptr != nullptr; ptr = ptr->next)
        cout << ptr->val << endl;

    return 0;
}

