#ifndef ORDEREDLIST_H
#define ORDEREDLIST_H

template <typename T>
class OrderedList {
private:
    struct Node {
        T* data;
        Node* prev;
        Node* next;
        Node(T* item) : data(item), next(nullptr), prev(nullptr) {}
    };
    Node* head;
    Node* tail;
    Node* current;
    int size;

public:
    OrderedList();
    ~OrderedList();
    void addItem(T* item);
    T* getItem(T* item);
    bool isEmpty() const;
    int getSize() const;
    T* seeAt(int index);
    T* seeNext();
    T* seePrev();
    void reset();
};

template <typename T>
OrderedList<T>::OrderedList() : head(nullptr), tail(nullptr), current(nullptr), size(0) {}

template <typename T>
OrderedList<T>::~OrderedList() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current->data;
        delete current;
        current = next;
    }
}

template <typename T>
void OrderedList<T>::addItem(T* item) {
    Node* newNode = new Node(item);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        Node* current = head;
        while (current && *(current->data) < *item) {
            current = current->next;
        }
        if ( ! current ) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        } else if (current == head) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        } else {
            newNode->next = current;
            newNode->prev = current->prev;
            current->prev->next = newNode;
            current->prev = newNode;
        }
    }
    size++;
}

template <typename T>
T* OrderedList<T>::getItem(T* item) {
    Node* current = head;
    while (current) {
        if (*(current->data) == *item) {
            T* result = current->data;
            if (current == head) head = current->next;
            if (current == tail) tail = current->prev;
            if (current->prev) current->prev->next = current->next;
            if (current->next) current->next->prev = current->prev;
            delete current;
            --size;
            return result;
        }
        current = current->next;
    }
    return nullptr;
}

template <typename T>
bool OrderedList<T>::isEmpty() const {
    return size == 0;
}

template <typename T>
int OrderedList<T>::getSize() const {
    return size;
}

template <typename T>
T* OrderedList<T>::seeAt(int index) {
    if (index < 0 || index >= size) return nullptr;
    Node* temp = head;
    for (int i = 0; i < index; ++i) {
        temp = temp->next;
    }
    current = temp;
    return current->data;
}

template <typename T>
T* OrderedList<T>::seeNext() {
    if (current && current->next) {
        current = current->next;
        return current->data;
    }
    return nullptr;
}

template <typename T>
T* OrderedList<T>::seePrev() {
    if (current && current->prev) {
        current = current->prev;
        return current->data;
    }
    return nullptr;
}

template <typename T>
void OrderedList<T>::reset() {
    current = head;
}
#endif
