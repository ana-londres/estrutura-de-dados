#ifndef NODE_H
#define NODE_H

struct node {
    int dado;      
    node* prox;   

    node(int val) : dado(val), prox(nullptr) {}
};

#endif // NODE_H
