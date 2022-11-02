//
// Created by jplop on 31/10/2022.
//

#include "Set.h"
#define INITIAL_SIZE 10

struct set
{
    void **elements;
    int current_count;
    int size;
    int (*equal)(void *a, void *b);
};


Set* set_new(int (*equals)(void* a, void* b))
{
    Set *new_set = malloc(sizeof(Set));
    new_set->current_count = 0;
    new_set->size = INITIAL_SIZE;
    //new_set->elements = malloc(sizeof(void*) * INITIAL_SIZE);
    new_set->elements = calloc(INITIAL_SIZE, sizeof(void*));

    new_set->equal = equals;
    return new_set;
}

int set_contains(Set *s, void *element)
{
    for(int i = 0; i < s->size; i++)
    {
        if(s->elements[i] == NULL)
            continue;
        if(s->equal(s->elements[i], element))
            return 1;
    }
    return 0;
}

Set* set_add(Set *s, void *element)
{
    if(set_contains(s, element))
        return s;
    if(s->current_count < s->size)
    {
        for (int i = 0; i < s->size; ++i)
        {
            if(s->elements[i] == NULL)
            {
                s->elements[i] = element;
                s->current_count++;
                return s;
            }
        }
    }else
    {
        s->size += 10;
        s->elements = realloc(s->elements, sizeof (void *) * s->size);
        for (int i = s->current_count; i < s->size; ++i)
        {
            s->elements[i] = NULL;
        }
        s->elements[s->current_count] = element;
        s->current_count++;
        return s;
    }
    return s;
}

Set* set_remove(Set *s, void *element)
{
    if(!set_contains(s, element))
        return s;
    else
    {
        for (int i = 0; i < s->size; ++i)
        {
            if(s->equal(s->elements[i], element))
            {
                s->elements[i] = NULL;
                s->current_count--;
                return s;
            }
        }
    }
    return s;
}
