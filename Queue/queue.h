#ifndef _QUEUE_H
#define _QUEUE_H
#include <assert.h>
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
    node_t *head, *tail;
} m_queue_t;

// make the node_t type node
static node_t *make(void *_val, size_t _len);

// create queue by malloc(), if successed return the m_queue_t*, else return NULL
m_queue_t *queue(m_queue_t *que);

// return current size of the queue
size_t size_queue(m_queue_t *que);

// append the val to the queue, _val is value's address, _len is the Bytes size of values
void push_queue(m_queue_t *que, void *_val, size_t _len);

// remove the first head of queue if exist else do nothing
void pop_queue(m_queue_t *que);

// if queue is empty return true, else return false
bool isempty_queue(m_queue_t *que);

// if queue is not empty return true and the queue's head value set in _val, else return false _val set NULL
bool front_queue(m_queue_t *que, void *_val);

// if queue is not empty return true and the queue's tail value set in _val, else return false _val set NULL
bool back_queue(m_queue_t *que, void *_val);

// free the memory of queue allocated
void free_queue(m_queue_t *que);

#endif // _QUEUE_H