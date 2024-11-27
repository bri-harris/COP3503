#pragma once
#include <iostream>
#include <vector>
struct Node;
using namespace std;

template<typename T>
class LinkedList {
public:
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node(const T& dataPar);
    };

    /*-----------------------------------------------Constructor / Destructor-------------------------------------------*/
    LinkedList();
    ~LinkedList();

    /*-----------------------------------------Copy Constructor / assignment operator------------------------------------*/
    LinkedList(const LinkedList& other);
    LinkedList& operator=(const LinkedList& other);

    /*------------------------------------------------other operators-----------------------------------------------------*/
    const T& operator[](unsigned int index) const;
    T& operator[](unsigned int index);
    bool operator==(const LinkedList<T>& rhs) const;

    /*----------------------------------------------- helper functions --------------------------------------------------*/
    void deallocateHelper();
    void CopyFromObj(const LinkedList& other);

    /*--------------------------------------------------Behaviors-------------------------------------------------------*/
    void PrintForward() const;
    void PrintReverse() const;
    void PrintForwardRecursive(const Node* node) const;
    void PrintReverseRecursive(const Node* node) const;

    /*-------------------------------------------------Accessors--------------------------------------------------------*/
    unsigned int NodeCount() const;
    Node* Head();
    const Node* Head() const;
    Node* Tail();
    const Node* Tail() const;
    const Node* GetNode(unsigned int index) const;
    Node* GetNode(unsigned int index);
    const Node* Find(const T& dataPar) const;
    Node* Find(const T& dataPar);
    void FindAll(vector<Node *>& outData, const T& value) const;

    /*-------------------------------------------------Insertion--------------------------------------------------------*/
    void AddHead(const T& dataPar);
    void AddTail(const T& dataPar);
    void AddNodesHead(const T* dataPar, unsigned int count);
    void AddNodesTail(const T* dataPar, unsigned int count);
    void InsertBefore(Node* node, const T& dataPar);
    void InsertAfter(Node* node, const T& dataPar);
    void InsertAt(const T& dataPar, unsigned int index);

    /*-------------------------------------------------Removal--------------------------------------------------------*/
    bool RemoveHead();
    bool RemoveTail();
    bool RemoveAt(unsigned int index);
    unsigned int Remove(const T& dataPar);
    void Clear();

    /*--------------------------------------------Private Data Members---------------------------------------------------*/
private:
    Node* _head;
    Node* _tail;
    unsigned int _nodeCount = 0;
};


/*-------------------------------------------------Constructor / Destructor---------------------------------------------*/

template<typename T>
LinkedList<T>::Node::Node(const T& dataPar) {
    data = dataPar;
    next = nullptr;
    prev = nullptr;
}

template<typename T>
LinkedList<T>::LinkedList() {
    _head = nullptr;
    _tail = nullptr;
    _nodeCount = 0;
}

template<typename T>
LinkedList<T>::~LinkedList() {
    deallocateHelper();
}


/*-------------------------------------------Copy Constructor / assignment operator--------------------------------------*/
template<typename T>
LinkedList<T>::LinkedList(const LinkedList& other) {
    CopyFromObj(other);
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& other) {
    if (this == &other) return *this;

    deallocateHelper();
    CopyFromObj(other);

    return *this;
}

/*------------------------------------------------other operators-----------------------------------------------------*/
template<typename T>
T& LinkedList<T>::operator[](unsigned int index) {
    if (index >= _nodeCount) throw out_of_range("Index out of range.");
    Node* temp = GetNode(index);
    return temp->data;
}

template<typename T>
const T& LinkedList<T>::operator[](unsigned int index) const {
    if (index >= _nodeCount) throw out_of_range("Index out of range.");
    const Node* temp = GetNode(index);
    return temp->data;
}

template<typename T>
bool LinkedList<T>::operator==(const LinkedList<T>& rhs) const {
    if (_nodeCount != rhs._nodeCount) return false;

    for (unsigned int i = 0; i < _nodeCount; i++) {
        if ((*this)[i] != rhs[i]) return false;
    }
    return true;
}

/*------------------------------------------------- helper functions ---------------------------------------------------*/
template<typename T>
void LinkedList<T>::deallocateHelper() {
    //start at head, use a temp pointer
    Node* tempNode = _head;

    //Another temp va, the next node as we traverse
    Node* nextNode;

    //check if temp node even exists
    //loop through the list, grab next node w temp node
    //delete the temp node and move on
    while (tempNode != nullptr) {
        nextNode = tempNode->next;
        delete tempNode;
        tempNode = nextNode;
    }
}

