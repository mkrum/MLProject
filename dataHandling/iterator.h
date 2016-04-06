//iterator class, you guys are welcome
//Michael Krumdick

#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"

class iterator : public std::iterator<std::forward_iterator_tag, node*> {

    node *itr;

    public: 
        iterator(node* head) : itr(head) {};
        iterator(const iterator& copy) : itr(copy.itr) {};
        iterator& operator++() {itr = itr->next(); return *this; };
        bool operator==(const iterator& rhs) { return itr == rhs.itr; };
        bool operator!=(const iterator& rhs) { return itr != rhs.itr; };
        node& operator*() {
            return *itr;
        }
};

#endif

        
