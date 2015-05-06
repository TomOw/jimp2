#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dt.h"
#include <time.h>

int main(int argc, char **argv)
{
    FILE *in = fopen (argv[1], "r");
	if(in == NULL){
		printf ("in = null\n");
		return -1;
	}
   // int ileslow =  (argc<3) ? atoi(argv[2]):50;
	int ileslow=50;
	int licznik_slow = 0;
	int k=0;
	char* buff2;
    FILE *out= fopen(argv [2], "w");
	if(out == NULL){
		printf ("out = Null\n");
		return -1;
	}

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
	if(!(buff2 = malloc((i+1)*sizeof( char))))
	{
		printf("FATAL ERROR\n");
		return -1;
	}

	strncpy (buff2 , buff, i);
		dt_add (s, buff2);
		free(buff2);
		buff2 = NULL;

		for (j=i;j>=0;j--)
			buff[j] = '\0';
		
            i=0;
        }
    }
	printf("haalo ");
	printf("%d\n\n", s->n);
	srand(time(NULL));
    	int m= rand()%s->n;
	printf("%d\n",m);
	while(licznik_slow<ileslow)
	{
		fprintf(out,"%s", s->t[m]);
		licznik_slow++;
		m++;
		if(m>s->n)
			m=rand()%s->n;
	
	}	
    dt_print( s, stdout );
    return 0;

}

