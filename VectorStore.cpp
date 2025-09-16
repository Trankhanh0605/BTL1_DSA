#include "VectorStore.h"

// ----------------- ArrayList Implementation -----------------
template <class T>
void ArrayList<T>::ensureCapacity(int cap) {
//TODO
if (cap<=capacity) return;
int newCap=capacity*1.5;
if (newCap<cap) newCap=cap;
T* newData=new T [newCap];
for (int i=0; i<count;++i) {
    newData[i]=data[i];
}
delete[]data;
data=newData;
capacity=newCap;
}

template <class T>
ArrayList<T>::ArrayList(int initCapacity = 10) {
    // TODO
if (initCapacity<0) initCapacity=10;
capacity=initCapacity;
count=0;
data=new T[capacity];
}

template <class T>
ArrayList<T>::ArrayList(const ArrayList<T>& other) {
    // TODO
    capacity=other.capacity;
    count=other.count;
    data=new T[capacity];
    for (int i=0; i<count; i++) {
        data[i]=other.data[i];
    }
}   

template <class T>
ArrayList<T>::~ArrayList() {
    // TODO
    delete[]data;
    data=nullptr;
    capacity=count=0;
}

// TODO: implement other methods of ArrayList
template<class T>
ArrayList<T>&  ArrayList<T>::operator=(const ArrayList<T>& other) {
    if (this==&other) return *this;
    delete[]data;
    capacity=other.capacity;
    count=other.count;
    data=new T[capacity];
    for (int i=0; i<count; ++i) {
        data[i]=other.data[i];
    }
    return *this;
}

template <class T>
void ArrayList<T> ::add(T e) {
    ensureCapacity(count+1);
    data[count]=e;
    count++;
}

template<class T>
void ArrayList<T>::add(int index, T e) {
if (index<0||index>count) {
    throw out_of_range("Index is invalid!");
}
ensureCapacity(count+1);
for (int i=count; i>index; --i) {
    data[i]=data[i-1];
}
data[index]=e;
count++;
}

template<class T>
T ArrayList<T>:: removeAt(int index) {
if (index<0||index>=count) {
    throw out_of_range("Index is invalid!");
}

T removedItem=data[index];
for (int i=index; i<count-1;++i) {
    data[i]=data[i+1];
}
count--;

return removedItem;
}

template <class T>
bool ArrayList<T>::empty() const {
if (count==0) return true;
else return false;
}

template<class T>
int ArrayList<T>::size() const {
    return count;
}

template<class T>
void ArrayList<T>:: clear() {
    delete[]data;
    count=0;
    capacity=10;
    data=new T[capacity]; 
}

template<class T>
T& ArrayList<T>:: get(int index) {
    if (index<0||index>=count) throw out_of_range("Index is invalid!");
    return data[index];
}

template<class T>
void ArrayList<T>:: set(int index, T e) {
    if (index<0||index>=count) throw out_of_range("Index is invalid!");
    data[index]=e;
}

template<class T>
int ArrayList<T>:: indexOf(T item) const {
    for (int i=0; i<count; ++i) {
        if (data[i]==item) {
            return i;
        }
    }
    return -1;
}

template<class T>
bool ArrayList<T>:: contains(T item) const {
    for (int i=0; i<count; i++) {
        if (data[i]==item) return true;
    }
    return false;
}

template<class T> 
string ArrayList<T>:: toString(string (*item2str)(T&) = 0) const {
stringstream ss;
ss<<"[";
for (int i=0; i<count; ++i) {
    if (i>0) ss<<",";
    if (item2str!=NULL) ss<<item2str(data[i]);
    else ss<<data[i];
}
ss<<"]";
return ss.str();
}

template <class T> 
typename ArrayList<T>:: Iterator ArrayList<T>::begin() {
    return Iterator(this, 0);
}

template <class T> 
typename ArrayList<T>:: Iterator ArrayList<T>::end() {
    return Iterator(this, count);
}




// ----------------- Iterator of ArrayList Implementation -----------------
template <class T>
ArrayList<T>::Iterator::Iterator (ArrayList<T>* pList, int index) {
    // TODO
this->pList=pList;
this->cursor=index;
}

