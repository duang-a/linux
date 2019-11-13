#include "my.h"

static void callback1()
{
	printf("--------callback1---------\n");
}
static void callback2()
{
	printf("--------callback2---------\n");
}
static void __attribute__((constructor)) before_main(void)
{
	printf("--------before main----------\n");
}
static void __attribute__((destructor)) after_main(void)
{
	printf("--------after main----------\n");
}

int main(void)
{
	atexit(callback1);
	atexit(callback2);
	FILE *fp;
	char buf[]={"fputs use full buffer!"};
	if((fp=fopen("test.dat","w+")) == NULL)
	{
		perror("failed to open!\n");
		return -1;
	}
	if(fputs(buf, fp) == EOF)
	{
		perror("failed to fputs!\n");
		return -1;
	}
	printf("-------running in main!--------\n");
	printf("printf use line buffer");
	exit(0);
	//_exit(0);
	//return 0;
}

