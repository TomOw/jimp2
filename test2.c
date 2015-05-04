#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dt.h"
int main(int argc, char **argv)
{
    FILE *in = fopen (argv[1], "r");
    char znak;
    char buff[1024];
	int it;
	for (it = 0; it<=1024;it++)
		buff[it] = '\0';
    struct dt *s = dt_init(1024);
	/*struct dt *p = dt_init( 20 );
		dt_add( s, "ala" );
		dt_add( p, "kota" );
	

	dt_print( s, stdout );
	dt_print( p, stdout );
*/
    int i,j = 0;
    znak = getc (in);
    while (znak != EOF){
        buff[i]= znak;
        znak = getc (in);
	j++;
	printf("wczytalem: %c\n", znak);
	printf("it: %d\n", i);
        printf("%s\n", buff);
	i++;
        if (buff[i-1]== ' '){
	char* buff2 = malloc((i+1)*sizeof( char));
	strncpy (buff2 , buff, i);
	
	printf("im  here\n");
            	dt_print(s, stdout);
		printf("buff %s\n", buff);
		dt_add( s, buff2 );
		for (j=i;j>=0;j--)
			buff[j] = '\0';
            i=0;
//	break;
        }
    }
    dt_print( s, stdout );
    return 0;

}

