#ifndef _STACK_H
#define _STACK_H
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct node_s
{
    int len;
    void *val;
    struct node_s *next;
} node_t;

typedef struct
{
    size_t size;
    node_t *head;
} m_stack_t;

// make the node_t type node
static node_t *make(void *_val, size_t _len);

// create a stack if _stack is null malloced else initialized by input
m_stack_t *stack(m_stack_t *_stack);

// judge the stack is empty, if empty return true else return false
bool isempty_stack(m_stack_t *_stack);

// push _val to stack, _len is sizeof(*_val)
bool push_stack(m_stack_t *_stack, void *_val, size_t _len);

// pop the head of stack
void pop_stack(m_stack_t *_stack);

// pop the head of stack, return by (*_val)
bool top_stack(m_stack_t *_stack, void *_val);

// free the memory allocated
void free_stack(m_stack_t *_stack);

#endif //_STACK_H