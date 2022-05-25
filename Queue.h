#ifndef QUEUE_H
#define QUEUE_H


#include <iostream>


/**This is a generic class for handling a queue of cards or players, in the game: **/
template<class T>
class Queue
{
public:
    Queue();
    Queue(const Queue<T>& other);
    Queue& operator=(const Queue<T>& other);
    ~Queue();
    class Iterator;
    class ConstIterator;
    Iterator begin();
    Iterator end();
    ConstIterator begin() const;
    ConstIterator end()const;
    void pushBack(T element);
    T& front();
    void popfront();
    int size();
    class EmptyQueue{};
private:
    class Element_Node
    {
    public:
        Element_Node();
        explicit Element_Node(const T element);
        Element_Node(const Element_Node& other);
        Element_Node& operator=(const  Element_Node& other);
        /**This is the destructor of the element node: **/
        ~Element_Node() = default;
        T& getElement();
        Element_Node* getNext();
        void setNext(Element_Node* other);
    private:
        T m_element;
        Element_Node* m_next;
    };
    void queueCreate(Queue<T>& other);
    void queueDelete();
    Element_Node *m_queueHead;
    int m_queueSize;
};


/**These are the functions for handling the Element Node class: **/

/**This is the default constructor if the class: **/
template<class T>
Queue<T>::Element_Node::Element_Node(): m_element(0), m_next(NULL)
{}
/**This is the constructor if the element node: **/
template<class T>
Queue<T>::Element_Node::Element_Node(const T element)
{
    Element_Node* new_node = new Element_Node;
    new_node->m_element = element;
    new_node->m_next = NULL;
}

/**This is the copy constructor of the element node: **/
template<class T>
Queue<T>::Element_Node::Element_Node(const Element_Node& other)
{
    Element_Node* new_node = new Element_Node;
    new_node->m_element = other.m_element;
    new_node->m_next = NULL;
}



/**This is the assignment operator of the element node class: **/
template<class T>
typename Queue<T>::Element_Node& Queue<T>::Element_Node::operator=(const Queue::Element_Node &other)
{
    if(this == &other)
    {
        return *this;
    }
    this->m_element = other.m_element;
    return *this;
}

/**This is a function for getting the element of the node: **/
template<class T>
T& Queue<T>::Element_Node::getElement()
{
    return m_element;
}

template<class T>
typename Queue<T>::Element_Node* Queue<T>::Element_Node::getNext()
{
    return m_next;

}
template<class T>
void Queue<T>::Element_Node::setNext(Element_Node* other)
{
    this->m_next = other;
}
/**These are the functions to handle the queue class: **/

/**This is the constructor of the queue: **/
template<class T>
Queue<T>::Queue() : m_queueHead(NULL), m_queueSize(0)
{}

/**This is the copy constructor of the queue: **/
template<class T>
Queue<T>::Queue(const Queue<T> &other): m_queueHead(NULL), m_queueSize(other.m_queueSize)
{
    if(other.m_queueSize != 0)
    {
        queueCreate(other);
    }
}

/**This is the assignment operator of the queue: **/
template<class T>
Queue<T>& Queue<T>::operator=(const Queue<T> &other)
{
    if (this == &other)
    {
        return *this;
    }
    m_queueSize = other.m_queueSize;
    this->queueDelete();
    queueCreate(other);
}


/**Ths is the destructor of the queue: **/
template<class T>
Queue<T>::~Queue()
{
    this->queueDelete();
}


/**This is a function for getting the first element in the queue: **/
template<class T>
typename Queue<T>::Iterator Queue<T>:: begin()
{
    return Iterator(this->m_queueHead);
}


/**This is a function for getting the past to last element in the queue: **/
template<class T>
typename Queue<T>::Iterator Queue<T>:: end()
{
    return nullptr;
}


/**This is a function for getting the first element in the queue,ensuring not to change it (const): **/
template<class T>
typename Queue<T>::ConstIterator Queue<T>:: begin() const
{
    return ConstIterator(this->m_queueHead);
}


/**This is a function for getting the end of the queue, ensuring not to change it (const): **/
template<class T>
typename Queue<T>::ConstIterator Queue<T>:: end() const
{
    return nullptr;
}



typedef bool filterFunctionPtr(int);

