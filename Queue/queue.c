#include "queue.h"

static node_t *make(void *_val, size_t _len)
{
    node_t *temp = (node_t *)malloc(sizeof(node_t));
    temp->val = (char *)malloc(sizeof(char) * _len);
    memcpy(temp->val, _val, _len);
    temp->len = _len, temp->next = NULL;
    return temp;
}

m_queue_t *queue(m_queue_t *que)
{
    if (que == NULL)
    {
        m_queue_t *que = (m_queue_t *)malloc(sizeof(m_queue_t));
        if (!que)
            return NULL;
        assert(que != NULL);
        que->head = que->tail = NULL, que->size = 0;
        return que;
    }
    else
    {
        que->head = que->tail = NULL;
        que->size = 0;
    }
    return que;
}

size_t size_queue(m_queue_t *que)
{
    return que->size;
}

void push_queue(m_queue_t *que, void *_val, size_t _len)
{
    node_t *temp = make(_val, _len);
    assert(temp != NULL);
    if (isempty_queue(que))
        que->head = que->tail = temp;
    else
    {
        que->tail->next = temp;
        que->tail = temp;
    }
    ++que->size;
    return;
}

void pop_queue(m_queue_t *que)
{
    if (isempty_queue(que))
        return;
    node_t *temp = que->head;
    if (que->head == que->tail)
        que->head = que->tail = NULL;
    else
        que->head = que->head->next;
    free(temp->val);
    free(temp);
    --que->size;
    return;
}

bool front_queue(m_queue_t *que, void *_val)
{
    if (isempty_queue(que))
        return false;
    memcpy(_val, que->head->val, que->head->len);
    return true;
}

bool back_queue(m_queue_t *que, void *_val)
{
    if (isempty_queue(que))
        return false;
    memcpy(_val, que->tail->val, que->tail->len);
    return true;
}

bool isempty_queue(m_queue_t *que)
{
    return que->size == 0;
}

void free_queue(m_queue_t *que)
{
    while (!isempty_queue(que))
        pop_queue(que);
    free(que);
}