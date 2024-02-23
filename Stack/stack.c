#include "stack.h"

static node_t *make(void *_val, size_t _len)
{
    node_t *temp = (node_t *)malloc(sizeof(node_t));
    temp->val = (char *)malloc(sizeof(char) * _len);
    memcpy(temp->val, _val, _len);
    temp->len = _len, temp->next = NULL;
    return temp;
}

m_stack_t *stack(m_stack_t *_stack)
{
    if (_stack == NULL)
    {
        m_stack_t *stack = (m_stack_t *)malloc(sizeof(m_stack_t));
        stack->head = NULL, stack->size = 0;
        return stack;
    }
    else
        _stack->head = NULL, _stack->size = 0;
    return _stack;
}

bool isempty_stack(m_stack_t *_stack)
{
    return _stack->size == 0;
}

bool push_stack(m_stack_t *_stack, void *_val, size_t _len)
{
    node_t *temp = make(_val, _len);
    if (!temp)
        return false;
    if (isempty_stack(_stack))
        _stack->head = temp;
    else
    {
        temp->next = _stack->head;
        _stack->head = temp;
    }
    ++_stack->size;
    return true;
}

void pop_stack(m_stack_t *_stack)
{
    if (isempty_stack(_stack))
        return;
    node_t *temp = _stack->head;
    _stack->head = _stack->head->next;
    --_stack->size;
    free(temp->val);
    free(temp);
    return;
}

bool top_stack(m_stack_t *_stack, void *_val)
{
    if (isempty_stack(_stack))
        return false;
    memcpy(_val, _stack->head->val, _stack->head->len);
    return true;
}

void free_stack(m_stack_t *_stack)
{
    while (!isempty_stack(_stack))
        pop_stack(_stack);
    free(_stack);
}