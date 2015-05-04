#include "dt.h"
#include <stdlib.h>

struct dt * dt_init( int initial_size ) {
// tworzy tab. dyn.
    int i;
    char tab[35];
	struct dt * ns = malloc( sizeof *ns );
	if( ns == NULL )
			return NULL;
	ns->t = malloc( initial_size * sizeof * ns->t );
	if( ns->t == NULL ) {
			free( ns );
			return NULL;
	}

	for (i=0;i<initial_size; i++){
        ns->t[i] = tab;
	}

	ns->size = initial_size;
	ns->n = 0;
	return ns;
}

struct dt * dt_resize( struct dt *t ) {
// powiêksza dwukrotnie tablice
	int a;
	int i;
	char temp[35];
	char** np = realloc( t->t, 2*t->size*sizeof *t->t );
	if( np == NULL )
		return NULL;
	a = t->size;
	t->size *= 2;
/*	for (i=a;i<t->size;i++){
		t->t[i] = temp;
		}*/
	t->t = np;
	return t;
}

void dt_add( struct dt * sp, char* x ) {
// dodaje do t jeden element
	if( sp->size <= sp->n )
		if( dt_resize( sp ) == NULL )
			return;
		sp->t[sp->n] = x;
		sp->n++;
		return;
}

void dt_print( struct dt *t, FILE *out ){
	// wypisuje t do out
	int i;
	fprintf( out, "[ " );
	for( i= 0; i < t->n; i++ )
		fprintf( out, "%s ", t->t[i] );
	fprintf( out, "] (%d)\n", t->size );
}
