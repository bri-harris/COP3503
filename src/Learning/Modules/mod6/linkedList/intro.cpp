
struct Node {
    int data;
    struct Node* next;
    Node(int value);
    Node();
};

Node::Node(int value) {
    data = value;
    next = nullptr;
}

Node::Node() {
    next = nullptr;
}


// int main() {
// Node* head = nullptr; //the start of it all
// head = new Node; // create the 1st node

// head->data = 1;
// head->next = nullptr;

// Node* secondNode = new Node;
// secondNode->data = 2;
// secondNode->next = nullptr;

// Node* head = new Node(1);
// Node* second = new Node(2);
//
// head->next = second;

//unnamed nodes
// Node* head = new Node;
// head->next = new Node;
// head->next->data = 2;
//
// head->next->next = new Node; //third node
// head->next->next->data = 3; //third node
//
// Node* last = head->next->next->next;

//Using a loop to traverse a node
//start at the begining
// Node* head = new Node;
// Node* curNode = head;
//
// //∀node which exists, - 1
// for (int i = 0; i < 3; i++)
//     //move forward 1 node
//     curNode = curNode->next;

// better traversal approach
//start at beginning
// Node* head = new Node;
// Node* curNode = head;
//
// //while we arent at the last node
// //(check if node has a valid -> next)
// while (curNode->next != nullptr)
//     curNode = curNode->next;
//
//
// //
// //
// //
// return 0;
/
}
