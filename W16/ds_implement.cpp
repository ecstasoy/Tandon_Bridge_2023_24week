#include <algorithm>


/*Vector implementation*/


template <typename Object>
class Vector
{
        int theSize;
        int theCapacity;
        Object* objects;
    public:
        explicit Vector(int iniSize = 0);
        Vector(const Vector& rhs);
        Vector& operator=(const Vector& rhs);
        ~Vector() {delete [] objects; }
        Vector(Vector&& rhs);
        Vector& operator=(Vector&& rhs);

        void resize(int newSize);
        void reserve(int newCapacity);

        Object& operator[](int index) {return objects[index]; }
        const Object& operator[](int index) const {return objects[index]; }

        bool empty() const {return theSize == 0; }
        int size() const {return theSize; }
        int capacity() const {return theCapacity; }

        void push_back(const Object& x);
        void push_back(Object&& x);
        void pop_back() {--theSize; }
        const Object& back() const {return objects[theSize - 1]; }

        typedef Object* iterator;
        typedef const Object* const_iterator;

        iterator begin() {return &objects[0]; }
        const_iterator begin() const {return &objects[0]; }
        iterator end() {return &objects[size()]; }
        const_iterator end() const {return &objects[size()]; }

        static const int SPARE_CAPACITY = 16;

};

template <typename Object>
Vector<Object>::Vector(int initSize) : theSize{initSize}, theCapacity{initSize + SPARE_CAPACITY}
{objects = new Object[theCapacity]; }

template <typename Object>
Vector<Object>::Vector(const Vector& rhs) : theSize{rhs.theSize}, theCapacity{rhs.theCapacity}, objects{nullptr} {
    objects = new Object[theCapacity];
    for(int k = 0; k < theSize; ++k) 
        objects[k] = rhs.objects[k];
}

template <typename Object>
Vector<Object>& Vector<Object>::operator=(const Vector& rhs) {
    Vector copy = rhs;
    std::swap(*this, copy);
    return *this;
}

template <typename Object>
Vector<Object>::Vector(Vector&& rhs) : theSize{rhs.theSize}, theCapacity{rhs.theCapacity}, objects{rhs.objects} {
    rhs.objects = nullptr;
    rhs.theSize = 0;
    rhs.theCapacity = 0;
}

template <typename Object>
Vector<Object>& Vector<Object>::operator=(Vector&& rhs) {
    std::swap(theSize, rhs.theSize);
    std::swap(theCapacity, rhs.theCapacity);
    std::swap(objects, rhs.objects);

    return *this;
}

template <typename Object>
void Vector<Object>::resize(int newSize) {
    if(newSize > theCapacity) reserve(newSize * 2);
    theSize = newSize;
}

template <typename Object>
void Vector<Object>::reserve(int newCapacity) {
    if(newCapacity < theSize) return;

    Object* newArray = new Object[newCapacity];
    for(int k = 0; k < theSize; ++k) 
        newArray[k] = std::move(objects[k]);

    theCapacity = newCapacity;
    std::swap(objects, newArray);
    delete[] newArray;
}

template <typename Object>
void Vector<Object>::push_back(const Object& x) {
    if(theSize == theCapacity) reserve(2 * theCapacity + 1);
    objects[theSize++] = x;
}

template <typename Object>
void Vector<Object>::push_back(Object&& x) {
    if(theSize == theCapacity) reserve(2 * theCapacity + 1);
    objects[theSize++] = std::move(x);
}


/*List implementation*/


template <typename Object>
class List {
        struct Node {
            Object data;
            Node* prev;
            Node* next;

            Node(const Object& d = Object{}, Node* p = nullptr, Node* n = nullptr) 
            : data{d}, prev{p}, next{n} {};

            Node(Object&& d, Node* p = nullptr, Node* n = nullptr)
            : data{std::move(d)}, prev{p}, next{n} {};
        };
        int theSize;
        Node* head;
        Node* tail;

        void init();

    public:
        class const_iterator;
        class iterator;

        List() {init(); }
        List(const List& rhs);
        ~List();
        List& operator=(const List& rhs);
        List(List&& rhs);
        List& operator=(List&& rhs);

        iterator begin() {return {head->next}; }
        const_iterator begin() const {return {head->next}; }
        iterator end() {return {tail}; }
        const_iterator end() const {return {tail}; }

        int size() const {return theSize; }
        bool empty() const {return size() == 0; }
        
        void clear() {while(!empty()) pop_front(); }