// TODO: implement other methods of ArrayList::Iterator
template <class T> 
typename ArrayList<T>:: Iterator&  ArrayList<T>::Iterator::operator=(const Iterator& other) {
if (this!=&other) {
    this->cursor=other.cursor;
    this->pList=other.pList;
}
}

template<class T>
T& ArrayList<T>::Iterator::operator*() {
if (pList==NULL||cursor<0||cursor>=pList->count) throw out_of_range("Iterator is out of range!");
return pList->data[cursor];
} 

template <class T>
bool ArrayList<T> :: Iterator :: operator!=(const Iterator& other) const {
    if ((this->pList!=other.pList) ||(this->cursor!=other.cursor)) return true;
    return false;
}

template <class T> 
typename ArrayList<T>:: Iterator& ArrayList<T>::Iterator::operator++() {
if (cursor>=pList->count) throw out_of_range("Iterator cannot advance past end!");
++cursor;
return *this; 
}

template <class T> 
typename ArrayList<T>:: Iterator ArrayList<T>::Iterator::operator++(int) {
if (cursor>=pList->count) throw out_of_range("Iterator cannot advance past end!");
Iterator temp=*this;
++cursor;
return temp;
}

template<class T>
typename ArrayList<T>:: Iterator& ArrayList<T>:: Iterator::operator--() {
    if (cursor==pList->count) cursor=pList->count-1;
    if (cursor<0) throw out_of_range("Iterator cannot move before begin!") ;
    --cursor;    
    return *this;
}

template <class T> 
typename ArrayList<T>:: Iterator ArrayList<T>:: Iterator::operator--(int) {
if (cursor<0) throw out_of_range("Iterator cannot move before begin!") ;
Iterator temp=*this;
--cursor;
return *this;
}







// ----------------- SinglyLinkedList Implementation -----------------
template <class T>
SinglyLinkedList<T>::SinglyLinkedList() {
    // TODO
    head=NULL;
    tail=NULL;
    count=0;
}   

template <class T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    // TODO
    clear();
}   



// TODO: implement other methods of SinglyLinkedList
template <class T>
void SinglyLinkedList<T>::add(T e) {
    Node* newNode=new Node(e);
    if (empty()) head=tail=newNode;
    else {
        tail->next=newNode;
        tail=newNode;
    }
    ++count;
}

template<class T>
void SinglyLinkedList<T>::add(int index,T e) {
if (index<0||index>count) throw out_of_range("Index is invalid!");
else if (index==count) return this->add(e);
if (index==0) {
    Node* tmp=new Node (e);
    tmp->next=this->head;
    this->head=tmp;
    this->count++;
}
else {
    Node *temp=new Node(e);
    Node *prev=this->head;
    for (int i=0; i<idx-1; ++i) prev=prev->next;
    temp->next=prev->next;
    prev->next=temp;
    this->count++;
}
}

template<class T>
T SinglyLinkedList<T>::removeAt(int index) {
if (index<0||index>=count)  throw out_of_range("Index is invalid!");

if (this->count==0) {
    T value=this->head->data;
    delete this->head;
    this->head=this->tail=NULL;
    this->count=0;
    return value;
}

if (index==0) {
    Node* temp=this->head;
    this->head=this->head->next;
    T value=temp->data;
    temp->next=NULL;
    delete temp;
    this->count--;
    return value;
}

if (index==count-1) {
    Node* prev=head;
    for (int i=0; i<idx-1;i++) prev=prev->next;
    Node* temp=prev->next;
    T value=temp->data;
    prev->next=NULL;
    this->tail=prev;
    delete temp;
    this->count--;
    return value;
}

else {
    Node*prev=head;
    for (int i=0; i<index;++i) prev=prev->next;
    Node*temp=prev->next;
    prev->next=temp->next;
    temp->next=NULL;
    T value=temp->data;
    delete temp;
    this->count--;
    return value;
}
}

template <class T>
bool SinglyLinkedList<T>::removeItem (T item) {
    if (empty()) return false;
    if (head->data==item) {
        Node* toDelete=head;
        head=head->next;
        if (head==NULL) tail=NULL;
        delete toDelete;
        --count;
        return true; 
    }
    Node *prev=head;
    Node *cur=head->next;
    while (cur) {
        if (cur->data==item) {
            prev->next=cur->next;
            if (cur==tail) tail=prev;
            delete cur;
            --count;
            return true;
        }
        prev=cur;
        cur=cur->next;
    }
    return false;
}

