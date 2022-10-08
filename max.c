#include <stdio.h>
#include <assert.h>

int max(int* numbers, int size)
{
    // assert, hvis vores size er > 0, der opfylder vores pre.
    assert(size > 0);

    // laver en variabel max, der afgører hvilken værdi der er max.
    // til at starte med sætter vi den til den første værdi i rækken.
    int max = numbers[0];

    // laver et for-loop, hvor vi starter i = 0 indtil vi går hele rækken igennem.
    for(int i = 0; i < size; i++)
    {
        // if-statement:
        // hvis værdien i rækken af større den den nuværende maksimum værdi,
        // er værdien det nye maksimum.
        if(numbers[i] > max)
        {
        max = numbers[i];
        }
    }
    
    // returner vores varibel max, der har den største værdi i rækken.
    return max;
}


