#include <stdio.h>
#include <string.h>

int main()
{
    int n=0;
    while (n!=100)
    {
        if (((n%3)==0)&&((n%5)!=0))
        {
            printf("Fizz\n");
        }else if (((n%3)!=0)&&((n%5)==0))
        {
            printf("Buzz\n");
        }else if (((n%3)==0)&&((n%5)==0))
        {
            printf("FizzBuzz\n");
        }else
        {
            printf("%d\n",n);
        } 
        n++;
    }
}