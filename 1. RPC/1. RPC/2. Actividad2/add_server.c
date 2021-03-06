/*
 * Esta clase se encarga del servidor. 
 * 
 */

#include "add.h"
#include "time.h"
#include "stdlib.h"

/*
*Esta funcion obtiene la fecha del sistema y obtiene el parametro nombre
*que ocupara para guardarlo en un archivo llamado
*datos.txt
*regresa nada.
*/
char **
add_1_svc(char **argp, struct svc_req *rqstp)
{ 
	static char * result;

time_t t = time(NULL);
struct tm tm = *localtime(&t);

result = "Done";

FILE *f = fopen("datos.txt", "a+");
if (f == NULL)
{
    printf("Error opening file!\n");
    exit(1);
}

fprintf(f,  "%s %d %d %d:%d:%d %d\n", *argp, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, tm.tm_year + 1900);

fclose(f);

printf("Server added, %s %d %d %d:%d:%d %d\n", *argp, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, tm.tm_year + 1900);
	

	return &result;
}

/*
*Esta funcion realiza una busqueda en el archivo y va aumentando 
*un contador. Regresa la cadena completa.
*/
char **
search_1_svc(char **argp, struct svc_req *rqstp)
{

	static char * result;
	char string_file[300];
char *num;
int x = 0;

FILE *f = fopen("datos.txt", "r");
char* nombre = *argp;
/*fscanf(f,"%s",string_file);
printf("archivo: \n%s", string_file);*/



while(!feof(f))//this loop searches the for the current word
{
    fscanf(f,"%s",string_file);
    if(strstr(string_file, nombre))//if match found increment num
    x++;
}

result = "Se encontro la palabra %s %d veces\n",nombre ,x;
printf("Se encontro la palabra %s %d veces\n",nombre ,x );
	/*
	 * insert server code here
	 */


	return &result;
}
