#include <stdio.h>
#include <cs50.h>
int main()
{
    char username[100];

    printf("Enter your name : ");
    scanf("%s", username);

    printf("Hello, %s!\n", username);

    return 0;
}