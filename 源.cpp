#include<stdio.h>
#include<string.h>
//int main()
//{
//	int a = 10;
//	int* p = &a;
//	printf("%d", sizeof(p));
//	struct book
//	{
//		char name[20];
//		int price;
//
//	};
//	struct book B1 ={ "C++",55 };
//	struct book* PB =&B1;
//	printf("%s\n", B1.name);
//	printf("%d\n", B1.price);
//	B1.price = 120;
//	strcpy(B1.name,"Python");
//	printf("%d\n", PB->name);
//	printf("%s\n", PB->price);
//	return 0;
//
//}
//交换a,b的值
void swap(int* a, int* b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;

}
//地址不变，同一个地址里面的值交换
int main()
{
	int a = 10, b = 20;
	printf("a=%d,b=%d\n", a, b);
	swap(&a, &b);
	printf("a=%d,b=%d\n", a, b);
	return 0;
}