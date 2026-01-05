#include <stdio.h>
#include <stdio.h> 
  
int main() 
{ 
    int i; 
  
    // Direct initialization of 2-D char array 
    char array[][20] = { "", "", "","", "", "" }; 
    for (i = 0; i < 4; i++)
    {
        printf("ingreso: ");
        scanf("%s",array[i]);
    }
    
    // print the words 
    for (i = 0; i < 4; i++) 
        printf("%s\n", array[i]); 
  
    return 0; 
} 