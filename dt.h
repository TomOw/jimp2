#ifndef _DT_H_
#define _DT_H_

#include <stdio.h>

struct dt {
	char **t;   // tablica wartoœci
	int size;    // jej aktualna wielkoœæ
	int n;       // liczba elementów ( <= size )
};

struct dt * dt_init( int initial_size ); // tworzy tab. dyn.

void dt_add( struct dt * t,  char *x );  // dodaje do t jeden element

void dt_print( struct dt *t, FILE *out ); // wypisuje t do out

#endif
