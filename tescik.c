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
    int i,j = 0;
    znak = getc (in);
    while (znak != EOF){
        buff[i]= znak;
        znak = getc (in);
	j++;
	i++;
        if (buff[i-1]== ' '){
	char* buff2 = malloc((i+1)*sizeof( char));
	strncpy (buff2 , buff, i);
            	dt_print(s, stdout);
		dt_add( s, buff2 );
		for (j=i;j>=0;j--)
			buff[j] = '\0';
            i=0;
        }
    }
    dt_print( s, stdout );
    return 0;

}