template<typename T>
void LinkedList<T>::CopyFromObj(const LinkedList& other) {
    _nodeCount = 0;
    _head = nullptr;
    _tail = nullptr;

    Node* tempNode = other._head;
    while (tempNode != nullptr) {
        AddTail(tempNode->data);
        tempNode = tempNode->next;
    }
}

/*--------------------------------------------------Behaviors-------------------------------------------------------*/
template<typename T>
void LinkedList<T>::PrintForward() const {
    if (_nodeCount == 0)
        cout << "The List is empty!";
    else {
        Node* currNode = _head;
        while (currNode != nullptr) {
            cout << currNode->data << endl;
            currNode = currNode->next;
        }
    }
}

template<typename T>
void LinkedList<T>::PrintReverse() const {
    if (_nodeCount == 0)
        cout << "The List is empty!";
    else {
        Node* currNode = _tail;
        while (currNode != nullptr) {
            cout << currNode->data << endl;
            currNode = currNode->prev;
        }
    }
}

template<typename T>
void LinkedList<T>::PrintForwardRecursive(const Node* node) const {
    if (node == _tail) cout << node->data << endl;
    else {
        cout << node->data << endl;
        PrintForwardRecursive(node->next);
    }
}

template<typename T>
void LinkedList<T>::PrintReverseRecursive(const Node* node) const {
    if (node == _head) cout << node->data << endl;
    else {
        cout << node->data << endl;
        PrintReverseRecursive(node->prev);
    }
}

/*-------------------------------------------------Accessors--------------------------------------------------------*/
template<typename T>
unsigned int LinkedList<T>::NodeCount() const {
    return _nodeCount;
}

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::Head() {
    return _head;
}

template<typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Head() const {
    return _head;
}

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::Tail() {
    return _tail;
}

template<typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Tail() const {
    return _tail;
}

template<typename T>
const typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) const {
    if (index >= _nodeCount) throw out_of_range("Index out of range.");

    const Node* tempNode = _head;
    for (unsigned int i = 0; i < index; i++) {
        tempNode = tempNode->next;
    }

    return tempNode;
}

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) {
    if (index >= _nodeCount) throw out_of_range("Index out of range.");

    Node* tempNode = _head;
    for (unsigned int i = 0; i < index; i++) {
        tempNode = tempNode->next;
    }

    return tempNode;
}

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::Find(const T& dataPar) {
    Node* tempNode = _head;

    while (tempNode != nullptr) {
        if (tempNode->data == dataPar) return tempNode;
        tempNode = tempNode->next;
    }

    return tempNode;
}


template<typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Find(const T& dataPar) const {
    const Node* tempNode = _head;

    while (tempNode != nullptr) {
        if (tempNode->data == dataPar) return tempNode;
        tempNode = tempNode->next;
    }

    return tempNode;
}

template<typename T>
void LinkedList<T>::FindAll(vector<Node *>& outData, const T& value) const {
    Node* tempNode = _head;
    while (tempNode != nullptr) {
        if (tempNode->data == value) {
            outData.push_back(tempNode);
        }
        tempNode = tempNode->next;
    }
}


/*-------------------------------------------------Insertion--------------------------------------------------------*/

template<typename T>
void LinkedList<T>::AddHead(const T& dataPar) {
    Node* newNode = new Node(dataPar);

    if (_head == nullptr) {
        _head = newNode;
        _tail = newNode;
        newNode->next = nullptr;
        newNode->prev = nullptr;
    } else {
        newNode->next = _head;
        _head->prev = newNode;
        _head = newNode;
        newNode->prev = nullptr;
    }
    _nodeCount++;
}

template<typename T>
void LinkedList<T>::AddTail(const T& dataPar) {
    Node* newNode = new Node(dataPar);

    if (_tail == nullptr) {
        _tail = newNode;
        _head = newNode;
        newNode->next = nullptr;
        newNode->prev = nullptr;
    } else {
        _tail->next = newNode; //Current tail's next pointer now points to newNode
        newNode->prev = _tail; //set newNode's previous pointer to the current tail
        _tail = newNode; // set the tail pointer to newNode
        newNode->next = nullptr; //set new tail pointer's next pointer to nullptr
    }
    _nodeCount++;
}

