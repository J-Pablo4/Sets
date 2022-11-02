//
// Created by jplop on 31/10/2022.
//

#ifndef CONJUNTOS_SET_H
#define CONJUNTOS_SET_H

#include <stdlib.h>
#include <stdio.h>

typedef struct set Set;

// Inicializa un nuevo SET
Set* set_new(int (*equals)(void* a, void* b));

// Regresa un apuntador al set si se agregó el elemento
// NULL si no fue posible agregarlo
Set* set_add(Set *s, void *element);

// Regresa un apuntador al set si se eliminó el elemento
// NULL si no fue posible eliminarlo
Set* set_remove(Set *s, void *element);

int set_contains(Set *s, void *element);

void* set_print(Set *s);

#endif //CONJUNTOS_SET_H