        Object& front() {return *begin(); }
        const Object& front() const {return *begin(); }
        Object& back() {return *--end(); }
        const Object& back() const {return *--end(); }
        void push_front(const Object& x) {insert(begin(), x); }
        void push_front(Object&& x) {insert(begin(), std::move(x)); }
        void push_back(const Object& x) {insert(end(), x); }
        void push_back(Object&& x) {int ert(end(), std::move(x)); }
        void pop_front() {erase(begin()); }
        void pop_back() {erase(--end()); }

        iterator insert(iterator itr, const Object& x);
        iterator insert(iterator itr, Object&& x);

        iterator erase(iterator itr);
        iterator erase(iterator from, iterator to);
};

template <typename Object>
class List<Object>::const_iterator {
    protected:
        Node* current;

        Object& retrieve() const {return current->data; }
        const_iterator(Node* p) : current(p) {}

        friend class List<Object>;
    public:
        const_iterator() : current{nullptr} {}

        const Object& operator*() const {return retrieve(); }
        const_iterator& operator++();
        const_iterator operator++(int);
        const_iterator& operator--();
        const_iterator operator--(int);
        bool operator==(const const_iterator& rhs) {return current == rhs.current; }
        bool operator!=(const const_iterator& rhs) {return !(*this == rhs); }
};

template <typename Object>
typename List<Object>::const_iterator& List<Object>::const_iterator::operator++() {
    current = current->next;
    return *this;
}

template <typename Object>
typename List<Object>::const_iterator List<Object>::const_iterator::operator++(int) {
    const_iterator old = *this;
    ++(*this);
    return old;
}

template <typename Object>
typename List<Object>::const_iterator& List<Object>::const_iterator::operator--() {
    current = current->prev;
    return *this;
}

template <typename Object>
typename List<Object>::const_iterator List<Object>::const_iterator::operator--(int) {
    const_iterator old = *this;
    --(*this);
    return old;
}

template <typename Object>
class List<Object>::iterator : public List<Object>::const_iterator {
    protected:
        iterator(Node* p) : const_iterator(p) {}

        friend class List<Object>;

    public:
        iterator() {}

        Object& operator*() {return const_iterator::retrieve(); }
        const Object& operator*() const {return const_iterator::operator*(); }

        iterator& operator++();
        iterator operator++(int);
        iterator& operator--();
        iterator operator--(int);
};

template <typename Object>
typename List<Object>::iterator& List<Object>::iterator::operator++() {
    this->current = this->current->next;
    return *this;
}

template <typename Object>
typename List<Object>::iterator List<Object>::iterator::operator++(int) {
    iterator old = *this;
    ++(*this);
    return old;
}

template <typename Object>
typename List<Object>::iterator& List<Object>::iterator::operator--() {
    this->current = this->current->prev;
    return *this;
}

template <typename Object>
typename List<Object>::iterator List<Object>::iterator::operator--(int) {
    iterator old = *this;
    --(*this);
    return old;
}

template <typename Object>
void List<Object>::init() {
    theSize = 0;
    head = new Node;
    tail = new Node;
    head->next = tail;
    tail->prev = head;
}

template <typename Object>
List<Object>::~List() {
    clear();
    delete head;
    delete tail;
}

template <typename Object>
List<Object>::List(const List& rhs) {
    init();
    for(auto& x : rhs) push_back(x);
}

template <typename Object>
List<Object>& List<Object>::operator=(const List& rhs) {
    List copy = rhs;
    std::swap(*this, copy);
    return *this;
}

template <typename Object>
List<Object>::List(List&& rhs) : theSize{rhs.theSize}, head{rhs.head}, tail{rhs.tail} {
    rhs.theSize = 0;
    rhs.head = nullptr;
    rhs.tail = nullptr;
}

template <typename Object>
List<Object>& List<Object>::operator=(List&& rhs) {
    std::swap(theSize, rhs.theSize);
    std::swap(head, rhs.head);
    std::swap(tail, rhs.tail);

    return *this;
}

template <typename Object>
typename List<Object>::iterator List<Object>::insert(iterator itr, const Object& x) {
    Node* p = itr.current;
    ++theSize;
    return {p->prev = p->prev->next = new Node{x, p->prev, p}};
}

template <typename Object>
typename List<Object>::iterator List<Object>::insert(iterator itr, Object&& x) {
    Node* p = itr.current;
    ++theSize;
    return {p->prev = p->prev->next = new Node{std::move(x), p->prev, p}};
}

template <typename Object>
typename List<Object>::iterator List<Object>::erase(iterator itr) {
    Node* p = itr.current;
    iterator retVal{p->next};
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
    --theSize;

    return retVal;
}

template <typename Object>
typename List<Object>::iterator List<Object>::erase(iterator from, iterator to) {
    for(iterator itr = from; itr != to; ) itr = erase(itr);

    return to;
}