template <class T>
bool SinglyLinkedList<T>::empty() const {
if (count==0) return true;
else return false;
}

template <class T>
int SinglyLinkedList<T>:: size() const {
    return count;
}

template <class T> 
void SinglyLinkedList<T>:: clear() {
Node *cur=head;
while (cur) {
    Node *nextNode=cur->next;
    delete cur;
    cur=nextNode;
}
head=tail=NULL;
count=0;
}

template <class T>
T& SinglyLinkedList<T>:: get(int index) {
    if (index<0||index>=count) throw out_of_range("Index is invalid!");
    Node *cur=head; 
    for (int i=0; i<index; ++i) {
        cur=cur->next;
    }
    return cur->data;
}

template <class T> 
int SinglyLinkedList<T>:: indexOf(T item) const {
    Node * cur=head;
    int idx;
    while (cur!=nullptr) {
        if (cur->data==item) return idx;
        cur=cur->next;
        ++idx;
    }
    return -1;
}

template <class T>
bool SinglyLinkedList<T>:: contains(T item) const{
    if (indexOf(item) !=-1) return true;
    else return false;
}

template <class T>
string SinglyLinkedList<T>:: toString(string (*item2str)(T&) = 0) const {
    stringstream ss;
    Node *cur=head;
    while (cur) {
        if (item2str) ss<<"[" <<item2str(cur->data)<<"]";
        else ss<<"["<<cur->data<<"]";
        if (cur->next) ss<<"->";
        cur=cur->next;
    }
    return ss.str();
}

template<class T>
typename SinglyLinkedList<T>::Iterator SinglyLinkedList<T>:: begin() {
    return Iterator(head);
}

template <class T>
typename SinglyLinkedList<T>::Iterator SinglyLinkedList<T>::end() {
    return Iterator(nullptr);
}








// ----------------- Iterator of SinglyLinkedList Implementation -----------------
template <class T>
SinglyLinkedList<T>::Iterator::Iterator(Node* node) {
    // TODO
    current=node;
}   


// TODO: implement other methods of SinglyLinkedList::Iterator
template<class T>
typename SinglyLinkedList<T>::Iterator&  SinglyLinkedList<T>::Iterator::operator=(const Iterator& other) {
if (this!=other) current=other.current;
return *this;
}

template<class T>
T& SinglyLinkedList<T>::Iterator::operator*(){
if (current==nullptr) throw out_of_range("Iterator is out of range!");
return current->data;
}

template <class T>
bool SinglyLinkedList<T>:: Iterator:: operator!=(const Iterator& other) const {
if (current!=other.current) return true;
else return false;
}

template<class T>
typename SinglyLinkedList<T>::Iterator& SinglyLinkedList<T>::Iterator::operator++() {
if (current == nullptr) throw std::out_of_range("Iterator cannot advance past end!");
current=current->next;
return *this;
}

template <class T>
typename SinglyLinkedList<T>::Iterator SinglyLinkedList<T>::Iterator:: operator++(int){
if (current == nullptr) throw std::out_of_range("Iterator cannot advance past end!");
Iterator temp=*this;
++(*this);
return temp;
}








// ----------------- VectorStore Implementation -----------------

VectorStore::VectorStore(int dimension = 512, EmbedFn embeddingFunction = nullptr) {
    // TODO
}

VectorStore::~VectorStore() {
    // TODO
}

// TODO: implement other methods of VectorStore


// Explicit template instantiation for char, string, int, double, float, and Point

template class ArrayList<char>;
template class ArrayList<string>;
template class ArrayList<int>;
template class ArrayList<double>;
template class ArrayList<float>;
template class ArrayList<Point>;

template class SinglyLinkedList<char>;
template class SinglyLinkedList<string>;
template class SinglyLinkedList<int>;
template class SinglyLinkedList<double>;
template class SinglyLinkedList<float>;
template class SinglyLinkedList<Point>;