template<typename T>
void LinkedList<T>::AddNodesHead(const T* dataPar, unsigned int count) {
    for (unsigned int i = count - 1; ((i >= 0) & (i < count)); i--) {
        Node* newNode = new Node(dataPar[i]);
        AddHead(newNode->data);
        delete newNode;
    }
}

template<typename T>
void LinkedList<T>::AddNodesTail(const T* dataPar, unsigned int count) {
    for (unsigned int i = 0; i < count; i++) {
        Node* newNode = new Node(dataPar[i]);
        AddTail(newNode->data);
        delete newNode;
    }
}

template<typename T>
void LinkedList<T>::InsertAt(const T& dataPar, unsigned int index) {
    if (index > _nodeCount) throw out_of_range("Index out of range.");
    if (index == _nodeCount) AddTail(dataPar);
    else if (index == 0) AddHead(dataPar);
    else {
        Node* newNode = new Node(dataPar);
        Node* findBefore = GetNode(index - 1);
        Node* findAfter = GetNode(index);

        newNode->next = findAfter;
        findAfter->prev = newNode;
        newNode->prev = findBefore;
        findBefore->next = newNode;

        _nodeCount++;
    }
}

template<typename T>
void LinkedList<T>::InsertAfter(Node* node, const T& dataPar) {
    //create a new node
    Node* newNode = new Node(dataPar);

    if (node == _tail) AddTail(dataPar);
    else {
        //pointer to previous node
        Node* nextNode = node->next;
        nextNode->prev = newNode;
        newNode->next = nextNode;

        newNode->prev = node;
        node->next = newNode;

        _nodeCount++;
    }
}

template<typename T>
void LinkedList<T>::InsertBefore(Node* node, const T& dataPar) {
    //create a new node
    Node* newNode = new Node(dataPar);

    if (node == _head) AddHead(dataPar);
    else {
        //pointer to previous node
        Node* prevNode = node->prev;
        prevNode->next = newNode;
        newNode->prev = prevNode;

        newNode->next = node;
        node->prev = newNode;

        _nodeCount++;
    }
}


/*-------------------------------------------------Removal--------------------------------------------------------*/

template<typename T>
bool LinkedList<T>::RemoveHead() {
    if (_head == nullptr) return false;

    Node* tempNode = _head->next;
    delete _head;
    _head = tempNode;

    if (_head != nullptr)_head->prev = nullptr;
    else {
        _tail = nullptr;
    }
    _nodeCount--;
    return true;
}

template<typename T>
bool LinkedList<T>::RemoveTail() {
    if (_tail == nullptr) return false;


    Node* tempNode = _tail->prev;
    delete _tail;
    _tail = tempNode;

    if (_tail != nullptr)_tail->next = nullptr;
    else {
        _head = nullptr;
    }
    _nodeCount--;
    return true;
}

template<typename T>
bool LinkedList<T>::RemoveAt(unsigned int index) {
    if (index >= _nodeCount) return false;
    if (index == _nodeCount - 1) RemoveTail();
    if (index == 0) RemoveHead();

    Node* prevNode = GetNode(index - 1);
    Node* nodeToDel = prevNode->next;
    Node* nextNode = nodeToDel->next;

    prevNode->next = nodeToDel->next;
    nextNode->prev = prevNode;
    delete nodeToDel;

    _nodeCount--;

    return true;
}

template<typename T>
unsigned int LinkedList<T>::Remove(const T& dataPar) {
    unsigned int removed = 0;
    Node* tempNode = _head;

    while (tempNode != nullptr) {
        if (tempNode->data == dataPar) {
            if (tempNode == _head) {
                RemoveHead();
            }
            if (tempNode == _tail) {
                RemoveTail();
                removed++;
                _nodeCount--;
                return removed;
            } else {
                //get pointer to prev & next nodes
                //tempNode is to be deleted, update it to next & create delPointer
                Node* prevNode = tempNode->prev;
                Node* nextNode = tempNode->next;
                Node* nodeToDel = tempNode;
                tempNode = tempNode->next;

                //correct pointers, then delete required node
                prevNode->next = nextNode;
                nextNode->prev = prevNode;
                delete nodeToDel;
            }
            _nodeCount--;
            removed++;
        } else {
            tempNode = tempNode->next;
        }
    }
    return removed;
}

template<typename T>
void LinkedList<T>::Clear() {
    Node* tempNode = _head;
    while (tempNode != nullptr) {
        RemoveHead();
        tempNode = _head;
    }
}
