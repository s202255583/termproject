#ifndef LINKEDLIST_NODE_H
#define LINKEDLIST_NODE_H

#ifdef __cplusplus
extern "C" {
#endif

struct Node {
    char* data;
    struct Node* prev;
    struct Node* next;
};
typedef struct Node Node;

#ifdef __cplusplus
}
#endif

#endif //LINKEDLIST_NODE_H
