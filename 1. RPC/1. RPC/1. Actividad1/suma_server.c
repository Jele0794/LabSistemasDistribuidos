/*
 * Este archivo es del servidor y es el que realiza el proceso de los   
 * datos
 */

#include "suma.h"

int *
suma_1_svc(intpair *argp, struct svc_req *rqstp)
{
	static int  result;


	printf("Server is working \n");
	printf("parameters: %d, %d\n", argp->a, argp->b);
	result = argp->a + argp->b;
	printf("returning: %d\n", result);

	return &result;
}
