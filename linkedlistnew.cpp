//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};  //it is must

Node* createLL() {
    Node * head = NULL;
    Node * tail = NULL;

    while (true) {
        int x;
        cin >> x;
        if (x == -1) break;

        Node * tmp = new Node(x);
        if (head == NULL) {
            //we are inserting the very first node
            head = tail = tmp;
        }
        else {
            //this node is NOT the starting node
            (*tail).next = tmp;
            //tail ->next = tmp
            tail = tmp;
        }
    }
    return head;
}

void printLL(Node* head) {
    Node * curNode = head;
    while (curNode != NULL) {
        cout << curNode->data << "-->";
        curNode = curNode->next;
    }
    cout << endl;
}

int lengthLL(Node * head) {
    int cnt = 0;
    Node* curNode = head;
    while (curNode) {
        ++cnt;
        curNode = curNode->next;
    }
    return cnt;
}

typedef pair<Node*, Node*> pnn;

pair<Node*, Node*> findEle(Node* head, int eleToDelete) {
    //returns the node prev to eleToDelete
    //NULL if element is not found

    if (head == NULL) {
        pnn p(NULL, NULL);
        return p;
    }

    //make sure that I have atleast one element
    if (head->data == eleToDelete) {
        return pnn(NULL, head);
    }

    pnn status = findEle(head->next, eleToDelete);
    if (status.first != NULL) return status;
    else if (status.second == head->next) {
        status.first = head;
        return status;
    }

}

Node* deleteNode(Node* head, int eleToDelete) {
    pnn status = findEle(head, eleToDelete);

    if (status.second == NULL) {
        return head;
    }

    if (status.second == head) {
        //head to be deleted
        head = head->next;
        delete status.second;
        return head;
    }
    else {
        Node * prevNode = status.first;
        prevNode->next = status.second->next;
        delete status.second;
        return head;
    }
}

Node * midPointLL(Node* head) {
    //SET
    Node * slow = head;
    Node * fast = head;

    //GO
    while (slow && fast && fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* bubbleSort(Node* head) {
            
     Node *cur=head;
     Node *prev=NULL;

     Node *ahead=cur->next;

     
     
     if(temp->data<temp->next->data)
}//2->7->4->5->6


Node* reverse(Node *head){

     Node *current=head;
      
     reverse(head,current,current->next);
}



cycle(Node *head){

    
    Node *slptr=head;
    node *fstptr=head;
    if(head->next&&head->next->next){
        fstptr=fstptr->next->next;
    }

    // if(fstptr&&fstptr->next&&slptr){

    //     fstptr=fsptr->next;
    //     count++;
    // }
     
     while(slptr!=fstptr){

        if(!fstptr){
            cout<<"no cycle";
            return;
        }
        slptr++;
        fstptr++;

     }

     //so gap was two now it is zero


    

}



Node * last5th(Node* head) {
    //SET
    Node* first = head;
    Node* fifth = head;

    int curPos = 1;
    while (curPos != 5 && fifth != NULL) {
        fifth = fifth->next;
        ++curPos;
    }

    if (fifth == NULL) return NULL;

    //GO
    while (first && fifth && fifth->next) {
        first = first->next;
        fifth = fifth->next;
    }
    return first;
}


Node* mergeSorted(Node* A, Node* B) {
    if (A == NULL){
        //A is empty 
        return B;
    }

    if (B == NULL){
        return A;
    }

    // I can make sure that BOTH of them have atleast one element
    Node * mergedList = NULL;
    if (A->data < B->data){
        mergedList = A;
        mergedList->next = mergeSorted(A->next, B);
    }
    else {
        mergedList = B;
        mergedList->next = mergeSorted(A, B->next);
    }
    return mergedList;
}

Node * mergeSort(Node * unsortedList){
    if (unsortedList == NULL || unsortedList->next == NULL){
        //either 1 or zero element
        return unsortedList;
    }

    Node * midpt = midPointLL(unsortedList);
    Node * A = unsortedList;
    Node * B = midpt->next;
    midpt->next = NULL; //break from midpt
    A = mergeSort(A);
    B = mergeSort(B);
    return mergeSorted(A, B);
}



int main() {
    // Node * head = createLL();
    // printLL(head);

    // int len = lengthLL(head);
    // cout << len << endl;

    // int eleToDelete;
    // cin >> eleToDelete;
    // Node * listAfterDeletion = deleteNode(head, eleToDelete);
    // printLL(listAfterDeletion);

    // Node * midPtr = midPointLL(head);
    // cout << midPtr << endl;
    // if (midPtr) cout << midPtr->data << endl;

    // Node * _5thNodeFromLast = last5th(head);
    // if (_5thNodeFromLast) cout << _5thNodeFromLast->data << endl;

    // Node * A = createLL();
    // Node * B = createLL();
    // printLL(A);
    // printLL(B);
    // Node * res = mergeSorted(A, B);
    // printLL(res);

    Node * head = createLL();
    printLL(head);
    head = mergeSort(head);
    printLL(head);

}