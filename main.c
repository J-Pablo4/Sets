
#include "Set.h"

int is_equal(void *a, void *b)
{
    return *(int*)a == *(int *)b;
}

int main() {
    Set *s = set_new(is_equal);
    int numbers[100];

    for(int i = 0; i < 100; i++)
    {
        numbers[i] = i;
        if(numbers[i] % 2 == 0)
            set_add(s, numbers+i);
    }
    int target = 54;
    if(set_contains(s, &target))
        printf("It works!\n");

    set_remove(s, &target);

    if(set_contains(s, &target))
        printf("It does NOT work!\n");


    int pop = 457;
    set_add(s, &pop);

    return 0;
}