#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlist.h"

static Node* _head = NULL;
static Node* _tail = NULL;
static Node* _cur_node = NULL;

bool empty(){
   return _head == NULL;
}

size_t size() {
    size_t count = 0;
    Node* current = _head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void print(){
    
}

void print_file(FILE* stream){
    
}

void clear(){
    Node* current = _head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp->data);
        free(temp);
    }
    _head = _tail = _cur_node = NULL;
}

Node* append_left(size_t n, char new_data[]){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = (char*)malloc(n * sizeof(char));
    strcpy(new_node->data, new_data);
    new_node->next = _head;
    new_node->prev = NULL;
    if (_head != NULL) {
        _head->prev = new_node;
    }
    _head = new_node;
    if (_tail == NULL) {
        _tail = new_node;
    }
    return new_node;
}

Node* append(size_t n, char new_data[]){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = (char*)malloc(n * sizeof(char));
    strcpy(new_node->data, new_data);
    new_node->next = NULL;
    new_node->prev = _tail;
    if (_tail != NULL) {
        _tail->prev = new_node;
    }
    _tail = new_node;
    if (_head == NULL) {
        _head = new_node;
    }
    return new_node;
}

Node* insert_after(Node* cur_node, Node* new_node){
    return NULL;
}

Node* pop_left(){
    if (_head == NULL) return NULL;
    Node* temp = _head;
    _head = _head->next;

    if (_head != NULL) {
        _head->prev = NULL;
    } else {
        _tail = NULL;
    }
    return temp;
}

Node* pop(){
    if (_tail == NULL) return NULL;
    Node* temp = _tail;
    _tail = _tail->next;

    if (_tail != NULL) {
        _tail->prev = NULL;
    } else {
        _head = NULL;
    }
    return temp;
}

Node* delete_node(Node* cur_node){
    if (cur_node == NULL) return NULL;
    if (cur_node->prev != NULL) {
        cur_node->prev->next = cur_node->next;
    } else {
        _head = cur_node -> next;
    }

    if (cur_node->next != NULL) {
        cur_node->next->prev = cur_node->prev;
    } else {
        _tail = cur_node->prev;
    }
}

Node* delete_by_data(char* data){
    Node* current = _head;
    while (current != NULL) {
        if (strcmp(current->data, data) == 0) {
            return delete_node(current);
        }
        current = current->next;
    }
}

Node* next(){
    if (_cur_node != NULL) {
        _cur_node = _cur_node->next;
    }
    return _cur_node;
}

Node* prev(){
    if (_cur_node != NULL) {
        _cur_node = _cur_node->prev;
    }
    return _cur_node;
}

Node* first_node(){
    _cur_node = _head;
    return _cur_node;
}

Node* last_node(){
    _cur_node = _tail;
    return _cur_node;
}

Node* get_node(size_t index){
    Node* _cur_node = _head;

    for (size_t i=0; i<index; i++) {
        _cur_node = _cur_node->next;
    }
    return _cur_node;
}

