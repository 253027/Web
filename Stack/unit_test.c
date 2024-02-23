#include "stack.h"
#include <stdio.h>
#include <time.h>

typedef struct
{
    int id;
    char buf[120];
} a;

// run as :
// gcc queue.c -o queue -g
// valgrind -s --leak-check=full ./queue

// run as:
// gcc queue.c -o queue -g -fsanitize=address
//./queue

int main()
{
    srand(time(NULL));
    m_stack_t *st = stack(NULL);
    int t1 = 0, t2 = 0;
    for (int i = 0; i < 10000000; i++)
    {
        int t = rand() % 2;
        if (t == 1)
        {
            a temp;
            if (top_stack(st, &temp))
                printf("pop%d %s\n", temp.id, temp.buf);
            t2++;
            pop_stack(st);
        }
        else
        {
            a temp;
            time_t t;
            time(&t);
            temp.id = i, strcpy(temp.buf, ctime(&t));
            push_stack(st, &temp, sizeof(temp));
            printf("push%d\n", temp.id);
            t1++;
        }
    }
    free_stack(st);
    printf("%d %d\n", t1, t2);
    return 0;
}