#include<stdio.h>

int main(){
	void *p;
	int a=5, b=2, *q;
	p=&a;
	q = (int*)p;
	b=*q;
	printf("%d", b);
	return 0;
}