template<class T>
Queue <T> filter(const Queue<T>& queue,filterFunctionPtr p)
{
    Queue<T> filtered;
    for(typename Queue<T>::ConstIterator it = queue.begin(); it != queue.end();++it)
    {
        if(p(*it))
        {
            filtered.pushBack(*it);
        }
    }
    return filtered;
}









/**This is a function for appending an element to the queue: **/
template<class T>
void Queue<T> :: pushBack(T element)
{
    Element_Node *new_node = new Element_Node(element);
    /**If this is the first element to be added to the queue: **/
    if(!m_queueHead)
    {
        m_queueHead = new_node;
        return;
    }
    Element_Node *current = m_queueHead;
    while(current->getNext() != NULL)
    {
        current = current->getNext();
    }
    /**now the current points to the last node in the queue: **/
     current->setNext(new_node);
     ++m_queueSize;
}




template<class T>
class Queue<T>::Iterator
{
public:
    const T& operator*() const;
    T& operator*();
    Iterator& operator++();
    bool operator!=(const Iterator& iterator) const;
    Iterator(const Iterator&) = default;
    Iterator& operator=(const Iterator&) = default;
private:
   // const Queue<T> *m_queue;
    Element_Node *m_currentNode;
    explicit Iterator(Element_Node* current);
    friend class Queue<T>;
};

template <class T>
T&  Queue<T>::Iterator::operator*()
{
    return this->m_currentNode->m_element;
}



template<class T>
typename Queue<T>::Iterator& Queue<T>::Iterator::operator++()
{
    this->m_currentNode = this->m_currentNode->m_next;
    return *this;
}

template<class T>
bool Queue<T>::Iterator::operator!=(const Queue<T>::Iterator &iterator) const
{
    if(this == &iterator)
    {
        return false;
    }
    return true;
}





template<class T>
class Queue<T>::ConstIterator
{
public:
    const T& operator*() const;
    ConstIterator& operator++();
    bool operator!=(const ConstIterator& iterator) const;
    ConstIterator(const ConstIterator&) = default;
    ConstIterator& operator=(const ConstIterator&) = default;
private:
    const Element_Node *m_currentNode;
    explicit ConstIterator(Element_Node* current);
    friend class Queue<T>;
};

template<class T>
Queue<T>::ConstIterator::ConstIterator(Element_Node* current):m_currentNode(current)
{}
template<class T>
const T& Queue<T>::ConstIterator::operator*() const
{
    return this->m_currentNode->m_element;
}

template<class T>
typename Queue<T>::ConstIterator& Queue<T>::ConstIterator::operator++()
{
    this->m_currentNode = this->m_currentNode->m_next;
    return *this;
}

template<class T>
bool Queue<T>::ConstIterator::operator!=(const Queue<T>::ConstIterator &iterator) const
{
    if(this == &iterator)
    {
        return false;
    }
    return true;
}



template<class T>
T &Queue<T>::front()
{
    return m_queueHead->getElement();
}

template<class T>
void Queue<T>::popfront()
{
    if(m_queueSize == 0)
    {
        throw EmptyQueue();
    }
    Element_Node to_pop =m_queueHead;
    m_queueHead= m_queueHead->m_next;
    delete(to_pop);
    --m_queueSize;
}

template<class T>
int Queue<T>::size() {
    return m_queueSize;
}




template<class T>
Queue<T>::Iterator::Iterator(Element_Node* current):m_currentNode(current)
{}

/**This is a function to create a queue: **/
template<class T>
void Queue<T>::queueCreate(Queue<T>& other)
{
    this->m_queueHead = new Element_Node;
    *(this->m_queueHead) = *(other.m_queueHead);
    Element_Node *pose = this->m_queueHead;
    Element_Node *other_pose = other->m_queueHead;
    while(other_pose != NULL)
    {
        pose->m_next = new Element_Node;
        *(pose->m_next) = *(other_pose->m_next);
        other_pose = other_pose->m_next;
        pose = pose->m_next;
    }

}
template<class T>
void Queue<T>:: queueDelete()
{
    Element_Node* current = m_queueHead;
    Element_Node* next = m_queueHead;
    while(next != NULL)
    {
        next = current->getNext();
        delete(current);
        current = next;
    }
}
#endif //QUEUE_H
