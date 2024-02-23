#include "queue.h"
#include <stdio.h>
#include <time.h>

typedef struct
{
    int id;
    char *buf;
} aa;

// run as :
// gcc queue.c -o queue -g
// valgrind -s --leak-check=full ./queue

// run as:
// gcc queue.c -o queue -g -fsanitize=address
//./queue

int main()
{
    srand(time(NULL));
    m_queue_t *que = queue(NULL);
    for (int i = 0; i < 10000000; i++)
    {
        int t = rand() % 2;
        if (t == 0)
        {
            aa temp;
            temp.buf = (char *)(malloc(sizeof(char) * 100));
            strcpy(temp.buf, "1");
            temp.id = i;
            printf("分配:%d %p\n", temp.id, temp.buf);
            push_queue(que, &temp, sizeof(aa));
        }
        else
        {
            aa tttt;
            bool ok = front_queue(que, &tttt);
            if (ok)
                printf("释放:%d %p\n", tttt.id, tttt.buf);
            pop_queue(que);
            if (ok)
                free(tttt.buf);
        }
    }
    while (!isempty_queue(que))
    {
        aa tttt;
        bool ok = front_queue(que, &tttt);
        printf("释放:%d %p\n", tttt.id, tttt.buf);
        pop_queue(que);
        if (ok)
            free(tttt.buf);
    }
    free_queue(que);
    return 0;
}