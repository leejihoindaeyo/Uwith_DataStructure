#include <stdio.h>

#define MAX_SIZE 100000
#define QUEUE 0

int main(void)
{
    int qs_size;
    scanf("%d", &qs_size);

    int qs_types[MAX_SIZE];
    int qs_elements[MAX_SIZE];

    for (int i = 0; i < qs_size; i++)
    {
        scanf("%d", &qs_types[i]);
    }
    for (int i = 0; i < qs_size; i++)
    {
        scanf("%d", &qs_elements[i]);
    }

    int insert_count;
    scanf("%d", &insert_count);

    for (int i = qs_size - 1; insert_count != 0 && i >= 0; i--)
    {
        if (qs_types[i] == QUEUE)
        {
            printf("%d ", qs_elements[i]);
            insert_count--;
        }
    }

    for (; insert_count != 0; insert_count--)
    {
        int append_element;
        scanf("%d", &append_element);
        printf("%d ", append_element);
    }
}