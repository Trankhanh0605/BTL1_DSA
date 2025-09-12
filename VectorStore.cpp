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





// ----------------- Iterator of ArrayList Implementation -----------------
template <class T>
ArrayList<T>::Iterator::Iterator(ArrayList<T>* pList, int index) {
    // TODO
}

// TODO: implement other methods of ArrayList::Iterator








// ----------------- SinglyLinkedList Implementation -----------------
template <class T>
SinglyLinkedList<T>::SinglyLinkedList() {
    // TODO
}   

template <class T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    // TODO
}   

// TODO: implement other methods of SinglyLinkedList



// ----------------- Iterator of SinglyLinkedList Implementation -----------------
template <class T>
SinglyLinkedList<T>::Iterator::Iterator(Node* node) {
    // TODO
}   

// TODO: implement other methods of SinglyLinkedList::Iterator



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
