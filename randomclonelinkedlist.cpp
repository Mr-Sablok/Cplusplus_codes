//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com

#include <iostream>
#include <map>
#include <ctime>
#include <stdlib.h>
using namespace std;

class specialNode {
public:
    specialNode * random;
    specialNode * next;
    int data;
    specialNode(int d) {
        data = d;
        random = NULL;
        next = NULL;
    }
};

void printLL(const specialNode * head) {
    while (head) {
        cout << head->data << "(" << head->random->data << ")-->";
        head = head->next;
    }
    cout << endl;
}

//creation of the randomList
//**********************************************************
specialNode* randomNode(specialNode * head, const int len) {
    // srand(time(NULL));  
    //this is wrong since srand is called again and again
    //time(NULL) gives the total number of SECONDS elapsed from 1-Jan-1970 

    int r_num = rand();
    r_num %= len;

    specialNode * randNode = head;
    while (r_num > 0) {
        randNode = randNode->next;
        r_num--;
    }
    return randNode;
}

void setRandom(specialNode* head) {
    int len = 0;
    specialNode * tmp = head;
    while (tmp) tmp = tmp->next, ++len; //comma as a seperator

    srand(time(0));    //Correct...See line 32
    tmp = head;
    while (tmp) {
        tmp->random = randomNode(head, len);
        tmp = tmp->next;
    }
}

specialNode* createLL() {
    specialNode * head = NULL;
    specialNode * tail = NULL;

    while (true) {
        int x;
        cin >> x;
        if (x == -1) break;

        specialNode * tmp = new specialNode(x);
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
    setRandom(head);
    return head;
}


int main() {

    specialNode * head = createLL();
    // setRandom(head); //included in createLL
    printLL(head);
    
    specialNode * cloneLL(const specialNode*);    //declaration
    //This way you can use function and define them below the calling function
    //Many students are not able to clear the first round due to this restriction
    
    specialNode * clone = cloneLL(head);
    printLL(clone);


}

//cloning
//*********************************************************
specialNode* duplicate(const specialNode* head) {
    specialNode * newList = NULL;
    specialNode * tail = NULL;
    while (head) {
        specialNode * tmp = new specialNode(head->data);
        if (newList == NULL) {
            newList = tmp;
            tail = tmp;
            head = head->next;
            continue;
        }
        tail->next = tmp;
        tail = tail->next;
        head = head->next;
    }
    return newList;
}

specialNode* cloneLL(const specialNode * head) {
    specialNode * clone = duplicate(head);

    map<const specialNode* , specialNode*> table;
    const specialNode * a = head;
    specialNode * b = clone;

    while (a && b) {
        table[a] = b;   //table.put(a, b);
        //recording just addresses
        a = a->next;
        b = b->next;
    }

    //initialising random pointers
    a = head;
    b = clone;

    while (a && b) {
        b->random = table[a->random];
        a = a->next;
        b = b->next;
    }
    return clone;
}